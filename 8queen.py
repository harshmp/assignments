import json
inf = open("8queen.json")
board = json.loads(inf.read())
board = board["matrix"]

for i in board:
    print i

def isSafe(row, col):
    for i in range(8):
        for j in range(8):
            if board[i][j] == 1 :
                if row == i:
                    return False
                if col == j:
                    return False
                if abs(row - i) == abs(col - j):
                    return False
    return True

def placeQueen(col):
    if col >= 8:
        print "..."
        return True

    for i in range(8):
        if isSafe(i, col):
            board[i][col] = 1
            if placeQueen(col+1):
                return True
            board[i][col] = 0
    return False

if(placeQueen(1) == True):
	print "Solution found!"
else:
	print "Solution not possible!"

for i in board:
    print i
