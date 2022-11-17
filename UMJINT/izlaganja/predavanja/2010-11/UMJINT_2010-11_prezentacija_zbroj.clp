(assert (ucitaj))
(defrule citanje (ucitaj) =>
	(printout t "Prvi pribrojnik: ")
	(assert (b1 (read)))
	(printout t "Drugi pribrojnik: ")
	(assert (b2 (read))))
(defrule zbroj (b1 ?br1) (b2 ?br2) =>
	(bind ?zbroj (+ ?br1 ?br2))
	(printout t "Zbroj je " ?zbroj "." crlf))
