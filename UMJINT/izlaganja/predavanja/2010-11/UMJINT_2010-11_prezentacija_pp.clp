(assert (pas Vero))
(assert (pas Garo))
(assert (macka Maca))
(defrule pobroji_pse (pas ?ime)
	=>
	 (printout t ?ime crlf))
