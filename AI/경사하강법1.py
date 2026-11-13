import numpy as np
import matplotlib.pyplot as plt

# 학습 데이터 (점 3개)
X = np.array([0.0, 1.0, 2.0])
y = np.array([3.0, 3.5, 5.5])

# 처음에는 W와 b를 0으로 시작한다.
w = 0            # 기울기 W
b = 0            # 절편 b

lrate = 0.01     # 학습률 (한 번에 얼마나 움직일지)
epochs = 1000    # 반복 횟수

n = float(len(X))   # 데이터의 개수

# 경사하강법
for i in range(epochs):
    y_pred = w * X + b                      # 현재 직선으로 예측한 값
    dw = (2 / n) * sum(X * (y_pred - y))    # W의 기울기
    db = (2 / n) * sum(y_pred - y)          # b의 기울기
    w = w - lrate * dw                      # W 수정
    b = b - lrate * db                      # b 수정

# 학습이 끝난 W와 b를 출력한다.
print(w, b)

# 학습이 끝난 직선으로 예측값을 만든다.
y_pred = w * X + b

# 데이터를 점으로 찍는다.
plt.scatter(X, y)

# 예측값을 직선으로 그린다. (맨 왼쪽 점부터 맨 오른쪽 점까지)
plt.plot([min(X), max(X)], [min(y_pred), max(y_pred)], color='red')
plt.show()