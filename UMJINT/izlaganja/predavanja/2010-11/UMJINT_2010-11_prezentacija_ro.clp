(assert (broj 1))
(assert (broj 2))
(assert (broj 3))
(assert (zbroj 0))
(defrule zbroji (declare (salience 2)) ?staro <- (zbroj ?zbroj) ?br <-(broj ?broj) =>
	(retract ?staro)
	(retract ?br)
	(assert (zbroj (+ ?broj ?zbroj))))
(defrule ispis (zbroj ?zbroj) =>
	(printout t "Drugi korijen od kuba zbroja je "
		(sqrt (** ?zbroj 3))
		"." crlf
))
