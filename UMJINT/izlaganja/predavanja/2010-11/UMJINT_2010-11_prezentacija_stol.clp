(defrule trazi1 (stol) => 
	(assert (pronadeno stol)))
(defrule trazi2 (stol) => 
	(printout t "Evo stola! :D" crlf))
(defrule trazi3 (declare (salience 10)) (stol) => 
	(printout t "Prvi!" crlf))
(assert (stol))

