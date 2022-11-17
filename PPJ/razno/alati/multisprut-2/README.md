# MultiSPRUT 2

Sadržaj radnog direktorija treba odgovarati sadržaju ZIP arhive koja se šalje na SPRUT sa sljedeæim razlikama:
	- umjesto izvornih datoteka, u radnom direktoriju (i odgovarajuæim poddirektorijima) se trebaju nalaziti EXE datoteke
	- u radnom direktoriju se treba nalaziti direktorij "Testovi" s ulaznim i izlaznim datotekama grupiranim u poddirektorijima
	- MultiSPRUT u radnom direktoriju stvara datoteku "MultiSPRUT.cfg" u koju sprema redoslijed izvoðenja programa i formate ulaznih i izlaznih datoteka
	- MultiSPRUT u radnom direktoriju stvara direktorij "Neispravni izlazi" koji èisti pri poèetku svakog novog ispitivanja i tijekom ispitivanja zapisuje neispravne izlaze

Priloženi su primjeri radnih direktorija za MultiSPRUT.
Prvi primjer sadrži dvije izvršne datoteke, jedna u radnom direktoriju "SA", a druga u poddirektoriju "SA\analizator". Nakon ispitivanja MultiSPRUT-om pojavljuje se direktorij "SA\Neispravni izlazi" s nekoliko neispravnih izlaza.
Drugi primjer sadrži jednu izvršnu datoteku u radnom direktoriju "Sema". Nakon ispitivanja MultiSPRUT-om pojavljuje sa direktorij "Sema\Neispravni izlazi" koji treba biti prazan jer su svi izlazi ispravni.

Izvorni kod:
https://bitbucket.org/Ivan1248/multisprut-2/src/79b185f3e2f6dbcc91af360238ba608158daca56?at=master
Svatko smije mijenjati i koristiti izvorni kod bez navoðenja autora.
