from PIL import Image, ImageDraw
import sys 
sys.setrecursionlimit(10**6)

m = int(input())
n = int(input())
v = [None]*n
visited = [[False for i in range(m)] for j in range(n)]
seen = [[False for i in range(m)] for j in range(n)]

px = [-1, 0, 1, -1, 1, -1, 0, 1]
py = [-1, -1, -1, 0, 0, 1, 1, 1]


def dfs(x, y):
	if visited[x][y]:
		return
	visited[x][y] = True
	for i in range(8):
		seen[x+px[i]][y+py[i]] = True
		if v[x+px[i]][y+py[i]] != 'X':
			dfs(x+px[i], y+py[i])


x = 0
y = 0


for i in range(n):
	v[i] = list(input())
	for j in range(len(v[i])):
		if v[i][j] == 'P':
			x = i
			y = j


img = Image.new('RGB', [50*m, 50*n], 'Black')
dib = ImageDraw.Draw(img)
seen[x][y] = True
dfs(x, y)


for i in range(n):
	for j in range(m):
		if (not seen[i][j]) and (i > 0 and i < n-1 and j > 0 and j < m-1):
			continue
		if v[i][j] == 'X':
			dib.polygon([(50*j, 50*i), (49+50*j, 50*i), (49+50*j, 49+50*i), (50*j, 49+50*i)], 'Brown')
		else:
			dib.polygon([(50*j, 50*i), (49+50*j, 50*i), (49+50*j, 49+50*i), (50*j, 49+50*i)], 'White')
		if v[i][j] == 'P':
			dib.ellipse([(50*j+5, 50*i+5), (44+50*j, 44+50*i)], 'Blue')
		elif v[i][j] == 'T':
			dib.ellipse([(50*j+5, 50*i+5), (44+50*j, 44+50*i)], 'Gold')


img.save('output.png')