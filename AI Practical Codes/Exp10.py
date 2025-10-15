import math

def check_winner(b):
    wins = [(0,1,2),(3,4,5),(6,7,8),(0,3,6),(1,4,7),(2,5,8),(0,4,8),(2,4,6)]
    for x,y,z in wins:
        if b[x]==b[y]==b[z]!=" ": return b[x]
    return "Draw" if " " not in b else None

def alpha_beta(b, depth, is_max, alpha, beta):
    w = check_winner(b)
    if w=="X": return 10-depth
    if w=="O": return depth-10
    if w=="Draw": return 0
    if is_max:
        val=-math.inf
        for i in range(9):
            if b[i]==" ":
                b[i]="X"; val=max(val,alpha_beta(b,depth+1,0,alpha,beta)); b[i]=" "
                alpha=max(alpha,val)
                if beta<=alpha: break
        return val
    else:
        val=math.inf
        for i in range(9):
            if b[i]==" ":
                b[i]="O"; val=min(val,alpha_beta(b,depth+1,1,alpha,beta)); b[i]=" "
                beta=min(beta,val)
                if beta<=alpha: break
        return val

def best_move(b):
    m,v=-1,-math.inf
    for i in range(9):
        if b[i]==" ":
            b[i]="X"; val=alpha_beta(b,0,0,-math.inf,math.inf); b[i]=" "
            if val>v: v,m=val,i
    return m

def show(b):
    for i in range(0,9,3): print(b[i:i+3])

b=[" "]*9
print("You=O, AI=X. Positions 0-8.")
while not check_winner(b):
    p=int(input("Move: "))
    if b[p]!=" ": continue
    b[p]="O"
    if check_winner(b): break
    b[best_move(b)]="X"
    show(b)

print("Result:",check_winner(b))

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
