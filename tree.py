user = int(input('추가 강화 수치'))

class TNode:
    def __init__(self,data,left,right):
        self.data = data
        self.left = left
        self.right =right

if __name__ == '__main__':
    E = TNode(35,None,None)
    D = TNode(40,None,None)
    C = TNode(15,E,None)
    B = TNode(20, D, None)
    A = TNode(10,B,C)


    D.data +=user # n1의 왼쪾 자식노드가 n3


    print("기본검 : ",A.data)
    print("불의 검 :",A.left.data)
    print("태양의 검 :",A.left.left.data)
    print("태양의검 최종루트 공격력 합계 : ",A.data+A.left.data+A.left.left.data)


    
