from PIL import Image, ImageDraw
import sys

sys.setrecursionlimit(10**9)

f = input()
t = input()
it = int(input())
n = int(input())
m = int(input())

pattern = [[None]*n]*m


img = Image.new('RGB', (n**it, m**it), 'Black')
dib = ImageDraw.Draw(img)

for i in range(m):
    pattern[i] = input()

    
def fractal(x, y, it, color):
    if it == 1:
        for i in range(m):
            for j in range(n):
                if color:
                    if pattern[i][j] == 'F':
                        dib.point((x+j, y+i), f)
                    if pattern[i][j] == 'T':
                        dib.point((x+j, y+i), t)
                else:
                    if pattern[i][j] == 'F':
                        dib.point((x+j, y+i), t)
                    if pattern[i][j] == 'T':
                        dib.point((x+j, y+i), f)
    else:
        for j in range(m):
            for i in range(n):
                lol = pattern[j][i]
                if lol == 'F':
                    #dib.point([x+(i*n**(it-1)), y+(j*m**(it-1))], "Yellow")
                    fractal(x+(i*n**(it-1)), y+(j*m**(it-1)), it-1, color)
                    
                elif lol == 'T':
                    
                    #dib.point([x+(i*n**(it-1)), y+(j*m**(it-1))], "Yellow")
                    fractal(x+(i*n**(it-1)), y+(j*m**(it-1)), it-1, not color)
                    
                    
                    

fractal(0, 0, it, True)



img.save('output.png')