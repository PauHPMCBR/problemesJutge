from collections import deque

while True:

    s = input()

    nombres = s.split()

    del(nombres[0])

    print(max(nombres))
