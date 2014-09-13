__author__ = 'lew'

primes = [2]
prime_sum = 2
i = 3
while len(primes) < 1000:
    for prime in primes:
        if i % prime == 0:
            break
        elif prime == primes[-1]:
            primes.append(i)
            prime_sum += i
    i += 1

print prime_sum