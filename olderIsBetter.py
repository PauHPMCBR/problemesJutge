alphabet = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
def find(letter):
    for x in range(len(alphabet)):
        if letter==alphabet[x]:
            return x
    return -1

arr =input()
k = int(arr[2])
n = int(arr[0])
for p in range(n):
    text = input()
    t = []

    for x in range(len(text)):
        t.append(text[x])
        if t[x]!=' ' and t[x]!='.':
            t[x] = alphabet[(find(t[x])-k)%26]
    res=""
    for x in range(len(t)):
        res+=t[x]
    print(res)