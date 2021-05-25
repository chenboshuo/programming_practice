# import time
def find_scheme(scheme,i,j,id) -> int:
    if i < 0 or j < 0 or i >= 4 or j >= 4 or scheme[i][j] != 0:
        # time.sleep(0.02)
        # print(scheme,end="\r")
        return int(id == 17)
    scheme[i][j] = id
    moves = ((0,1),(0,-1),(1,0),(-1,0))
    total = 0
    for x,y in moves:
        total += find_scheme(scheme,i+x,j+y,id+1)
    scheme[i][j] = 0
    return total

total = 0
scheme = [[0]*4 for _ in range(4)]
for i in range(4):
    for j in range(4):
        total += find_scheme(scheme,i,j,1)
        # print(scheme)

print(total//4)