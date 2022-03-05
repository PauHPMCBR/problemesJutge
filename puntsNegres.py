from PIL import Image, ImageDraw

n = int(input())
s = 150*n+25*(n-1)
img = Image.new('RGB', (s,s), 'White')
dib = ImageDraw.Draw(img)

for j in range(1,n):
	y = 150*j+25*(j-1)
	dib.polygon([(0,y),(0,y+24),(s,y+24),(s,y)],'Grey')

for i in range(1,n):
	x = 150*i+25*(i-1)
	dib.polygon([(x,0),(x+24,0),(x+24,s),(x,s)],'Grey')
	for j in range(1,n):
		y = 150*j+25*(j-1)
		dib.ellipse([(x,y),(x+24,y+24)],'Black')


img.save('output.png')