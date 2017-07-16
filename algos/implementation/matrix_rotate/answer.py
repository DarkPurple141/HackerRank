#!/usr/bin/env python3
matrix = []
sub_matrix = []

def main():
    rows, cols, rotates = map(int,input().split(' '))
    for _ in range(rows):
        temp = list(map(int,input().split()))
        matrix.append(temp)
        sub_matrix.append([0 for _ in range(cols)])
    print(matrix)
    print(sub_matrix)
    rotate(cols,rows,0,rotates)

def rotate(cols,rows,depth,rotates):
    print('rotate call:',cols, rows,depth)
    if depth >= rows or depth >= cols:
        return
    else:
        perim = (cols-depth)*2+(rows-depth)*2
        max_rotate = rotates % perim
        for i in range(cols):
            print(matrix[depth][i+depth],"",end="")
        print()
        for i in range(depth+1,rows-1+depth):
            print(matrix[i][depth], matrix[i][cols+depth-1])
        for i in range(cols):
            print(matrix[rows-1+depth][i+depth],"",end="")
        print()
        
        rotate(cols-2,rows-2,depth+1,rotates)

if __name__ == '__main__':
    main()
