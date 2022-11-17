Napisao sam ovaj test za Javu jer mi nije radio niti jedan od testova drugih kolega, a bio sam lijen sam tražiti greške. Posebnost ovog testa je da je iskljuèivo za Javu što omoguæuje da se program poziva unutar njega.
Test se može pokretati iz Eclipsea, samo treba iskopirati klasu u njega. Ja sam ga i pokretao iz Eclipsea, a ne komandne linije.
Ne trebate mijenjati svoju klasu jer ovaj test radi promjenu standardnog ulaza i izlaza na datoteke.

Ako netko želi samo engine usporedbe, a veæ je napravio svoje outpute, može izbrisati kod izmeðu 40. i 65. reda i reader.close() na kraju (SAMO reader.close(), ne close za ostale).

Da bi radilo treba napraviti sljedeæe korake (pišu i unutar klase):
1. Promijeniti konstante u redovima 21-24 tako da vode do pravih testova
	Put do npr. 12. testa u 2. labosu je kod mene C:\Users\Murta\Desktop\lab2_primjeri\test12\t.ul
	Mislim da je oèigledno što koja konstanta znaèi.
	Paziti da se unutar klase koriste \\ kod Pathova jer je za Javu \ escape char sljedeæeg
2. U 55. redu odrediti koju klasu želite testirati

I to je to. Nakon toga bi sve trebalo raditi za labos koji je podešen. Može se podestiti za SVAKI labos.
Provjerite outpute na kraju da je sve OK.