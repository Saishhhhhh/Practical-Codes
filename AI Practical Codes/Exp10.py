# Implement Alpha-Beta Tree search for any game search problem.

import math

# ---------- Check if someone has won ----------
def check_winner(board):
    winning_combinations = [
        (0,1,2), (3,4,5), (6,7,8),  # rows
        (0,3,6), (1,4,7), (2,5,8),  # columns
        (0,4,8), (2,4,6)             # diagonals
    ]
    for x, y, z in winning_combinations:
        if board[x] == board[y] == board[z] != " ":
            return board[x]   # Return 'X' or 'O'
    # If no empty spots left, it's a draw
    if " " not in board:
        return "Draw"
    return None  # Game still going

# ---------- Alpha-Beta Algorithm ----------
def alpha_beta(board, depth, is_maximizing, alpha, beta):
    winner = check_winner(board)

    # Base cases (end of recursion)
    if winner == "X":
        return 10 - depth
    if winner == "O":
        return depth - 10
    if winner == "Draw":
        return 0

    # Maximizing player (AI = X)
    if is_maximizing:
        best_value = -math.inf
        for i in range(9):
            if board[i] == " ":
                board[i] = "X"
                value = alpha_beta(board, depth + 1, False, alpha, beta)
                board[i] = " "
                best_value = max(best_value, value)
                alpha = max(alpha, best_value)
                if beta <= alpha:
                    break  # Prune branch
        return best_value

    # Minimizing player (Human = O)
    else:
        best_value = math.inf
        for i in range(9):
            if board[i] == " ":
                board[i] = "O"
                value = alpha_beta(board, depth + 1, True, alpha, beta)
                board[i] = " "
                best_value = min(best_value, value)
                beta = min(beta, best_value)
                if beta <= alpha:
                    break  # Prune branch
        return best_value

# ---------- Choose the best move for AI ----------
def best_move(board):
    best_val = -math.inf
    move = -1
    for i in range(9):
        if board[i] == " ":
            board[i] = "X"
            move_val = alpha_beta(board, 0, False, -math.inf, math.inf)
            board[i] = " "
            if move_val > best_val:
                best_val = move_val
                move = i
    return move

# ---------- Display Board ----------
def display(board):
    print()
    for i in range(0, 9, 3):
        print(" | ".join(board[i:i+3]))
        if i < 6:
            print("-" * 5)
    print()

# ---------- Main Game Loop ----------
board = [" "] * 9
print("You = O, AI = X")
print("Board positions: 0 1 2 | 3 4 5 | 6 7 8")

while not check_winner(board):
    display(board)
    move = int(input("Your move (0-8): "))

    # Validate move
    if board[move] != " ":
        print("Spot taken! Try again.")
        continue

    board[move] = "O"
    if check_winner(board):
        break

    ai_move = best_move(board)
    board[ai_move] = "X"

winner = check_winner(board)
display(board)
print("Result:", winner)

# You=O, AI=X. Positions 0-8.
# Move: 0
# ['O', ' ', ' ']
# [' ', 'X', ' ']
# [' ', ' ', ' ']

# Move: 4
# ['O', ' ', ' ']
# [' ', 'O', 'X']
# [' ', ' ', ' ']

# Move: 8
# ['O', ' ', ' ']
# [' ', 'O', 'X']
# [' ', ' ', 'O']
# Result: O

# Space Complexity  :   O(D)
# Time Complexity  : O(B^D)
# b = branching factor = number of possible moves per turn
# d = maximum depth of the game tree

# https://chatgpt.com/share/6914b447-0be0-8002-ba08-8fe0f1f3c2dd