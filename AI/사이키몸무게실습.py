import matplotlib.pyplot as plt
from sklearn import linear_model

reg = linear_model.LinearRegression()

x = [[174],[152],[138],[128],[186]]
y = [71,55,46,38,88]

reg.fit(x,y)

print(reg.predict([[165]]))


plt.scatter(x, y, color='black')


y_pred = reg.predict(x)

# 예측값을 파란색 굵은 직선으로 그린다. (직선의 기울기와 절편이 반영된다.)
plt.plot(x, y_pred, color='blue', linewidth=3)
plt.show()