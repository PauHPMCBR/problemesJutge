from PIL import Image, ImageDraw

def func(x, y, x1, y1):
	return (x1*x1 - y1*y1 + x), (2*x1*y1 + y)

def q(x, y):
	return x*x+y*y

def checkMand(x, y, k):
	x1 = 0
	y1 = 0
	for i in range(k+1):
		if q(x1,y1) > 4:
			return False
		x1, y1 = func(x, y, x1, y1)
	return True

c = input()
f = input()
x1 = int(input())
x2 = int(input())
y1 = int(input())
y2 = int(input())
e = int(input())
k = int(input())

img = Image.new('RGB', [x2-x1+1, y2-y1+1], f)
dib = ImageDraw.Draw(img)

for x in range(x1, x2+1):
	for y in range(y1, y2+1):
		if checkMand(x/e, y/e, k):
			dib.point([x - x1, y - y1], c)

img.save('output.png')