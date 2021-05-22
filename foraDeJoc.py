from PIL import Image, ImageDraw

img = Image.new('RGB', (101, 71), 'Green')
dib = ImageDraw.Draw(img)

n = int(input())
Bx = [None]*n
By = [None]*n
for i in range(n):
	Bx[i] = int(input())
	By[i] = int(input())
m = int(input())
Mx = [None]*m
My = [None]*m
for i in range(m):
	Mx[i] = int(input())
	My[i] = int(input())

p2 = Mx.index(min(Mx))
p1 = Bx.index(min(Bx))

if Bx[p1] < 50:
	if Bx[p1] < Mx[p2]:
		dib.polygon([(0,0), (0,71), (Bx[p1],71), (Bx[p1],0)], 'Red')
	elif Bx[p1] > Mx[p2]:
		dib.polygon([(0,0), (0,71), (Mx[p2],71), (Mx[p2],0)], 'Orange')

dib.line([(50,0),(50,71)], 'White')

dib.line([(0,16),(16,16)], 'White')
dib.line([(16,16),(16,54)], 'White')
dib.line([(0,54),(16,54)], 'White')

dib.line([(100,16),(100-16,16)], 'White')
dib.line([(100-16,16),(100-16,54)], 'White')
dib.line([(100,54),(100-16,54)], 'White')

dib.line([(0,25),(6,25)], 'White')
dib.line([(6,25),(6,45)], 'White')
dib.line([(0,45),(6,45)], 'White')

dib.line([(100,25),(100-6,25)], 'White')
dib.line([(100-6,25),(100-6,45)], 'White')
dib.line([(100,45),(100-6,45)], 'White')

dib.arc([40, 25, 60, 45], 0, 360, 'White')

for i in range(n):
	dib.ellipse([(Bx[i]-3, By[i]-3), (Bx[i]+3, By[i]+3)], 'Blue')
for i in range(m):
	dib.ellipse([(Mx[i]-3, My[i]-3), (Mx[i]+3, My[i]+3)], 'Magenta')


img.save('output.png')