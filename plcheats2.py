import mouse
import keyboard
import time, sys
import unicodedata
sys.setrecursionlimit(10000)

#letters = ['e', 'b', 'a', 'u', 'q', 't', 's']
#letters = ['s', 'd', 'e', 'v', 'a', 'l', 'g']
letters = ['g', 'r', 'o', 'a', 'x', 'd', 'n']

intro = (855, 573)
coords = [
	(762, 390), #centre
	(717, 321), #dalt esquerra
	(801, 316), #dalt dreta
	(845, 394), #dreta
	(800, 463), #baix dreta
	(716, 459), #baix esquerra
	(670, 386)  #esquerra
]

def printWord(word):
	for i in word:
		mouse.move(i[0], i[1])
		mouse.click()
		time.sleep(0.001)
	mouse.move(intro[0], intro[1])
	mouse.click()
	time.sleep(0.001)
	return

def checkWord(word):
	hasFirst = False
	for i in word:
		if not i in letters:
			return False
		else:
			if i == letters[0]:
				hasFirst = True
	return hasFirst

def transformWord(text):
	word = []
	for i in text:
		word.append(coords[letters.index(i)])
	return word


time.sleep(2)
with open("transformedCatDic.txt", "r", encoding="utf8") as dic:
	for word in dic:
		if checkWord(word[:-1]):
			printWord(transformWord(word[:-1]))
