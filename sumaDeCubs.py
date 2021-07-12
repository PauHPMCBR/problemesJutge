from PIL import Image, ImageDraw

n = int(input())
s = int(input())

lel = (n*(n+1))//2
img = Image.new('RGB', (lel*s, lel*s))
dib = ImageDraw.Draw(img)

y = 0
for i in range(1,n+1):
	c1 = 'Yellow'
	c2 = 'Red'
	x = 0
	if i%2 == 0:
		x = -s*i//2
		c1 = 'Blue'
		c2 = 'Lime'
	for j in range(i//2+1):
		if j%2 == 0:
			dib.polygon([(x+j*i*s, y), (x+(j+1)*i*s-1, y), (x+(j+1)*i*s-1, y+i*s-1), (x+j*i*s, y+i*s-1)], c1)
		else:
			dib.polygon([(x+j*i*s, y), (x+(j+1)*i*s-1, y), (x+(j+1)*i*s-1, y+i*s-1), (x+j*i*s, y+i*s-1)], c2)

	for j in range(i//2):
		if j%2 == 0:
			dib.polygon([(y, x+j*i*s), (y, x+(j+1)*i*s-1), (y+i*s-1, x+(j+1)*i*s-1), (y+i*s-1, x+j*i*s)], c1)
		else:
			dib.polygon([(y, x+j*i*s), (y, x+(j+1)*i*s-1), (y+i*s-1, x+(j+1)*i*s-1), (y+i*s-1, x+j*i*s)], c2)
	y += i*s
img = img.rotate(90)
img.save('output.png')