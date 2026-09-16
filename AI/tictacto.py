def print_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 9)

def check_win(board, player):
    for row in board:
        if all(s == player for s in row):
            return True
    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True
    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True
    return False

def tic_tac_toe():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"
    moves = 0

    while moves < 9:
        print_board(board)
        try:
            row, col = map(int, input(f"플레이어 {current_player} (행 열 입력, 0-2): ").split())
            if board[row][col] != " ":
                print("이미 선택된 위치입니다. 다시 입력하세요.")
                continue
        except (ValueError, IndexError):
            print("올바른 범위의 숫자 두 개를 입력하세요 (예: 0 1).")
            continue

        board[row][col] = current_player
        moves += 1

        if check_win(board, current_player):
            print_board(board)
            print(f"플레이어 {current_player} 승리!")
            return

        current_player = "O" if current_player == "X" else "X"

    print_board(board)
    print("무승부입니다!")

tic_tac_toe()