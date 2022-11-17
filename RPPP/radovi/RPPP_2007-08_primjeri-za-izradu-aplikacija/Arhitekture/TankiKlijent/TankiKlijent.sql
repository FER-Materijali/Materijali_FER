CREATE VIEW [dbo].[vw_Partner]
AS
SELECT     IdOsobe AS IdPartnera, PrezimeOsobe + ' ' + ImeOsobe AS Naziv, JMBG AS Broj
FROM         dbo.Osoba
UNION
SELECT     IdTvrtke AS IdPartnera, NazivTvrtke AS Naziv, MatBrTvrtke AS Broj
FROM         dbo.Tvrtka
GO

CREATE VIEW [dbo].[vw_Promet]
AS
SELECT     TOP (10) IdPartnera, SUM(IznosDokumenta) AS Promet
FROM         dbo.Dokument
GROUP BY IdPartnera
ORDER BY Promet DESC
GO

CREATE VIEW [dbo].[vw_PrometPartnera]
AS
SELECT     TOP (100) PERCENT dbo.vw_Partner.IdPartnera, dbo.vw_Partner.Naziv, dbo.vw_Partner.Broj, dbo.vw_Promet.Promet
FROM         dbo.vw_Promet INNER JOIN
                      dbo.vw_Partner ON dbo.vw_Promet.IdPartnera = dbo.vw_Partner.IdPartnera
ORDER BY dbo.vw_Promet.Promet DESC
GO

CREATE PROCEDURE [dbo].[ap_PrometPartnera]
AS
BEGIN
	SELECT * FROM vw_PrometPartnera
    ORDER BY Promet DESC
END
GO

CREATE PROCEDURE [dbo].[ap_DokumentPartnera]
	 @IdPartnera int
AS
BEGIN
	SELECT IdDokumenta, VrDokumenta, BrDokumenta, DatDokumenta, IznosDokumenta	
	FROM Dokument
	WHERE	Dokument.IdPartnera = @IdPartnera;
END
GO