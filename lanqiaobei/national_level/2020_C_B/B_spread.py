boundaries = {(0, 0),(2020, 11), (11, 14), (2000, 2000)}
interior = set()
for t in range(2020):
    new_boundaries = set()
    while boundaries:
        point = boundaries.pop()        
        if point not in interior:
            interior.add(point)
            for dx,dy in [(0,1),(1,0),(-1,0),(0,-1)]:
                new_point = (point[0]+dx,point[1]+dy)
                if new_point not in interior and new_point not in boundaries:
                    new_boundaries.add(new_point)
    boundaries = new_boundaries

print(len(interior|boundaries))