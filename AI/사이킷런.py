#pip install scikit-learn #window
#pip3 install scikit-learn #mac

import matplotlib.pyplot as plt
from sklearn import linear_model

# 선형 회귀 모델을 만든다.
reg = linear_model.LinearRegression()

X = [[0], [1], [2]]     # 입력 데이터 (반드시 2차원)
y = [3, 3.5, 5.5]       # 목표값 (1차원)

reg.fit(X, y)

print(reg.coef_)         # 직선의 기울기 W
print(reg.intercept_)    # 직선의 y절편 b
print(reg.score(X, y))   # 직선이 학습 데이터에 얼마나 잘 맞는지

print(reg.predict([[5]]))

# 학습 데이터를 검은색 점으로 찍는다.
plt.scatter(X, y, color='black')

# 학습 데이터를 입력으로 하여 예측값을 계산한다.
y_pred = reg.predict(X)

# 예측값을 파란색 굵은 직선으로 그린다. (직선의 기울기와 절편이 반영된다.)
plt.plot(X, y_pred, color='blue', linewidth=3)
plt.show()