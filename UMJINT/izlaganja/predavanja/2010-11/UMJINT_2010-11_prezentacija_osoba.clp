(deftemplate osoba "osobne informacije"
	(slot ime
		(type SYMBOL)
	)
)
(assert (osoba (ime A)) (osoba (ime B)))
(defrule prozovi (osoba (ime ?ime))
	=> (printout t "Osoba " ?ime "." crlf))
(defrule drugi (osoba (ime ?tko&~Mirko))
	=> (printout t "Nije Mirko nego " ?tko "." crlf))
