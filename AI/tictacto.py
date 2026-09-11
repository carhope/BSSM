def tictacto(borad, winner):
    message = f"{turn}의 차례 1~9 입력"
    while (winner == 0):
        turn = "X"
        playerX = int(input(message))
def isWin(borad,winner):
    if borad[0]>0 and borad[]
        
def initTictac():
    tictak = [0,0,0,
              0,0,0,
              0,0,0]
    winner = 0
    return tictak,winner
tictacto(initTictac())

