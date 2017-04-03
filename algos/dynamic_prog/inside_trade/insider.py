#!/usr/bin/env python3

def main(n):
    for row in range(1,n+1):
        for col in range(1,n+1):
            if (n-row) >= col:
                print(" ", end ="")
            else:
                print("#", end="")
        print("")




if __name__ == "__main__":
    main(6)
