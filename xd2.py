def rotCol(i, j, mat):
    if i != j:
        for k in range(4):
            mat[k][i],mat[k][j] = mat[k][j],mat[k][i]
    return mat

def rotRow(i, j, mat):
    if i != j:
        for k in range(4):
            mat[i][k],mat[j][k] = mat[j][k],mat[i][k]
    return mat

def gauss(mat):
    for i in range(3):
        k = i
        while (k < 3 and mat[k][i] == 0):
            k += 1
        if k >= 3:
            k = i
            while (k < 3 and mat[i][k] == 0):
                k += 1
            if k >= 3:
                continue
            else:
                mat = rotCol(i,k,mat)
                for l in range(i+1, 3):
                    for j in range(i+1, 4):
                        mat[l][j] = mat[l][j] - mat[l][i]*mat[i][j]/mat[i][i]
        else:
            mat = rotRow(i,k,mat)
            for l in range(i+1, 3):
                for j in range(i+1, 4):
                    mat[l][j] = mat[l][j] - mat[l][i]*mat[i][j]/mat[i][i]
    
    res = [0,0,0]
    
    for i in [2,1,0]:
        res[i]=mat[i][3]
        for j in range(i+1, 3):
            if i!=j:
                res[i] -= mat[i][j]*res[j]

        if (res[i] != 0 and mat[i][i] == 0):
            return False
        if (res[i] == 0):
            res[i] = 0
        else:
            res[i] = res[i]/mat[i][i]
    trobat = True
    for i in range(3):
        if (res[i] < 0):
            trobat = False
            break



    return trobat


while True:
    a1, a2, a3 = list(map(int,input().split()))
    if (a1 == a2 and a2 == a3 and a3 == 0):
        break;
    mat = [[0 for i in range(4)] for j in range(3)]
    mat[0][0] = a1
    mat[1][0] = a2
    mat[2][0] = a3
    x2 = list(map(int,input().split()))
    x3 = list(map(int,input().split()))
    x4 = list(map(int,input().split()))
    for i in range(3):
        mat[i][1] = x2[i]
        mat[i][2] = x3[i]
        mat[i][3] = x4[i]

    lcm = 1
    for i in range(3):
        for j in range(4):
            if (mat[i][j] == 0):
                continue
            lcm = lcm*mat[i][j]

    for i in range(3):
        for j in range(4):
            mat[i][j] *= lcm
    if (gauss(mat)):
        print("YES")
    else:
        print("NO")
    lmao = input()