#파이썬 큐 모듈 사용 회문
import queue as q
def display():
  queue_counts = list(s.queue)
  if not queue_counts:
    print("큐가 비어있음")
    return
  print(f"큐 내용 : {queue_counts}")

#help(q.LifoQueue)
text = 'cha hiu mang'
s=q.LifoQueue(maxsize=20)
for i in text:
  s.put(i)
  display()
while s.empty:
  print(s.get(),end = "")