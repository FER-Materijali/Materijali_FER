import os
import re


def main():

    student = {}
    dat = open('studenti.txt', 'r')
    datoteka = dat.readlines()
    st = []
    for red in datoteka:
        JMBAG,Prezime,Ime = red.rstrip().split(' ')
        student[JMBAG] = {'prez': Prezime, 'ime': Ime}
        st.append(JMBAG)
    dat.close()

    vjezbe=[]
    lista = os.listdir('.')
    for dat in lista:
        if re.match('(Lab_[0-9]+_g[0-9]+.txt)', dat):
            d = open(dat, 'r')
            datoteka = d.readlines()
            vj = int(dat.split('_')[1])
            if vj not in vjezbe:
                vjezbe.append(vj)
            for red in datoteka:
                if not student.get(red.split(" ")[0],0).get(vj,0):
                    student[red.split(" ")[0]][vj] = float(red.split(" ")[1])
                else:
                    print("UPOZORENJE!!!")
                    print(student[red.split(" ")[0]]["ime"], student[red.split(" ")[0]]["prez"], "je vec pristupio/la", str(vj) + ".", "vjezbi!")
    d.close()

    L = len(vjezbe)
    print("JMBAG       Prezime, Ime       ",end='')
    for i in range(L):
        print("     L" + str(i+1),end='')
    print()
    for i in st:
        print(i + "  " + "%-20s" % (student[i]["prez"] + ", " + student[i]["ime"]),end='')
        for j in range(1, L+1):            
            print("    " + "%-3.1f" % (student.get(i,0).get(j,0)),end='')
        print()


if __name__ == '__main__':
    main()
