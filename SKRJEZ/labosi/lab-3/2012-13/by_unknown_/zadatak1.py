def ucitavanje(ime, i):
    dat = open(ime, 'r')
    datoteka = dat.read()
    datoteka = datoteka.split('\n\n')
    redovi = datoteka[i].split('\n')
    vel = redovi[0].split(' ')

    matrice = {}
    matrice['r'] = int(vel[0])
    matrice['s'] = int(vel[1])

    for red in redovi[1:]:
        ele = red.split(' ')
        matrice[(int(ele[0]), int(ele[1]))] = float(ele[2])

    dat.close()
    return matrice


def ispis(ime):
    var = ''
    for i in range(1, ime['r']+1):
        for j in range(1, ime['s']+1):
            var += "%9g" % float(ime.get((i, j), 0))
        var += '\n'
    print(var)


def spremi(matrica, ime):
    dat = open(ime, 'w')
    dat.write(str(matrica['r']) + ' ' + str(matrica['s']) + '\n')
    for ele in matrica.keys():
        if ele != 'r' and ele != 's':
            dat.write(str(ele[0]) + ' ' + str(ele[1]) + ' ' + str(matrica[ele]) + '\n')
    dat.close()    
        


def main():
    mat1 = ucitavanje("rMatrice.txt", 0)
    mat2 = ucitavanje("rMatrice.txt", 1)
    print("Prva matrica:")
    ispis(mat1)
    print("Druga matrica:")
    ispis(mat2)

    if mat1['s'] != mat2['r']:
        exit("Matrice nisu ulancane!!!")

    umnozak = {}
    umnozak['r'] = mat1['r']
    umnozak['s'] = mat2['s']
    for i in range(1, mat1['r']+1):
        for j in range(1, mat2['s']+1):
            umnozak[(i, j)] = 0
            for k in range(1, mat1['s']+1):
                umnozak[(i, j)] += float(mat1.get((i, k), 0) * mat2.get((k, j), 0))
            if umnozak[(i, j)] == 0:
                del umnozak[(i, j)]

    print("Umnozak prve i druge matrice je:")
    ispis(umnozak)
    spremi(umnozak, "umnozak.txt")


if __name__ == "__main__":
    main()
