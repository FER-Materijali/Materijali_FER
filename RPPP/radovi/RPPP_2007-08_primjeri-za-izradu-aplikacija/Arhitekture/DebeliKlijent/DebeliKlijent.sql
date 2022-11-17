SELECT     TOP (10) Dokument.IdPartnera, PoslovniPartner.Naziv, PoslovniPartner.Broj, SUM(Dokument.IznosDokumenta) AS Promet
FROM         Dokument INNER JOIN
                          (SELECT     IdOsobe AS IdPartnera, PrezimeOsobe + ' ' + ImeOsobe AS Naziv, JMBG AS Broj
                            FROM          Osoba
                            UNION
                            SELECT     IdTvrtke AS IdPartnera, NazivTvrtke AS Naziv, MatBrTvrtke AS Broj
                            FROM         Tvrtka) AS PoslovniPartner ON Dokument.IdPartnera = PoslovniPartner.IdPartnera
GROUP BY Dokument.IdPartnera, PoslovniPartner.Naziv, PoslovniPartner.Broj
ORDER BY Promet DESC
GO

