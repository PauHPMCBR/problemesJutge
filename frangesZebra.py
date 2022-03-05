from PIL import Image, ImageDraw

n = int(input())
m = int(input())

img = Image.new('RGB', (n*105+55, m*105+5), 'Grey')
dib = ImageDraw.Draw(img)

for i in range(m):
	despl = 5
	if i%2 == 1:
		despl += 25
	elif i%4 == 2:
		despl += 50
	for j in range(n):
		x = despl + j*105
		y = 5 + i*105
		color = 'Black'
		if j%2 == 1:
			color = 'White'
		dib.polygon([(x,y),(x+100,y),(x+100,y+100),(x,y+100)], color)


img.save('output.png')