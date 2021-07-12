from PIL import Image, ImageDraw

n = int(input())
p = int(input())
v = []
maxx = 0
maxy = 0
minx = n
miny = n

for i in range(p):
	x = int(input())
	if x > maxx:
		maxx = x
	if x < minx:
		minx = x
	y = int(input())
	if y > maxy:
		maxy = y
	if y < miny: 
		miny = y
	v.append((x,y))

img = Image.new('RGB', (n, n), 'Beige')
dib = ImageDraw.Draw(img)

dib.polygon([(minx, miny), (maxx, miny), (maxx, maxy), (minx, maxy)], 'Red')

for (x,y) in v:
	dib.point((x,y), 'Black')

img.save('output.png')