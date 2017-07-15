#!/usr/bin/env python3

def romanize(num):
    if num == 1000:
        return "M"
    elif num >= 900:
        return "CM" + romanize(num - 900)
    elif num >= 500:
        return "D" + romanize(num-500)
    elif num >= 400:
        return "CD" + romanize(num-400)
    elif num >= 100:
        return "C" + romanize(num-100)
    elif num >= 90:
        return "XC" + romanize(num-90)
    elif num >= 50:
        return "L" + romanize(num-50)
    elif num >= 40:
        return "XL" + romanize(num-40)
    elif num >= 10:
        return "X" + romanize(num-10)
    elif num >= 9:
        return "IX" + romanize(num-9)
    elif num >=5:
        return "V" + romanize(num-5)
    elif num >= 4:
        return "IV" + romanize(num-4)
    elif num >= 1:
        return "I" + romanize(num-1)
    else:
        return ""


def romanizer(numbers):
    # between I and M
    result = []

    for num in numbers:
        result.append(romanize(num))

    return result

if __name__ == "__main__":
    print(romanizer([1000, 900, 350]))
