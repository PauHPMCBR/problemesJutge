from PIL import Image, ImageDraw
from queue import PriorityQueue

n = int(input())
m = int(input())
v = []
s = (0,0)
e = (0,0)

img = Image.new('RGB', (m*25,n*25), 'Brown')
dib = ImageDraw.Draw(img)

for i in range(n):
	lel = input()
	v.append(list(lel))
	for j in range(m):
		if v[i][j] != 'X':
			dib.polygon([(25*j, 25*i), (25*j+24, 25*i), (25*j+24, 25*i+24), (25*j, 25*i+24)], 'White')
			if v[i][j] == 'O':
				dib.ellipse([(25*j+5, 25*i+5), (25*j+19, 25*i+19)], 'Black')
		if v[i][j] == 'S':
			s = (i,j)
		if v[i][j] == 'E':
			e = (i,j)

lel = int(input())
colors = []
for i in range(lel):
	colors.append(input())
x1,y1 = s
queue = PriorityQueue()
queue.put((0, x1, y1, []))
cami1 = []
leastW = -1

visited = [[False for i in range(m)] for i in range(n)]

while not queue.empty():
	weight, x, y, cami = queue.get()
	if visited[x][y]:
		continue
	cami.append((x,y))
	visited[x][y] = True
	if v[x][y] == 'O':
		weight += 10000

	if (x,y) == e:
		cami1 = cami
		break

	if not (x+1,y) in visited and v[x+1][y] != 'X':
		queue.put((weight+1, x+1, y, cami[:]))
	if not (x-1,y) in visited and v[x-1][y] != 'X':
		queue.put((weight+1, x-1, y, cami[:]))
	if not (x,y+1) in visited and v[x][y+1] != 'X':
		queue.put((weight+1, x, y+1, cami[:]))
	if not (x,y-1) in visited and v[x][y-1] != 'X':
		queue.put((weight+1, x, y-1, cami[:]))

colorPos = 0
cami1.reverse()
for (i,j) in cami1:
	dib.polygon([(25*j, 25*i), (25*j+24, 25*i), (25*j+24, 25*i+24), (25*j, 25*i+24)], 'Darkseagreen')
	if v[i][j] == 'O' or v[i][j] == 'S':
		dib.ellipse([(25*j+5, 25*i+5), (25*j+19, 25*i+19)], colors[colorPos])
		colorPos += 1

img.save('output.png')