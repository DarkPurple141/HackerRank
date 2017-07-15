#!/usr/bin/env python3

def oddNumbers(l, r):
    result = []
    for i in range(l,r+1):
        if i % 2:
            result.append(i)

    return result
