from PIL import Image, ImageDraw

c = int(input())
f = int(input())
n = int(input())

v = [[-1 for i in range(f)] for j in range(c)]

img = Image.new('RGB', [75*c, 75*f], 'Beige')
dib = ImageDraw.Draw(img)

v[0][0] = 1
v[-1][-1] = 0

for i in range(n):
	x = int(input())
	y = int(input())
	v[x-1][y-1] = 0

x = 0
y = 0
reached = True
path = []

while x != c-1 or y != f-1:
	if x < c-1 and v[x+1][y] != -1:
		path.append([(x,y),(x+1,y)])
		x += 1
		v[x][y] = 1
	elif y < f-1 and v[x][y+1] != -1:
		path.append([(x,y),(x,y+1)])
		y += 1
		v[x][y] = 1
	else:
		reached = False
		break

if reached:
	path.append([(x,y),(c-1,f-1)])
	v[-1][-1] = 1

for i in range(c):
	for j in range(f):
		if v[i][j] == 0:
			dib.ellipse([75*i+25, 75*j+25, 75*i+49, 75*j+49], 'Black')
		elif v[i][j] == 1:
			if reached:
				dib.ellipse([75*i+25, 75*j+25, 75*i+49, 75*j+49], 'Green')
			else:
				dib.ellipse([75*i+25, 75*j+25, 75*i+49, 75*j+49], 'Red')

for (x1,y1),(x2,y2) in path:
	if reached:
		dib.rectangle([x1*75+35, y1*75+35, x2*75+39, y2*75+39], 'Green')
	else:
		dib.rectangle([x1*75+35, y1*75+35, x2*75+39, y2*75+39], 'Red')


img.save('output.png')