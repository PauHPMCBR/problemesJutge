from PIL import Image, ImageDraw

n = int(input())
m = int(input())

img = Image.new('RGB', (n*120, m*120), 'YellowGreen')
dib = ImageDraw.Draw(img)

for i in range(n):
	for j in range(m):
		mod = (i+j)%4
		x = 120*i + 20
		y = 120*j + 20
		c1 = 'Black'
		c2 = 'White'
		if (i+j)%8 > 3:
			c1, c2 = c2, c1
		if mod == 0:
			dib.ellipse([(x-14,y),(x-14+80-1,y+80-1)], c1)
			dib.ellipse([(x+14,y),(x+14+80-1,y+80-1)], c2)
		elif mod == 1:
			dib.ellipse([(x-10,y+10),(x+70-1,y+90-1)], c1)
			dib.ellipse([(x+10,y-10),(x+90-1,y+70-1)], c2)
		elif mod == 2:
			dib.ellipse([(x,y-14),(x+80-1,y-14+80-1)], c2)
			dib.ellipse([(x,y+14),(x+80-1,y+14+80-1)], c1)#!
		else:
			dib.ellipse([(x+10,y+10),(x+90-1,y+90-1)], c1)
			dib.ellipse([(x-10,y-10),(x+70-1,y+70-1)], c2)
		dib.ellipse([(x,y),(x+80-1,y+80-1)], 'Blue')

img.save('output.png')