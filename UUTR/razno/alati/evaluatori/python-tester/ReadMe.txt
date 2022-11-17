run.bat je mali program za provjeru vaših python programa.
Da bi ispravno radio treba mu config.conf u kojemu se nalaze podatci o 
vašem programu i vrsti datoteka koje sadrže podatke o ulazu i izlazu.
Da bi run.bat radio mora se nalaziti u datoteci skupa sa vašim .py programom
i test datotekom koja sadrži sve testove u ovom obliku:

run.bat
program.py
test \  -test01 \ -test.in
		  -test.out
	-test02 \ -test.in
		  -test.out
	-test03 \ -test.in
		  -test.out

Pri tome da test01, test02, test03, ... se mogu zvati kako god želite,
dok test ne.
Testne primjere možete naći na http://materijali.fer2.net/Folder.65.aspx

Za sva dodatna pitanja, kontaktirajte me na: deanbabich@gmail.com
