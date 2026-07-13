class oneTwo: #클래스 함수 - 메서드 (클래스 안에있는 함수 = 메서드!!!)
  home = '지훈T'
  def __init__(self, name, score): #⭐️메서드중 init은 생성자⭐️ 안에 변수 - 필드, 속성 - class선언시 자동으로 실행 
    # 그안에 있는 변수 (self는 필드 속성이라고 함.)
    self.name = name
    self.score = score
    #self.home = home

  def get_score(self): #
    print(f'{self.name}의 합계는 {sum(self.score)}입니다')

  def get_AVG(self):
    print(f'{self.name}의 합계는 {sum(self.score)/len(self.score)}')
    print(f'{self.home} : {self.name}아 잘했어')
s1 = oneTwo('감강현',[100,100,100]) #객체
s1.get_score()
s1.get_AVG()
s2 = oneTwo('김정원',[30,20,70])
s2.get_score()
s2.get_AVG()
s3 = oneTwo('박혜리',[100,50,50])
oneTwo_list = [s1,s2,s3]
for i in oneTwo_list:
  i.get_score()
  i.get_AVG()