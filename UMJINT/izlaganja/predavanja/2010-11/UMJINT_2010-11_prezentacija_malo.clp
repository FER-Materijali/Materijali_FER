(assert (osoba Mirko 17))
(assert (osoba Slavko 18))
(assert (osoba Slavko 19))
(defrule samo_punoljetni
	?maloljetnik <- (osoba ?ime ?godine)
	(test (< ?godine 18))
	=>
	 (retract ?maloljetnik)
	 (printout t "Uklonjen je maloljetnik " ?ime "." crlf))
