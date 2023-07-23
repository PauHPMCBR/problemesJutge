def arithmetic_derivative(n):
    if n == 0 or n == 1:
        return 0
    if is_prime(n):
        return 1

    # Find prime factors of n
    prime_factors = get_prime_factors(n)
    x = prime_factors[0]
    y = n // x

    return x * arithmetic_derivative(y) + y * arithmetic_derivative(x)

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False

    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6

    return True

def get_prime_factors(n):
    factors = []
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

for n in range(0, 1000000):
    if n == arithmetic_derivative(n):
        print(n)