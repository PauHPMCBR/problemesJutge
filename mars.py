x = input()
x = [x[i:i+2] for i in range(0, len(x), 2)]
dic = {"AA":"Glycine", "AT":"Cysteine", "TU":"Arginine", "UA":"Serine", "UU":"Lysine"}
first = True
last = False
ans = []
for i in x:
	if last == True:
		ans = ["None"]
		break
	if first == True:
		if i != "AU":
			ans = ["None"]
			break
		first = False
	else:
		if i == "TA" or i == "TT":
			last = True
		elif i == "UT":
			if ans == "":
				ans = ["None"]
				break
			else:
				ans = ans[:-1]
		else:
			if not i in dic:
				ans = ["None"]
				break
			else:
				ans.append(dic[i])
if last == False:
	ans = ["None"]
first = True
for i in ans:
	if first == True:
		first = False
	else:
		print(',', end='')
	print(i, end='')
print()
