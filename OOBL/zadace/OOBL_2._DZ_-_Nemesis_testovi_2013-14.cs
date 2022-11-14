using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NUnit.Framework;

namespace DrugaDomacaZadaca_Burza
{
    [TestFixture]
    public class BurzaTests
    {
        private IStockExchange _stockExchange;

        [SetUp]
        public void SetUp()
        {
            _stockExchange = Factory.CreateStockExchange();
        }


        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_AddStockToIndex_Complicated()
        {
            // Dodaju se dionice u index, onda se jedna obriše s burze i pokuša se dohvatiti u indeksu 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000000, 10m, DateTime.Now);

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);

            _stockExchange.AddStockToIndex(indeks1, dionica1);
            _stockExchange.AddStockToIndex(indeks1, dionica2);

            Assert.True(_stockExchange.IsStockPartOfIndex(indeks1, dionica1));
            Assert.True(_stockExchange.IsStockPartOfIndex(indeks1, dionica2));
            Assert.AreEqual(2, _stockExchange.NumberOfStocksInIndex(indeks1));

            _stockExchange.DelistStock(dionica1);

            _stockExchange.RemoveStockFromIndex(indeks1, dionica1);             // treba baciti exception
        }

        [Test]
        public void Test_AddStockToIndex_MoreIndices()
        {
            // Dodaje se ista dionica u različite indexe 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);
            string indeks2 = "indeks2";
            _stockExchange.CreateIndex(indeks2, IndexTypes.AVERAGE);

            _stockExchange.AddStockToIndex(indeks1, dionica1);
            _stockExchange.AddStockToIndex(indeks2, dionica1);

            Assert.True(_stockExchange.IsStockPartOfIndex(indeks1, dionica1));
            Assert.True(_stockExchange.IsStockPartOfIndex(indeks2, dionica1));
            Assert.AreEqual(1, _stockExchange.NumberOfStocksInIndex(indeks1));
            Assert.AreEqual(1, _stockExchange.NumberOfStocksInIndex(indeks2));
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_AddStockToIndex_NoIndex()
        {
            // Dodaju se dionice u index koji ne postoji na burzi

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000000, 10m, DateTime.Now);

            string indeks1 = "IndeksKojiNePostoji";

            _stockExchange.AddStockToIndex("IndeksKojiNePostoji", dionica1);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_AddStockToIndex_NoStock()
        {
            // Dodaju se dionice koje ne postoje na burzi u index koji postoji

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);

            _stockExchange.AddStockToIndex(indeks1, "dionicaKojaNePostoji");

        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_AddStockToIndex_SameStock()
        {
            // Dodaje se ista dionica više puta u index

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);

            _stockExchange.AddStockToIndex(indeks1, dionica1);
            _stockExchange.AddStockToIndex(indeks1, dionica1);
        }

        [Test]
        public void Test_AddStockToIndex_Simple()
        {
            // Dodaju se dionice u index
            string firstStockName = "IBM";
            _stockExchange.ListStock(firstStockName, 5, 100m, DateTime.Now);
            string secondStockName = "MSFT";
            _stockExchange.ListStock(secondStockName, 5, 200m, DateTime.Now);
            string thirdStockName = "GOOG";
            _stockExchange.ListStock(thirdStockName, 1, 300m, DateTime.Now);

            string indexName = "DOW JONES";
            _stockExchange.CreateIndex(indexName, IndexTypes.WEIGHTED);

            _stockExchange.AddStockToIndex(indexName, firstStockName);
            _stockExchange.AddStockToIndex(indexName, secondStockName);
            _stockExchange.AddStockToIndex(indexName, thirdStockName);

            Assert.True(_stockExchange.IsStockPartOfIndex(indexName, firstStockName));
            Assert.True(_stockExchange.IsStockPartOfIndex(indexName, secondStockName));
            Assert.True(_stockExchange.IsStockPartOfIndex(indexName, thirdStockName));
            Assert.AreEqual(3, _stockExchange.NumberOfStocksInIndex(indexName));
        }

        [Test]
        public void Test_AddStockToPortfolio_Complicated()
        {
            // Dodaju se dionice u portfelj, onda se jedna obriše s burze i pokuša se dohvatiti u portfelju

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000000, 10m, DateTime.Now);

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 1);
            _stockExchange.AddStockToPortfolio(portfelj1, dionica2, 1);

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica2));
            Assert.AreEqual(2, _stockExchange.NumberOfStocksInPortfolio(portfelj1));

            _stockExchange.DelistStock(dionica1);

            Assert.False(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));   // treba baciti false, tak je Vanjak rekao (iako dionica ne postoji na burzi)
        }

        [Test]
        public void Test_AddStockToPortfolio_GreaterThenNumOfShares()
        {
            // Dodaje se ista dionica više puta u portfelj - ukupno više od postojećeg broja 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);

            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 50);
            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 150);   // previše ih dodamo, treba ih dodati još 50 (ukupno ih mora biti 100)

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.AreEqual(100, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj1, dionica1));
        }

        [Test]
        public void Test_AddStockToPortfolio_MorePortfolios()
        {
            // Dodaje se ista dionica u različiti portfelj

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            string portfelj2 = "portfelj2";
            _stockExchange.CreatePortfolio(portfelj2);

            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 50);
            _stockExchange.AddStockToPortfolio(portfelj2, dionica1, 30);

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj2, dionica1));

            Assert.AreEqual(50, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj1, dionica1));
            Assert.AreEqual(30, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj2, dionica1));
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_AddStockToPortfolio_NegativeNumberOfShares()
        {
            // dodaje se neispravan broj dionica u portfelj

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);

            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, -100);
        }
        
        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_AddStockToPortfolio_NoPortfolio()
        {
            // Dodaju se dionice u portfelj koji ne postoji na burzi

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);

            _stockExchange.AddStockToPortfolio("PortfeljKojiNePostoji", dionica1, 100);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_AddStockToPortfolio_NoStock()
        {
            // Dodaju se dionice koje ne postoje na burzi u portfelj koji postoji

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);

            _stockExchange.AddStockToPortfolio(portfelj1, "NepostojeceDionice", 100);
        }

        [Test]
        public void Test_AddStockToPortfolio_SameStock()
        {
            // Dodaje se ista dionica više puta u portfelj

            string stockName = "IBM";
            _stockExchange.ListStock(stockName, 5, 100m, DateTime.Now);

            string portfolioID = "P1";
            _stockExchange.CreatePortfolio(portfolioID);

            _stockExchange.AddStockToPortfolio(portfolioID, stockName, 1);
            _stockExchange.AddStockToPortfolio(portfolioID, stockName, 2);

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfolioID, stockName));
            Assert.AreEqual(1, _stockExchange.NumberOfStocksInPortfolio(portfolioID));
            Assert.AreEqual(3, _stockExchange.NumberOfSharesOfStockInPortfolio(portfolioID, stockName));
        }

        [Test]
        public void Test_AddStockToPortfolio_Simple()
        {
            // Dodaju se dionice u portfelj

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 100, 10m, DateTime.Now);

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);

            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 50);
            _stockExchange.AddStockToPortfolio(portfelj1, dionica2, 50);

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica2));

            Assert.AreEqual(2, _stockExchange.NumberOfStocksInPortfolio(portfelj1));
            Assert.AreEqual(50, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj1, dionica1));
            Assert.AreEqual(50, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj1, dionica2));
        }

        [Test]
        public void Test_AddStockToPortfolios_GreaterThenNumOfShares()
        {
            // Dodaje se ista dionica u različiti portfelj - ukupno više od postojećeg broja 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            string portfelj2 = "portfelj2";
            _stockExchange.CreatePortfolio(portfelj2);

            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 50);
            _stockExchange.AddStockToPortfolio(portfelj2, dionica1, 150);   // OPREZ!!!!  u portfelju 2 ih treba biti samo 50 (jer ukupno u svim portfeljima mora biti 100)

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj2, dionica1));

            Assert.AreEqual(1, _stockExchange.NumberOfStocksInPortfolio(portfelj1));
            Assert.AreEqual(1, _stockExchange.NumberOfStocksInPortfolio(portfelj2));
            Assert.AreEqual(50, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj1, dionica1));
            Assert.AreEqual(50, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj2, dionica1));
        }




        // Test_ComplicatedChanges_Values




        // Test_CreateIndex_IllegalTypeNegative


        


        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_CreateIndex_SameNameAlreadyExists()
        {
            // Dodaje se indeks imena koje već postoji na burzi, ali drugog tipa 

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.AVERAGE);
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_CreateIndex_SameNameAndTypeAlreadyExists()
        {
            // Dodaje se indeks koji već postoji na burzi

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.AVERAGE);
            _stockExchange.CreateIndex(indeks1, IndexTypes.AVERAGE);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_CreateIndex_SimilarNameAlreadyExists()
        {
            // Dodaje se indeks koja već postoji na burzi ali s promjenom velika/mala slova u imenu 

            _stockExchange.CreateIndex("abc", IndexTypes.AVERAGE);
            _stockExchange.CreateIndex("ABC", IndexTypes.AVERAGE);
        }

        [Test]
        public void Test_CreateIndex_Simple()
        {
            // Dodaje se par indeksa i provjerava postoje li na burzi

            string firstIndexName = "DOW JONES";
            _stockExchange.CreateIndex(firstIndexName, IndexTypes.AVERAGE);
            string secondIndexName = "S&P";
            _stockExchange.CreateIndex(secondIndexName, IndexTypes.WEIGHTED);
            Assert.AreEqual(2, _stockExchange.NumberOfIndices());
            Assert.True(_stockExchange.IndexExists(firstIndexName));
            Assert.True(_stockExchange.IndexExists(secondIndexName));
            Assert.False(_stockExchange.IndexExists("AB"));
        }
        
        [Test]
        public void Test_CreateIPortfolio_Simple()
        {
            // Dodaje se par portfelja i provjerava postoje li na burzi 

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            string portfelj2 = "portfelj2";
            _stockExchange.CreatePortfolio(portfelj2);

            Assert.True(_stockExchange.PortfolioExists(portfelj1));
            Assert.True(_stockExchange.PortfolioExists(portfelj2));
            Assert.AreEqual(2, _stockExchange.NumberOfPortfolios());
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_CreatePortfolio_SameIdAlreadyExists()
        {
            // Dodaje se portfelj koji već postoji na burzi 

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            _stockExchange.CreatePortfolio(portfelj1);

        }

        [Test]
        public void Test_CreatePortfolio_SimilarNameAlreadyExists()
        {
            // Dodaje se portfelj sličnog imena 

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            string portfelj2 = "Portfelj1";
            _stockExchange.CreatePortfolio(portfelj2);

            Assert.True(_stockExchange.PortfolioExists(portfelj1));
            Assert.True(_stockExchange.PortfolioExists(portfelj2));
            Assert.AreEqual(2, _stockExchange.NumberOfPortfolios());

        }
         
        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_DelistStock_EmptyStockExchange()
        {
            // Pokušaj micanja dionice s burze koja nema niti jednu dionicu 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 0, 10m, DateTime.Now);

            // ak se ne varam, već bi kod dodavanja trebalo baciti exception
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_DelistStock_NotExist()
        {
            // Pokušaj micanja nepostojeće dionice s burze

            _stockExchange.DelistStock("nepostojecaDionica");
        }

        [Test]
        public void Test_DelistStock_Simple()
        {
            // Postojeća dionica miče se s burze
            
            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);

            Assert.True(_stockExchange.StockExists(dionica1));
            Assert.AreEqual(1, _stockExchange.NumberOfStocks());

            _stockExchange.DelistStock(dionica1);

            Assert.False(_stockExchange.StockExists(dionica1));
            Assert.AreEqual(0, _stockExchange.NumberOfStocks());
        }
        
        [Test]
        public void Test_GetIndexValue_AfterDelistingStock()
        {
            // Provjera izračuna vrijednosti portfelja nakon brisanja dionice s burze
            
            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 100, 20m, DateTime.Now);


            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 10);
            _stockExchange.AddStockToPortfolio(portfelj1, dionica2, 10);

            Assert.AreEqual(300, _stockExchange.GetPortfolioValue(portfelj1, DateTime.Now));

            _stockExchange.DelistStock(dionica1);

            Assert.AreEqual(200, _stockExchange.GetPortfolioValue(portfelj1, DateTime.Now));
        }

        [Test]
        public void Test_GetIndexValue_Average()
        {
            // Provjera izračuna AverageIndexa 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, DateTime.Now);
            System.Threading.Thread.Sleep(10);

            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000, 200m, DateTime.Now);
            System.Threading.Thread.Sleep(10);

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.AVERAGE);

            _stockExchange.AddStockToIndex(indeks1, dionica1);
            _stockExchange.AddStockToIndex(indeks1, dionica2);

            Assert.AreEqual(150, _stockExchange.GetIndexValue(indeks1, DateTime.Now));

        }

        [Test]
        public void Test_GetIndexValue_AverageAfterDelistingStock()
        {
            // Provjera izračuna AverageIndeksa nakon brisanja dionice s burze

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, DateTime.Now);
            System.Threading.Thread.Sleep(10);

            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000, 200m, DateTime.Now);
            System.Threading.Thread.Sleep(10);

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.AVERAGE);

            _stockExchange.AddStockToIndex(indeks1, dionica1);
            _stockExchange.AddStockToIndex(indeks1, dionica2);

            Assert.AreEqual(150, _stockExchange.GetIndexValue(indeks1, DateTime.Now));
            System.Threading.Thread.Sleep(10);

            _stockExchange.DelistStock(dionica2);

            Assert.AreEqual(100, _stockExchange.GetIndexValue(indeks1, DateTime.Now));
        }

        [Test]
        public void Test_GetIndexValue_AverageAfterPriceChange()
        {
            // Provjera izračuna AverageIndexa nakon promijene cijene

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, new DateTime(2014, 1, 1, 0, 0, 0));
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000, 200m, new DateTime(2014, 1, 1, 0, 0, 0));

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.AVERAGE);

            _stockExchange.AddStockToIndex(indeks1, dionica1);
            _stockExchange.AddStockToIndex(indeks1, dionica2);

            Assert.AreEqual(150, _stockExchange.GetIndexValue(indeks1, new DateTime(2014, 1, 2, 0, 0, 0)));

            _stockExchange.SetStockPrice(dionica2, new DateTime(2014, 1, 3, 0, 0, 0), 300m);

            Assert.AreEqual(200, _stockExchange.GetIndexValue(indeks1, new DateTime(2014, 1, 4, 0, 0, 0)));
        }

        [Test]
        public void Test_GetIndexValue_AverageAfterRemovingStock()
        {
            // Provjera izračuna AverageIndeksa nakon brisanja dionice iz indeksa 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, DateTime.Now);
            System.Threading.Thread.Sleep(10);

            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000, 200m, DateTime.Now);
            System.Threading.Thread.Sleep(10);

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.AVERAGE);

            _stockExchange.AddStockToIndex(indeks1, dionica1);
            _stockExchange.AddStockToIndex(indeks1, dionica2);

            Assert.AreEqual(150, _stockExchange.GetIndexValue(indeks1, DateTime.Now));

            _stockExchange.RemoveStockFromIndex(indeks1, dionica2);

            Assert.AreEqual(100, _stockExchange.GetIndexValue(indeks1, DateTime.Now));
        }

        
        

        
        // Test_GetIndexValue_Begining 





        [Test]
        public void Test_GetIndexValue_Weighted()
        {
            // Provjera izračuna WeightedIndeksa 

            string firstStockName = "IBM";
            _stockExchange.ListStock(firstStockName, 1, 100m, new DateTime(2012, 1, 11, 14, 10, 00, 00));
            string secondStockName = "MSFT";
            _stockExchange.ListStock(secondStockName, 2, 200m, new DateTime(2012, 1, 11, 14, 10, 00, 00));

            string indexName = "DOW JONES";
            _stockExchange.CreateIndex(indexName, IndexTypes.WEIGHTED);

            _stockExchange.AddStockToIndex(indexName, firstStockName);
            _stockExchange.AddStockToIndex(indexName, secondStockName);

            Assert.AreEqual(180m, _stockExchange.GetIndexValue(indexName, new DateTime(2012, 1, 11, 14, 11, 00, 00)));
        }

        [Test]
        public void Test_GetIndexValue_WeightedDecimal()
        {
            // Provjera izračuna WeightedIndeksa decimalno

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1, 110m, new DateTime(2014, 1, 1, 0, 0, 0));
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 2, 200m, new DateTime(2014, 1, 1, 0, 0, 0));

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);

            _stockExchange.AddStockToIndex(indeks1, dionica1);
            _stockExchange.AddStockToIndex(indeks1, dionica2);

            Assert.AreEqual(180.588m, _stockExchange.GetIndexValue(indeks1, new DateTime(2014, 1, 2, 0, 0, 0 )));
        }

        [Test]
        public void Test_GetInitialStockPrice_RandomPrices()
        {
            // Postavljanje cijena u trenucima i dohvaćanje početne

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, new DateTime(2013, 1, 1, 1, 0, 0, 0));
            
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 1, 1, 0, 0, 0), 200m);      // cijena nakon
            _stockExchange.SetStockPrice(dionica1, new DateTime(2012, 1, 1, 1, 0, 0, 0), 300m);      // cijena prije - trebala bi biti inicijalna jer je najstarija

            Assert.AreEqual(300m, _stockExchange.GetInitialStockPrice(dionica1));
        }

        [Test]
        public void Test_GetLastStockPrice_RandomPrices()
        {
            // Postavljanje cijena u trenucima i dohvaćanje zadnje

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, new DateTime(2013, 1, 1, 1, 0, 0, 0));
            
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 1, 1, 0, 0, 0), 200m);      // cijena nakon - najnovija/zadnja
            _stockExchange.SetStockPrice(dionica1, new DateTime(2012, 1, 1, 1, 0, 0, 0), 300m);      // cijena prije

            Assert.AreEqual(200m, _stockExchange.GetLastStockPrice(dionica1));
        }





        // Test_GetPortfolioPercentChangeInValueForMonth_Complicated

        // Test_GetPortfolioPercentChangeInValueForMonth_InitialPrices

        // Test_GetPortfolioPercentChangeInValueForMonth_PriceChanges





        [Test]
        public void Test_GetPortfolioPercentChangeInValueForMonth_Simple()
        {
            // provjera izračuna postotka mjesečne promjene

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));       // 1.1.2014. 0:00 100kn

            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 31, 0, 0, 0, 0), 150);        // 15.1.2014. 0:00 150kn (+50%)

            string portfolio1 = "portfolio1";
            _stockExchange.CreatePortfolio(portfolio1);

            _stockExchange.AddStockToPortfolio(portfolio1, dionica1, 100);

            Assert.AreEqual(50, _stockExchange.GetPortfolioPercentChangeInValueForMonth(portfolio1, 2014, 1));  // 1. mjesec 2014.
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_GetPortfolioPercentChangeInValueForMonth_WrongDate()
        {
            // provjera izračuna postotka mjesečne promjene uz pogrešnu vrijednost datuma 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));       // 1.1.2014. 0:00 100kn

            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 31, 0, 0, 0, 0), 150);        // 15.1.2014. 0:00 150kn (+50%)

            string portfolio1 = "portfolio1";
            _stockExchange.CreatePortfolio(portfolio1);

            _stockExchange.AddStockToPortfolio(portfolio1, dionica1, 100);

            Assert.AreEqual(50, _stockExchange.GetPortfolioPercentChangeInValueForMonth(portfolio1, 2014, 20));  // 20. mjesec 2014. (krivi datum)
        }

        [Test]
        public void Test_GetPortfolioValue_AfterPriceChange()
        {
            // Provjera izračuna vrijednosti portfelja nakon promijene cijene 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));       // 1.1.2014. 0:00 100kn

            string portfolio1 = "portfolio1";
            _stockExchange.CreatePortfolio(portfolio1);

            _stockExchange.AddStockToPortfolio(portfolio1, dionica1, 10);

            Assert.AreEqual(1000, _stockExchange.GetPortfolioValue(portfolio1, new DateTime(2014, 3, 1, 0, 0, 0, 0)));  // 1.3.2014. 0:00   PROVJERA

            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 31, 0, 0, 0, 0), 200);                         // 1.2.2014. 0:00 200kn

            Assert.AreEqual(2000, _stockExchange.GetPortfolioValue(portfolio1, new DateTime(2014, 3, 1, 0, 0, 0, 0)));  // 1.3.2014. 0:00
        }

        [Test]
        public void Test_GetPortfolioValue_AfterRemovingStock()
        {
            // Provjera izračuna vrijednosta portfelja nakon brisanja dionice iz portfolia 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));       // 1.1.2014. 0:00 100kn
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));       // 1.1.2014. 0:00 100kn

            string portfolio1 = "portfolio1";
            _stockExchange.CreatePortfolio(portfolio1);

            _stockExchange.AddStockToPortfolio(portfolio1, dionica1, 10);
            _stockExchange.AddStockToPortfolio(portfolio1, dionica2, 10);

            Assert.AreEqual(2000, _stockExchange.GetPortfolioValue(portfolio1, new DateTime(2014, 3, 1, 0, 0, 0, 0)));  // 1.3.2014. 0:00   PROVJERA

            _stockExchange.RemoveStockFromPortfolio(portfolio1, dionica2);

            Assert.AreEqual(1000, _stockExchange.GetPortfolioValue(portfolio1, new DateTime(2014, 3, 1, 0, 0, 0, 0)));  // 1.3.2014. 0:00
        }

        [Test]
        public void Test_GetPortfolioValue_Begining()
        {
            // Provjera izračuna vrijednosti portfelja na početku

            string portfolio1 = "portfolio1";
            _stockExchange.CreatePortfolio(portfolio1);

            Assert.AreEqual(0, _stockExchange.GetPortfolioValue(portfolio1, DateTime.Now));
        }

        [Test]
        public void Test_GetPortfolioValue_Sum()
        {
            // Provjera izračuna vrijednosti portfelja na početku

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));       // 1.1.2014. 0:00 100kn
            string dionica2 = "Dionica2";
            _stockExchange.ListStock(dionica2, 1000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));       // 1.1.2014. 0:00 100kn

            string portfolio1 = "portfolio1";
            _stockExchange.CreatePortfolio(portfolio1);

            _stockExchange.AddStockToPortfolio(portfolio1, dionica1, 10);
            _stockExchange.AddStockToPortfolio(portfolio1, dionica2, 10);

            Assert.AreEqual(2000, _stockExchange.GetPortfolioValue(portfolio1, new DateTime(2014, 3, 1, 0, 0, 0, 0)));  // 1.3.2014. 0:00   PROVJERA
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_GetStockPrice_BeforeAlPrices()
        {
            // Postavlja više cijena i dohvaćanje cijenu prije svih trenutaka 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, new DateTime(2014, 1, 1, 0, 0, 0, 0));     // 1.1.2014.
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 2, 0, 0, 0, 0), 100m);         // 2.1.2014.

            _stockExchange.GetStockPrice(dionica1, new DateTime(2013, 1, 1, 0, 0, 0, 0));               // 1.1.2013.    dionica tada nije ni postojala - exception
        }




        // Test_GetStockPrice_BeforeInitialPrice        // nisam siguran na kaj se misli

        // Test_GetStockPrice_InitialPrice

        [Test]
        public void Test_GetStockPrice_LastPrice()
        {
            // Postavljanje više cijena dionice i provjera vrijednosti zadnje

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));     // 1.1.2014.
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 2, 0, 0, 0, 0), 200m);         // 2.1.2014.
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 3, 0, 0, 0, 0), 300m);         // 3.1.2014.

            Assert.AreEqual(300m, _stockExchange.GetLastStockPrice(dionica1));
        }

        [Test]
        public void Test_GetStockPrice_MorePrices()
        {
            // Postavljanje više cijena dionica i provjera za određene trenutke

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));    // 1.1.2014.     100
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 10, 0, 0, 0, 0), 200m);        // 10.1.2014.    200
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 20, 0, 0, 0, 0), 300m);        // 20.1.2014.    300

            Assert.AreEqual(100m, _stockExchange.GetStockPrice(dionica1, new DateTime(2014, 1, 1, 10, 0, 0, 0)));   // 1.1.2014.    10:00   100
            Assert.AreEqual(200m, _stockExchange.GetStockPrice(dionica1, new DateTime(2014, 1, 14, 0, 1, 0, 0)));   // 14.1.2014.   00:01   200
            Assert.AreEqual(300m, _stockExchange.GetStockPrice(dionica1, new DateTime(2014, 2, 25, 0, 0, 0, 0)));   // 25.2.2014.   00:00   300
        }




        // Test_GetStockPrice_RandomPrices

        
        
        [Test]
        public void Test_GetStockPrice_SimilarName()
        {
            // Dohvaćanje početnu cijenu dionicu - upit sa sličnim imenom 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 300m, new DateTime(2014, 1, 20, 0, 0, 0, 0));   // 20.1.2014.   300
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 1, 0, 0, 0, 0), 100m);         // 1.1.2014.    100
            _stockExchange.SetStockPrice(dionica1, new DateTime(2014, 1, 10, 0, 0, 0, 0), 200m);        // 10.1.2014.   200

            Assert.AreEqual(100m, _stockExchange.GetInitialStockPrice("DIOnicA1"));
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_ListStock_IllegalNumberOfSharesNegative()
        {
            // Dodaje se dionica s negativnim brojem dionica

            _stockExchange.ListStock("IBM", -10, 10m, DateTime.Now);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_ListStock_IllegalNumberOfSharesNull()
        {
            // Dodaje se dionica s 0 dionica

            _stockExchange.ListStock("IBM", 0, 10m, DateTime.Now);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_ListStock_IllegalPriceNegative()
        {
            _stockExchange.ListStock("IBM", 1000000, -10m, DateTime.Now);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_ListStock_IllegalPriceNull()
        {
            _stockExchange.ListStock("IBM", 1000000, 0m, DateTime.Now);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_ListStock_SameName()
        {
            // Dodaje se dionica koja ima isto ime kao neka koja već postoji na burzi 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));

            _stockExchange.ListStock(dionica1, 1000000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_ListStock_SameNameAlreadyExists()
        {
            _stockExchange.ListStock("IBM", 1000000, 10m, DateTime.Now);
            _stockExchange.ListStock("IBM", 1000000, 10m, DateTime.Now);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_ListStock_SimilarNameAlreadyExists()
        {
            // Dodaje se dionica koja već postoji na burzi ali s promjenom velika/mala slova u imenu

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));

            _stockExchange.ListStock("DiOnIcA1", 1000000, 100m, new DateTime(2014, 1, 1, 0, 0, 0, 0));
        }

        [Test]
        public void Test_ListStock_Simple()
        {
            Assert.AreEqual(0, _stockExchange.NumberOfStocks());
            string firstStockName = "IBM";
            _stockExchange.ListStock(firstStockName, 1000000, 10m, DateTime.Now);

            Assert.AreEqual(1, _stockExchange.NumberOfStocks());
            Assert.True(_stockExchange.StockExists(firstStockName));
            Assert.False(_stockExchange.StockExists("Bezveze"));

            string secondStockName = "MSFT";
            _stockExchange.ListStock(secondStockName, 100000, 15m, DateTime.Now);
            Assert.AreEqual(2, _stockExchange.NumberOfStocks());
            Assert.True(_stockExchange.StockExists(secondStockName));
        }

        [Test]
        public void Test_NumberOfStocksInIndex_NoStocks()
        {
            // Ispitivanje broja dionica za indeks kojem nisu pridijeljene dionice

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);
            Assert.AreEqual(0, _stockExchange.NumberOfStocksInIndex(indeks1));

            string indeks2 = "indeks2";
            _stockExchange.CreateIndex(indeks2, IndexTypes.AVERAGE);
            Assert.AreEqual(0, _stockExchange.NumberOfStocksInIndex(indeks2));
        }

        [Test]
        public void Test_NumberOfStocksInPortfolio_NoStocks()
        {
            // Ispitivanje broja dionica za portfelj kojem nisu pridijeljene dionice

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);

            Assert.AreEqual(0, _stockExchange.NumberOfStocksInPortfolio(portfelj1));
        }






        // Test_RemoveStockFromIndex_MoreIndices




        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_RemoveStockFromIndex_NonExistingIndex()
        {
            // Briše se dionica iz nepostojećeg indeksa

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);

            _stockExchange.RemoveStockFromIndex("nepostojeciIndeks", dionica1);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_RemoveStockFromIndex_NonExistingStock()
        {
            // Briše se dionica koja ne postoji iz indeksa koji postoji

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);

            _stockExchange.RemoveStockFromIndex(indeks1, "NepostojecaDionica");     // treba baciti exception
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_RemoveStockFromIndex_Twice()
        {
            // 2 puta se briše ista dionica

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);

            string indeks1 = "indeks1";
            _stockExchange.CreateIndex(indeks1, IndexTypes.WEIGHTED);

            _stockExchange.AddStockToIndex(indeks1, dionica1);

            _stockExchange.RemoveStockFromIndex(indeks1, dionica1);
            _stockExchange.RemoveStockFromIndex(indeks1, dionica1);     // treba baciti exception
        }




        // Test_RemoveStockFromPortfolio_All


        // Test_RemoveStockFromPortfolio_AllTwice




        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_RemoveStockFromPortfolio_NonExistingPortfolio()
        {
            // Briše se dionica iz nepostojećeg portfelja 

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 1000000, 10m, DateTime.Now);

            _stockExchange.RemoveStockFromPortfolio("nepostojeciPortfelj", dionica1);
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_RemoveStockFromPortfolio_NonExistingStock()
        {
            // Briše se dionica koja ne postoji iz portfelja koji postoji

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);

            _stockExchange.RemoveStockFromPortfolio(portfelj1, "nepostojecaDionica");
        }

        [Test]
        public void Test_RemoveStockFromPortfolio_NumOfShares()
        {
            // Briše se određeni broj dionica iz portfelja

            string firstStockName = "IBM";
            _stockExchange.ListStock(firstStockName, 5, 100m, DateTime.Now);
            string secondStockName = "MSFT";
            _stockExchange.ListStock(secondStockName, 5, 200m, DateTime.Now);

            string portfolioID = "P1";
            _stockExchange.CreatePortfolio(portfolioID);
            _stockExchange.AddStockToPortfolio(portfolioID, firstStockName, 4);
            _stockExchange.AddStockToPortfolio(portfolioID, secondStockName, 1);

            _stockExchange.RemoveStockFromPortfolio(portfolioID, firstStockName, 2);

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfolioID, firstStockName));
            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfolioID, secondStockName));
            Assert.AreEqual(2, _stockExchange.NumberOfStocksInPortfolio(portfolioID));
            Assert.AreEqual(2, _stockExchange.NumberOfSharesOfStockInPortfolio(portfolioID, firstStockName));
            Assert.AreEqual(1, _stockExchange.NumberOfSharesOfStockInPortfolio(portfolioID, secondStockName));
        }

        [Test]
        public void Test_RemoveStockFromPortfolio_Simple()
        {
            // Briše se dionica iz portfelja

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 100);

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.AreEqual(1, _stockExchange.NumberOfStocksInPortfolio(portfelj1));

            _stockExchange.RemoveStockFromPortfolio(portfelj1, dionica1);
            
            Assert.False(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.AreEqual(0, _stockExchange.NumberOfStocksInPortfolio(portfelj1));
        }

        [Test]
        public void Test_RemoveStockFromPortfolio_Twice()
        {
            // 2 puta briše se određeni broj iste dionice

            string dionica1 = "Dionica1";
            _stockExchange.ListStock(dionica1, 100, 10m, DateTime.Now);

            string portfelj1 = "portfelj1";
            _stockExchange.CreatePortfolio(portfelj1);
            _stockExchange.AddStockToPortfolio(portfelj1, dionica1, 100);

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.AreEqual(1, _stockExchange.NumberOfStocksInPortfolio(portfelj1));
            Assert.AreEqual(100, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj1, dionica1));     // dodaj 100

            _stockExchange.RemoveStockFromPortfolio(portfelj1, dionica1, 50);                               // izbriši 50

            Assert.True(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.AreEqual(1, _stockExchange.NumberOfStocksInPortfolio(portfelj1));
            Assert.AreEqual(50, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj1, dionica1));      // treba ih biti 50


            _stockExchange.RemoveStockFromPortfolio(portfelj1, dionica1, 50);                               // izbriši još 50

            Assert.False(_stockExchange.IsStockPartOfPortfolio(portfelj1, dionica1));
            Assert.AreEqual(0, _stockExchange.NumberOfStocksInPortfolio(portfelj1));
            Assert.AreEqual(0, _stockExchange.NumberOfSharesOfStockInPortfolio(portfelj1, dionica1));       // treba ih biti 0
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_SetStockPrice_DifferentName()
        {
            // postavljanje cijene dionice sa drugačijim imenom 

            decimal oldPrice = 10m;
            _stockExchange.ListStock("IBM", 1000000, oldPrice, new DateTime(2012, 1, 10, 15, 22, 00));

            decimal newPrice = 20m;
            _stockExchange.SetStockPrice("KRIVO_IME", new DateTime(2012, 1, 10, 15, 40, 00), newPrice);
        }

        [Test]
        public void Test_SetStockPrice_NewPrice()
        {
            // Postavljanje cijene dionice i provjera vrijednosti za datume

            string stockName = "IBM";
            decimal oldPrice = 10m;
            _stockExchange.ListStock(stockName, 1000000, oldPrice, new DateTime(2012, 1, 10, 15, 22, 00));
            decimal newPrice = 20m;
            _stockExchange.SetStockPrice(stockName, new DateTime(2012, 1, 10, 15, 40, 00), newPrice);

            Assert.AreEqual(newPrice, _stockExchange.GetStockPrice(stockName, new DateTime(2012, 1, 10, 15, 50, 0, 0)));
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_SetStockPrice_SameTimeStamp()
        {
            // Pokušaj dodavanja cijene za trenutak koji već postoji

            _stockExchange.ListStock("IBM", 1000000, 10m, DateTime.Now);

            decimal cijena = 10m;
            _stockExchange.SetStockPrice("IBM", new DateTime(2012, 1, 10, 15, 40, 00), cijena);
            _stockExchange.SetStockPrice("IBM", new DateTime(2012, 1, 10, 15, 40, 00), cijena);
        }

        [Test]
        public void Test_SetStockPrice_SimilarName()
        {
            // Postavljanje cijene dionice sa sličnim imenom

            _stockExchange.ListStock("IBM", 1000000, 10m, DateTime.Now);

            decimal novaCijena = 20m;
            _stockExchange.SetStockPrice("IbM", new DateTime(2012, 1, 10, 15, 40, 00), novaCijena);
            Assert.AreEqual(novaCijena, _stockExchange.GetStockPrice("IBM", new DateTime(2012, 1, 10, 15, 40, 00)));
        }

        [Test]
        [ExpectedException(typeof(StockExchangeException))]
        public void Test_SetStockPrice_StockNotExists()
        {
            // Pokušaj postavljanja cijene dionici koja ne postoji
            _stockExchange.ListStock("IBM", 1000000, 10m, DateTime.Now);

            decimal cijena = 10m;
            _stockExchange.SetStockPrice("KRIVO_IME", new DateTime(2012, 1, 10, 15, 40, 00), cijena);
        }

        [Test]
        public void Test_StockExchangeAtTheBeginig()
        {
            // provjera početnih vrijednosti na burzi

            Assert.AreEqual(0, _stockExchange.NumberOfStocks());
            Assert.AreEqual(0, _stockExchange.NumberOfIndices());
            Assert.AreEqual(0, _stockExchange.NumberOfPortfolios());
        }

    }
}
