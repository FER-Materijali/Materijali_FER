# Prva domaća zadaća iz predmeta Paralelno programiranje: Vrlo gladni filozofi.
# Siniša Biđin, 0036433736

from mpi4py import MPI
from time import sleep
from random import randint

# Dohvatim osnovne podatke o sebi i ostalim filozofima.
comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()

# Uzmem početne vilice.
vilice = {
    'l': 'p' if rank == 0        else ' ',
    'r': ' ' if rank == size - 1 else 'p'
}

# Koji filozofi sjede lijevo i desno od mene?
susjedi = {
    'l': size - 1 if rank == 0 else rank - 1,
    'r': 0 if rank == size - 1 else rank + 1
}

# Koji su mi zahtjevi već poslani? Na početku nijedan.
zahtjevi = set()

# Koje susjede trenutno osluškujem? Kreni odmah obojicu.
osluškujem = {}
for strana in "lr":
   if strana not in osluškujem:
       osluškujem[strana] = comm.irecv(dest=susjedi[strana])


# Kao filozof, volim glasno najaviti svaku svoju radnju, kao i broj vilica koje
# posjedujem te njihovu čistoću.
def reci(msg):
    global vilice
    v = "[" + vilice['l'] + vilice['r'] + "]"
    print('\t'*rank + msg + v)


# Ponašam se drugačije ovisno o sadržaju i izvoru poruke koju primim.
def reagiraj(strana, poruka):
    global vilice

    # Ako sam primio vilicu, uzimam je.
    if poruka in "pč":
        vilice[strana] = poruka
        reci("got" + strana)

    # Ako sam primio zahtjev za vilicom...
    elif poruka == "gimme":
        # Dajem je ukoliko je prljava.
        if vilice[strana] == 'p':
            comm.isend('č', dest=susjedi[strana])
            vilice[strana] = ' '
            reci("gav" + strana)

        # Ako nemam prljavu, onda samo pamtim zahtjev za kasnije.
        else:
            if strana not in zahtjevi:
                zahtjevi.add(strana)
                reci("mem" + strana)


# Pogledam imam li novih poruka. Ako da, reagiram na njih.
def provjeri_poruke():
    # Sjećam li se nekih starijih zahtjeva? Ako da, reagiram na njih.
    global zahtjevi
    for smjer in zahtjevi:
        reagiraj(smjer, "gimme")

    # Nema više zahtjeva.
    zahtjevi = set()

    # Jesam li primio novu poruku od nekoga?
    global osluškujem
    for strana in "lr":
        ok, dat = osluškujem[strana].test()
        if ok:
            reagiraj(strana, dat)
            osluškujem[strana] = comm.irecv(dest=susjedi[strana])


# Dok mislim, dajem svoje vilice drugima na upit.
def misli():
    reci("omm")

    # Provjeravat ću nadolazeće poruke svako malo i reagirati na njih.
    n = randint(3, 14)
    while n > 0:
        provjeri_poruke()
        sleep(0.3)
        n -= 1


# Dok gladujem, tražim od drugih vilice koje nemam, a drugima ću na upit dati
# samo svoje prljave vilice.
def gladuj():
    reci("hgr")

    global vilice
    last_asked = 10

    while vilice['l'] == ' ' or vilice['r'] == ' ':
        for strana in "lr":
            if vilice[strana] == ' ' and last_asked > 7:
                comm.isend("gimme", dest=susjedi[strana])
                last_asked = 0
                reci('plz' + strana)

        provjeri_poruke()
        sleep(0.3)
        last_asked += 1


# Dok jedem, ne odgovaram na ikakve upite sve dok ne postanem sit.
def jedi():
    reci("eat")
    sleep(randint(1, 3))

    global vilice
    vilice = { 'l': 'p', 'r': 'p' }
    reci("ate")


if __name__ == "__main__":
    while True:
        misli()
        gladuj()
        jedi()
