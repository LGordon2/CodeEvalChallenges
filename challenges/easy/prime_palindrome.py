__author__ = 'lew'


def is_palindrome(str):
    return str[0:len(str)/2] == str[::-1][0:len(str)/2]

def is_prime(num):
    for i in range(2, num - 1):
        if num % i == 0:
            return False
    return True

for i in reversed(range(1, 1000)):
    i_as_str = str(i)
    if is_palindrome(i_as_str) and is_prime(i):
        print i_as_str
        exit(0)