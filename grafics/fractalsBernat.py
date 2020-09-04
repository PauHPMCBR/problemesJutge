from PIL import Image, ImageDraw




	
f = 'Red'
c = 'Blue'
it = int(input())
x = int(input())
y = int(input())
img = Image.new('RGB', [x**it, y**it], f)
dib = ImageDraw.Draw(img)


def iteration(x1,y1,x2,y2,s,width,height,it):
	v = (x2-x1)/width
	w = (y2-y1)/height
	c1;
	c2;
	for i in range(x1,x2,v):
		c2=0
		for j in range(y1,y2,w):
			if s[c2][c1]=='X':
				if it==1:
					#dib.point([(j*v,i*w)],c)
					dib.point([(i,j)],c)
				#else:
					#dib.polygon([(j*v,i*w),((j+1)*v-1,i*w),((j+1)*v-1,(i+1)*w-1),(j*v,(i+1)*w-1)],c)
				else:
					iteration(i,j,i,(i+1)*w,s,width,height,it-1)
					#iteration(j*v,i*w,(j+1)*v,(i+1)*w,s,width,height,it-1)
			c2++;
		c1++;




s = []
for i in range(y):
    s.append(list(input()))
   
print(s)

iteration(0,0,x**it,y**it,s,x,y,it)
img.show()
img.save('output.png')
