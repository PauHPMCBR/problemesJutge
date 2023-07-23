from PIL import Image, ImageDraw
import math

f = input() #fons
c = input() #color
l = int(input()) #llargada de la imatge
n = int(input()) #nombre de funcions sinus
v = [0 for i in range(l)] #punts on s'avaluen

for i in range(n): #lectura de les funcions
	a = float(input())
	b = float(input())
	for j in range(l):
		v[j] += a*math.sin(b*j)

mm = min(v) #normalitzar la imatge (perque no quedin negatius)
for i in range(l):
	v[i] -= mm
print(v)

w = int(max(v))+25

img = Image.new('RGB', (l, w), f)
dib = ImageDraw.Draw(img)

for i in range(l):
	dib.line(((i, w-1), (i, w-1-int(v[i]))), c)

img.show()
