import numpy as np

while True:
	e1 = list(map(int,input().split()))
	if e1 == [0,0,0]:
		break
	e2 = list(map(int,input().split()))
	e3 = list(map(int,input().split()))
	e0 = [0,0,0]
	s = list(map(int,input().split()))

	A = np.array([e1, e2, e3])
	b = np.array(s)
	try:
		x = np.linalg.solve(A, b)
		print(x)
		if x[0] < 0 or x[1] < 0 or x[2] < 0:
			print("NO")
		else:
			print("YES")
	except:
		try:
			A = np.array([e1,e2,e0])
			x = np.linalg.solve(A, b)
			print(x)
			if x[0] < 0 or x[1] < 0:
				print("NO")
			else:
				print("YES")
		except:
			try:
				A = np.array([e2,e3,e0])
				x = np.linalg.solve(A, b)
				print(x)
				if x[0] < 0 or x[1] < 0:
					print("NO")
				else:
					print("YES")
			except:
				try:
					A = np.array([e1,e3,e0])
					x = np.linalg.solve(A, b)
					print(x)
					if x[0] < 0 or x[1] < 0:
						print("NO")
					else:
						print("YES")
				except:
					try:
						A = np.array([e1,e0,e0])
						x = np.linalg.solve(A, b)
						print(x)
						if x[0] < 0:
							print("NO")
						else:
							print("YES")
					except:
						try:
							A = np.array([e2,e0,e0])
							x = np.linalg.solve(A, b)
							print(x)
							if x[0] < 0:
								print("NO")
							else:
								print("YES")
						except:
								A = np.array([e3,e0,e0])
								x = np.linalg.solve(A, b)
								print(x)
								if x[0] < 0:
									print("NO")
								else:
									print("YES")

	