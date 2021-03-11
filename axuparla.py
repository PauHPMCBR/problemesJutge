for i in range(int(input())):
	n = int(input())
	print((pow(2,n+1,1000000007)-n-2+1000000007)%1000000007)