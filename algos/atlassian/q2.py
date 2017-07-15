#!/usr/bin/env python3

chars = ['a','b','c','d','e','f']
upper = ['A','B','D','E','F','C']
dig = ['1','2','3','4','5','6','7','8','9','0']

def ipv6(arr):
    for sub in arr:
        if not sub:
            return "Neither"
        if len(sub) > 4:
            return "Neither"
        for c in sub:
            if c not in dig and c not in chars and c not in upper:
                return "Neither"

    return "IPv6"

def ipv4(arr):
    for sub in arr:
        if not sub:
            return "Neither"
        if (len(sub) > 3):
            return "Neither"
        for c in sub:
            if c not in dig:
                return "Neither"
        if int(sub) > 255:
            return "Neither"

    return "IPv4"

def checkIPs(ip_array):
    result = []
    for ip in ip_array:
        notI4 = False
        notI6 = False
        if '.' not in ip:
            notI4 = True
        if ':' not in ip:
            notI6 = True

        if notI4 and notI6 or not (notI4 or notI6):
            result.append("Neither")
        elif notI4:
            temp = ip.split(":")
            if len(temp) != 8:
                result.append("Neither")
            else:
                result.append(ipv6(temp))
        elif notI6:
            temp = ip.split(".")
            if len(temp) != 4:
                result.append("Neither")
            else:
                result.append(ipv4(temp))

    return result


if __name__ == "__main__":
    print(checkIPs(['999.999.999.999','0.0.0.0','192.168.1.1',':::::::','0:0:0:0:0:0:0:0','1923.167.1.1', '1923.167.1.1a', "Junk text", "192.168"]))
