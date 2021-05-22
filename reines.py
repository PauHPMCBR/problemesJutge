from PIL import Image, ImageDraw
import sys 

sys.setrecursionlimit(10**6)

n = int(input())
col = []
dig1 = []
dig2 = []

img = Image.new('RGB', [50*n, 50*n], 'Beige')
dib = ImageDraw.Draw(img)


def escriu():
	for i in range(n):
		for j in range(n):
			if (i+j) % 2 == 1:
				dib.polygon([(50*i, 50*j), (50+50*i-1, 50*j), (50+50*i-1, 50+50*j-1), (50*i, 50+50*j-1)], 'Brown')
			if col[j] == i:
				dib.ellipse([(50*i + 5, 50*j + 5), (50+50*i - 6, 50+50*j - 6)], 'Black')

def backtrack(p):
	if p == n:
		escriu()
		return True
	for i in range(n):
		if col[i] >= 0:
			continue
		if dig1[(n-1+i-p)] == True:
			continue
		if dig2[(2*n-2-i-p)] == True:
			continue
		col[i] = p
		dig1[(n-1+i-p)] = True
		dig2[(2*n-2-i-p)] = True
		if backtrack(p+1) == True:
			return True
		col[i] = -1
		dig1[(n-1+i-p)] = False
		dig2[(2*n-2-i-p)] = False
	return False



col = [-1]*n
dig1 = [False]*3*n
dig2 = [False]*3*n
backtrack(0)

img.save('output.png')