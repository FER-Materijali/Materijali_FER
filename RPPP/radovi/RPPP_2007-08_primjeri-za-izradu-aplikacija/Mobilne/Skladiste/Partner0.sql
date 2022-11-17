SET IDENTITY_INSERT Partner ON
INSERT INTO Partner
		(IdPartnera
		,TipPartnera
		,IdMjestaPartnera
		,AdrPartnera
		,IdMjestaIsporuke
		,AdrIsporuke)
	VALUES
		(0
		,'T'
		,null
		,null
		,null
		,null)
SET IDENTITY_INSERT Partner OFF


INSERT INTO Tvrtka
		(IdTvrtke
		,MatBrTvrtke
		,NazivTvrtke)
	VALUES
		(0
		,'000'
		,'Nepoznat')