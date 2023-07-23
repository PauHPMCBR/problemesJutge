import turtle

parity = 1

def draw_circle(x1,y1,x2,y2):
	r = abs((x1-x2)/2)
	x = (x1+x2)/2
	y = (y1+y2)/2

	turtle.penup()
	turtle.goto(x+r, y)
	turtle.seth(90)
	turtle.pendown()
	turtle.circle(r)
def tangent( x1,y1, r1, x2,y2,r2, x3,y3,r3):
	global parity
	#Descartes Theorem on tangent circles
	k1 = 1/r1
	k2 = 1/r2
	k3 = 1/r3
	k = k1+k2+k3+2*((k1*k2+k2*k3+k3*k1)**0.5)
	r = 1/k
	#Setting up the linear system of equations to find the center of the 4th circle given its radius
	a = -2*x1 +2*x2
	b = -2*y1+2*y2
	c = -2*x2 +2*x3
	d = -2*y2+2*y3
	if a==c and c==0:
		u = r1*r1 -r2*r2+2*r*(r1-r2)-x1*x1+x2*x2 -y1*y1 + y2*y2
		v = r2*r2 -r3*r3+2*r*(r2-r3)-x2*x2+x3*x3 -y2*y2 + y3*y3
		y = u/b
		x = x1-parity*1.33*r1
		parity*=-1
		return [x,y,r]
	else:

		u = r1*r1 -r2*r2+2*r*(r1-r2)-x1*x1+x2*x2 -y1*y1 + y2*y2
		v = r2*r2 -r3*r3+2*r*(r2-r3)-x2*x2+x3*x3 -y2*y2 + y3*y3
		
		#(A,B;C,D)) represents the inverse of the matrix (a,b,c,d)
		A = d/(a*d-b*c)
		D = a/(a*d-b*c)
		B = -b/(a*d-b*c)
		C = -c/(a*d-b*c)
		x = A*u + B*v
		y = C*u + D*v
		return [x,y,r]
def tangent3( x1,y1, r1, x2,y2,r2, x3,y3,r3):

	k1 = 1/r1
	k2 = 1/r2
	k3 = 1/r3
	k = (k1+k2+k3-2*((k1*k2 + k2*k3+k3*k1)**0.5))
	r = 1/k
	a = -2*x1 +2*x2
	b = -2*y1+2*y2
	c = -2*x1 +2*x3
	d = -2*y1+2*y3
	r*=-1
	u = r1*r1 -r2*r2+2*r*(r1-r2)-x1*x1+x2*x2 -y1*y1 + y2*y2
	v = r1*r1 -r3*r3+2*r*(r1-r3)-x1*x1+x3*x3 -y1*y1 + y3*y3
	A = d/(a*d-b*c)
	D = a/(a*d-b*c)
	B = -b/(a*d-b*c)
	C = -c/(a*d-b*c)
	x = A*u + B*v
	y = C*u+D*v
	return [x,y,abs(r)]
def fractal(x1,y1, r1, x2,y2,r2, x3,y3,r3,depth, t1):
	#if depth==0:
	#	return
	if (t1==1):
		circle = tangent(x1,y1, r1, x2,y2,r2, x3,y3,r3)
		print(circle[0],circle[1],circle[2])
		if circle[2]<2:
			return
		draw_circle([circle[0]-circle[2], circle[1]-circle[2], circle[0]+circle[2]-1, circle[1]+circle[2]-1], 'White',(int(255/16*(16-depth)),0,0))
		fractal(x1,y1, r1, x2,y2,r2, circle[0],circle[1],circle[2], depth+1, 1)
		fractal(x1,y1, r1, x3,y3,r3, circle[0],circle[1],circle[2],depth+1,1)
		fractal(x3,y3, r3, x2,y2,r2, circle[0],circle[1],circle[2],depth+1,1)
	if (t1==0):
		circle = tangent(x3,y3, r3, x2,y2,r2, x1,y1,-r1)
		print(circle[0],circle[1],circle[2])
		draw_circle([circle[0]-circle[2], circle[1]-circle[2], circle[0]+circle[2]-1, circle[1]+circle[2]-1], 'White',(int(255/16*(16-depth)),0,0))
		if circle[2]<2:
			return
		fractal(x1,y1, r1, x2,y2,r2, circle[0],circle[1],circle[2], depth+1, 0)
		fractal(x1,y1, r1, x3,y3,r3, circle[0],circle[1],circle[2],depth+1,0)
		fractal(x3,y3, r3, x2,y2,r2, circle[0],circle[1],circle[2],depth+1,1)




def fractal2(x1,y1, r1, depth):
	#if(depth==0):
		#return
	r2 = r1/2
	x2 = x1
	y2 = y1+r2
	if(r2<2):
		return
	draw_circle([x2-r2, y2-r2, x2+r2-1, y2+r2-1], 'White','Black')
	y3= y2-2*r2
	x3 = x2
	r3 = r2
	draw_circle([x3-r3, y3-r3, x3+r3-1, y3+r3-1], 'White','Black')
	fractal(x1,y1,r1,x2,y2,r2,x3,y3,r3,depth,0)
	fractal(x1,y1,r1,x2,y2,r2,x3,y3,r3,depth,0)
	fractal2(x2,y2,r2, depth+1)

D =10
l = 10
x = 100*l
y = 10*l

x1 = 300*l+x
y1 = (((3)**0.5)*100+200)*l+y
r1 = 10*l
r2 = r1*2
x2 = x1
y2 = y1 +r1-r2

r3 = r2*2
x3 = x1
y3 = y2+r2-r3

r4 = r1
x4 = x1
y4 = y1-2*r1

#circle = tangent3(x1,y2,r1, x2,y2,r2, x3,y3,r3)
#print(circle[0],circle[1],circle[2])
#dib.ellipse([circle[0]-circle[2], circle[1]-circle[2], circle[0]+circle[2]-1, circle[1]+circle[2]-1], 'White','Red')

#dib.ellipse([x1-r1,y1-r1, x1+r1-1,y1+r1-1], None,'Black')
#dib.ellipse([x2-r2,y2-r2, x2+r2-1,y2+r2-1], None,'Black')
dib.ellipse([x3-r3,y3-r3, x3+r3-1,y3+r3-1], None,'Black')
#dib.ellipse([x4-r4,y4-r4, x4+r4-1,y4+r4-1], None,'Black')
fractal2(x3,y3,r3,1)
#fractal( x2,y2,r2,x4,y4,r4,x1,y1, r1, D,0)
#fractal( circle[0],circle[1],circle[2],x1,y1, r2, x3,y3,r2,2*D,0)
#fractal( circle[0],circle[1],circle[2],x3,y3, r3, x2,y2,r3,2*D,0)
#fractal(x1,y1,r1, x2, y2, r2, x3,y3, r3, D,1)
img.show()
img.save('output.png')