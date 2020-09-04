from PIL import Image, ImageDraw
import sys
sys.setrecursionlimit(10**6)

c = input()
f = input()
it = int(input())
l = int(input())
w = int(input())
img = Image.new('RGB', [l**it, w**it], f)
dib = ImageDraw.Draw(img)

s = []

def iteration(x, y, it):
    for i in range(w):
        for j in range(l):
            if s[i][j] == 'X':
                if it == 1:
                    dib.point([y+j, x+i], c)
                else:
                    iteration(x + i*(w**(it-1)), y + j*(l**(it-1)), it-1)
	



for i in range(w):
    s.append(list(input()))


iteration(0, 0, it)

img.show()
img.save('output.png')
