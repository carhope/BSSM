import cv2
from ultralytics import YOLO
import serial

model = YOLO("yolov8n.pt")
camera = cv2.VideoCapture(0)
ser = serial.Serial(
	port = "/dev/cu.usbmodem11301",
	baudrate=9600,
	timeout=1
)
if not camera.isOpened():
	raise RuntimeError("웹캠을 열 수 없습니다.")

try:
	while True:
		success, frame = camera.read()
		if not success:
			break

		frame = cv2.flip(frame, 1)
		results = model(frame, verbose=False)
		person_count = 0

		for box in results[0].boxes:
			cls_id = int(box.cls[0])
			#conf = float(box.conf[0])
			#if conf > 0.4:
			if cls_id ==0:
				x1, y1, x2, y2 = map(int, box.xyxy[0])
				name = results[0].names[cls_id]
				cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
				label = f"{name}"
				confidence = float(box.conf[0])
				person_count += 1
				center = (x1+x2)/2
				break



			cv2.putText(
				frame,
				label,
				(x1, y1-10),
				cv2.FONT_HERSHEY_SIMPLEX,
				0.8,
				(0, 255, 0),
				2,
			)
		if person_count>0:
			ser.write(b"a")
			if center <200:
				ser.write(b"c")
			elif center >440:
				ser.write(b"e")
			else:
				ser.write(b"d")
		else:
			ser.write(b"b")
		cv2.imshow("YOLO Webcam (q: quit)", frame)

		if cv2.waitKey(33) & 0xFF == ord("q"):
			break
finally:
	camera.release()
	cv2.destroyAllWindows()
# 다음 시간에 들어오는 값에 따라 모터 돌리는거 하기