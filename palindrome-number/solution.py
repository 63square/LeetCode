class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        a = x % 10
        if x < 100:
            if x < 10:
                return True
            return x // 10 == a

        b = (x % 100) // 10
        c = (x % 1000) // 100
        d = (x % 10000) // 1000
        e = (x % 100000) // 10000
        if x < 1000000:
            if x < 10000:
                if x < 1000:
                    return x // 100 == a

                return x // 1000 == a and c == b
            if x < 100000:
                return x // 10000 == a and d == b

            return x // 100000 == a and e == b and d == c

        f = (x % 1000000) // 100000
        g = (x % 10000000) // 1000000
        if x < 100000000:
            if x < 10000000:
                return x // 1000000 == a and f == b and e == c

            return x // 10000000 == a and g == b and f == c and e == d

        h = (x % 100000000) // 10000000
        if x < 1000000000:
            return x // 100000000 == a and h == b and g == c and f == d

        i = (x % 1000000000) // 100000000
        return x // 1000000000 == a and i == b and h == c and g == d and f == e
