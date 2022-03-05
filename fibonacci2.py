def fib(n):
	if n== 0 or n== 1:
		return n
	return fib (n- 1) + fib (n- 2)

n = input().split()
for i in n:
	print(fib(int(i)-1), end=' ')
print()