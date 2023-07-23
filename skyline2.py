from PIL import Image, ImageDraw
import math

f = input() #fons
c = input() #color
l = int(input()) #llargada de la imatge
d = int(input()) #diferencia maxima
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

while max(v) != 0: #escalar segons 'd'
	for i in range(l):
		if v[i] == max(v):
			dib.line(((i, w-1), (i, w-1-int(v[i]))), c)
			j = i-1
			while j > 0 and v[j] > v[i]-d:
				dib.line(((j, w-1), (j, w-1-int(v[i]))), c)
				v[j] = 0
				j -= 1
			j = i+1
			while j < l and v[j] > v[i]-d:
				dib.line(((j, w-1), (j, w-1-int(v[i]))), c)
				v[j] = 0
				j += 1
			v[i] = 0

img.show()
