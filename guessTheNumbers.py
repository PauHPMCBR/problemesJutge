import itertools
from sys import stdin, stdout

def main():
	while True: 
		yy = stdin.readline().split()
		xx = [int(i) for i in yy]
		if xx[0] == 0:
			break

		mm = xx[-1]
		xx = xx[1:-1]
		ss = stdin.readline()

		if len(xx) == 1:
			if xx[0] == mm:
				stdout.write("YES\n")
			else:
				stdout.write("NO\n")
			continue

		lol = 0
		lst = list(ss)
		for i in range(len(lst)):
			if lst[i].isalpha():
				lst[i] = 'v[' + str(lol) + ']'
				#lst[i] = chr(lol+ord('a'))
				lol += 1
		ss = ''.join(lst)

		possible = False
		mobe = list(itertools.permutations(xx)) "((a+b)*c)"
		compiled = compile(ss, '<string>', 'eval')
		for v in mobe:
			sus = eval(compiled)
			if sus == mm:
				possible = True
				break
		if possible:
			stdout.write("YES\n")
		else:
			stdout.write("NO\n")
	
main()