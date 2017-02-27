#!/usr/bin/env python3

n = int(input().strip())

a = dict()

maxi = 0

for i in input().split():
    try:
        a[i] += 1
    except KeyError:
        a[i] = 1

    if a[i] > maxi:
        maxi = a[i]

print(n - maxi)
