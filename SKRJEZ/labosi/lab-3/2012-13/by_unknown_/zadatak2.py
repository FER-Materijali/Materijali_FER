def main():
    datoteka = open("ulaz.txt", "r")
    datoteka = datoteka.readlines()
    print("Hyp#Q10#Q20#Q30#Q40#Q50#Q60#Q70#Q80#Q90")
    k = 1
    for red in datoteka:
        br = []
        red = list(red.rstrip().split(' '))
        l = len(red)
        for i in range(l):
            red[i] = float(red[i])
        red.sort()
        for i in range(1, 10):
            vr = int(round(i/10*l))
            br.append(red[vr])
        print(("%03d" % k)+'#'+str(br[0])+'#'+str(br[1])+'#'+str(br[2])+'#'+str(br[3])+'#'+str(br[4])+'#'+str(br[5])+'#'+str(br[6])+'#'+str(br[7])+'#'+str(br[8]))
        k+=1

if __name__ == "__main__":
    main()
