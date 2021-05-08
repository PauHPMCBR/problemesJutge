import math

n = int(input())
k = 6
print(((math.ceil(math.sqrt(n)) + math.sqrt(n))**k + (math.ceil(math.sqrt(n)) - math.sqrt(n))**k)/2)