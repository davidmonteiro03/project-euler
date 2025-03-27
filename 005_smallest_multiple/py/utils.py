def abs(a: int) -> int:
    return a if a >= 0 else -a


def gcd(a: int, b: int) -> int:
    result: int = min(a, b)
    while result > 0:
        if a % result == 0 and b % result == 0:
            break
        result -= 1
    return result


def lcm(a: int, b: int) -> int:
    return abs(a * b) // gcd(a, b)
