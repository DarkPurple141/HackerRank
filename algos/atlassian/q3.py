#!/usr/bin/env python3

import random

bestindex = {}
a = []

def price_helper(prices, i):
    val = prices[i]
    if val not in bestindex:
        for j, sub in enumerate(prices[i+1:]):
            if sub <= val:
                bestindex[val] = j+i+1
                return (val-sub)
        else:
            return val
    elif bestindex[val] <= i:
        del bestindex[val]
        for j, sub in enumerate(prices[i+1:]):
            if sub <= val:
                bestindex[val] = j+i+1
                return (val-sub)
        else:
            return val
    elif bestindex[val] > i:
        return val-prices[bestindex[val]]
    else:
        return val

def price_helper_bad(prices, i):
    val = prices[i]
    for j, sub in enumerate(prices[i+1:]):
        if sub <= val:
            return (val-sub)
    else:
        return val

def finalPriceBad(prices):
    finalPrice = 0
    indexes = []
    for i, price in enumerate(prices):
        p = price_helper_bad(prices,i)
        if p == price:
            indexes.append(str(i))
        finalPrice += p
    print(finalPrice)
    print(" ".join(indexes))

def finalPrice(prices):
    finalPrice = 0
    indexes = []
    for i, price in enumerate(prices):
        p = price_helper(prices,i)
        if p == price:
            indexes.append(str(i))
        finalPrice += p
    print(finalPrice)
    print(" ".join(indexes))

def sol1():
    finalPrice(a)
def sol2():
    finalPriceBad(a)

if __name__ == "__main__":
    for _ in range(20000):
        a.append(random.randint(1,500))
    sol1()
    sol2()
