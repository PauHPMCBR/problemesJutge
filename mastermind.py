from PIL import Image, ImageDraw

s = input()
n = int(input())

color = {'R' : 'Red', 'G' : 'Green', 'B' : 'Blue', 'Y' : 'Yellow', 'P' : 'Pink', 'O' : 'Orange'}

img = Image.new('RGB', (900, 100*n), 'Sienna')
dib = ImageDraw.Draw(img)

counter = 0

for j in range(n):
	counter += 1
	b = 0
	neg = 0
	v = [0,0,0,0]
	s2 = input()
	s1 = [lel for lel in s]
	diff = 0
	for i in range(4):
		if s1[i-diff] == s2[i]:
			v[i] = 1
			neg += 1
			s1.pop(i-diff)
			diff += 1
	for i in range(4):
		if v[i] != 1:
			if s2[i] in s1:
				b += 1
				s1.pop(s1.index(s2[i]))

	for i in range(4):
		dib.ellipse([(100*i, 100*j),(100*i+99, 100*j+99)], color[s2[i]])
	pos = 0
	for i in range(neg):
		dib.ellipse([(100*pos+500, 100*j),(100*pos+99+500, 100*j+99)], 'Black')
		pos += 1
	for i in range(b):
		dib.ellipse([(100*pos+500, 100*j),(100*pos+99+500, 100*j+99)], 'White')
		pos += 1
	if s == s2:
		break
	

img = img.crop((0,0,900, 100*counter))

img.save('output.png')