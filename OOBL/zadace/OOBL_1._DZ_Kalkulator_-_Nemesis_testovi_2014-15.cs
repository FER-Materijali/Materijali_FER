using System;
using System.Text;
using System.Collections.Generic;
using System.Linq;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace PrvaDomacaZadaca_Kalkulator
{
    [TestClass]
    public class ExampleTests
    {
        private ICalculator calculator;

        /// <summary>
        /// Provjera promjene predznaka negativnog broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_ChangeSignOfANegativeNumber_PositiveNumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('M');
            calculator.Press('M');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2", displayState);
        }

        /// <summary>
        /// Provjera promjene predznaka pozitivnog broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_ChangeSignOfAPositiveNumber_NegativeNumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('M');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-2", displayState);
        }

        /// <summary>
        /// Provjera piše li nakon uključivanja kalkulatora 0 na ekranu
        /// </summary>
        [TestMethod]
        public void CheckDisplay_OnTheBegining_Zero()
        {
            calculator = Factory.CreateCalculator();

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0", displayState);
        }

        /// <summary>
        /// Provjera sadržaja na ekranu nakon pritiska binarnog operatora (binarni operator se ne ispisuje na ekranu)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressBinaryOperatorAfterNumber_Number()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('5');
            calculator.Press('+');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2,5", displayState);
        }

        /// <summary>
        /// Provjera počisti li se ekran nakon pritiska na clear bez obzira na operacije i znamenke koje su unesene
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressClear_Zero()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('1');
            calculator.Press('+');
            calculator.Press('3');
            calculator.Press('C');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0", displayState);
        }

        /// <summary>
        /// Provjera mogu li se nastaviti operacije nakon obrisanog ekrana
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressClearThenNumber_Result()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('1');
            calculator.Press('+');
            calculator.Press('3');
            calculator.Press('C');
            calculator.Press('5');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("6", displayState);
        }

        /// <summary>
        /// provjera funkcije kosinus (+ provjera pravilnog zaokruživanja decimala)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressCosinus_CosinusOfANumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('4');
            calculator.Press('K');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-0,653643621", displayState);
        }

        /// <summary>
        /// Provjera ispisuje li se decimalni znak nakon pritiska na njega nakon unosa broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressDecimalCharacterAfterDigits_Digits()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press(',');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2,", displayState);
        }

        /// <summary>
        /// Provjera ispisuje li se decimalni znak nakon pritiska na njega na početku
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressDecimalCharacterOnTheBegining_Zero()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press(',');
            calculator.Press('2');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0,2", displayState);
        }

        /// <summary>
        /// Provjera unosa decimalnog broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressDecimalNumber_Digits()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('0');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2,0", displayState);
        }

        /// <summary>
        /// Provjera ispisuje li se znamenka nakon pritiska na neki broj
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressDigit_Digit()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2", displayState);
        }

        /// <summary>
        /// Provjera obrade znaka jednakosti nakon decimalnog broja koji se može zaokružiti (npr. 2,00)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressEqualAfterDecimalNumber_NaturalNumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('0');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2", displayState);
        }

        /// <summary>
        /// Provjera obrade znaka jednakosti nakon unosa decimalnog broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressEqualAfterDecimalNumber_Number()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('5');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2,5", displayState);
        }

        /// <summary>
        /// Provjera obrade znaka jednakosti nakon decimalnog znaka unesenog nakon unosa broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressEqualAfterDecimalSign_NaturalNumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2", displayState);
        }

        /// <summary>
        /// Provjera obrade znaka jednakosti nakon unosa cjelobrojnog broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressEqualAfterNaturalNumber_Number()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2", displayState);
        }

        /// <summary>
        /// Provjera operacija s istim brojem (2+= --> 2+2)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressEqualAfterPlus_OperationWithTheSameNumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('+');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("4", displayState);
        }

        /// <summary>
        /// Provjera obrade znaka jednakosti nakon decimalnog znaka unesenog na početku
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressEqualAfterZeroAndDecimalSign_Zero()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press(',');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0", displayState);
        }

        /// <summary>
        /// Provjera funkcije inverza (+ provjera pravilnog zaokruživanja decimala)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressInvers_InversOfANumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('3');
            calculator.Press('I');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0,333333333", displayState);
        }

        /// <summary>
        /// Provjera obrade pogreške prilikom dijeljenja s 0
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressInversOfTheZero_Error()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('0');
            calculator.Press('I');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-E-", displayState);
        }

        /// <summary>
        /// -(sin({broj}+-{broj}*{broj})^2) --> MEMORIJA , 1/{broj}+MEMORIJA
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMixOfOperation_Result()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('3');
            calculator.Press('+');
            calculator.Press('2');
            calculator.Press('M');
            calculator.Press('*');
            calculator.Press('4');
            calculator.Press('=');
            calculator.Press('Q');
            calculator.Press('S');
            calculator.Press('M');
            calculator.Press('P');
            calculator.Press('C');
            calculator.Press('5');
            calculator.Press('I');
            calculator.Press('+');
            calculator.Press('G');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0,487903317", displayState);
        }

        /// <summary>
        /// Provjera zanemaruje li se drugi decimalni znak
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMoreDecimalCharacters_Digits()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('7');
            calculator.Press('8');
            calculator.Press(',');
            calculator.Press('6');
            calculator.Press(',');
            calculator.Press('1');
            calculator.Press('5');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("78,615", displayState);
        }

        /// <summary>
        /// Provjera što će se dogoditi ako se više puta zaredom stisnu različiti binarni operatori
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMoreDiffernetBinaryOperators_ResultOfLastOperation()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('5');
            calculator.Press(',');
            calculator.Press('+');
            calculator.Press('-');
            calculator.Press('-');
            calculator.Press('*');
            calculator.Press('3');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("15", displayState);
        }

        /// <summary>
        /// Pritisak više brojeva i provjera jesu li svi ispisani na ekranu
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMoreDigits_Digits()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('7');
            calculator.Press('5');
            calculator.Press('2');
            calculator.Press('6');
            calculator.Press(',');
            calculator.Press('0');
            calculator.Press('0');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("7526,00", displayState);
        }

        /// <summary>
        /// Provjera izgubi li se početna nula nakon pritiska drugih znamenki
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMoreDigitsAfterZero_Number()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('0');
            calculator.Press('7');
            calculator.Press('5');
            calculator.Press('2');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("752", displayState);
        }

        /// <summary>
        /// Pritisak više znamenki nego što može stati na ekran te provjera je li prikazano samo prvih 10
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMoreDigitsThenAllowed_FirstDigits()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('1');
            calculator.Press('2');
            calculator.Press('3');
            calculator.Press('4');
            calculator.Press('5');
            calculator.Press(',');
            calculator.Press('6');
            calculator.Press('7');
            calculator.Press('8');
            calculator.Press('9');
            calculator.Press('1');
            calculator.Press('2');
            calculator.Press('3');
            calculator.Press('4');
            calculator.Press('M');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-12345,67891".ToString(), displayState);
        }

        /// <summary>
        /// Provjera što se dogodi ako se više puta zaredom pritisne isti binarni operator
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMoreTimesSameBinaryOperator_ResultLikeThereWasOnlyOne()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('5');
            calculator.Press('+');
            calculator.Press('+');
            calculator.Press('+');
            calculator.Press('3');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("8", displayState);
        }

        /// <summary>
        /// Provjera višestrukih unarnih operacija
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMoreTimesSameUnaryOperator_MoreOperationExecution()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('3');
            calculator.Press('Q');
            calculator.Press('Q');
            calculator.Press('Q');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("6561", displayState);
        }

        /// <summary>
        /// pritisak više 0 i provjera nalazi li se samo jedna na ekranu
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressMoreZeros_Zero()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('0');
            calculator.Press('0');
            calculator.Press('0');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0", displayState);
        }

        /// <summary>
        /// Provjera počisti li se sve nakon restiranja kalkulatora
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressOffOn_Zero()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('1');
            calculator.Press('+');
            calculator.Press('3');
            calculator.Press('O');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0", displayState);
        }

        /// <summary>
        /// provjera funkcije sinus (+ provjera pravilnog zaokruživanja decimala)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressSinus_SinusOfANumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('4');
            calculator.Press('S');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-0,756802495".ToString(), displayState);
        }

        /// <summary>
        /// provjera funkcije kvadriranja (+ provjera pravilnog zaokruživanja decimala)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressSquare_SquareOfANumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('1');
            calculator.Press('2');
            calculator.Press('3');
            calculator.Press(',');
            calculator.Press('4');
            calculator.Press('5');
            calculator.Press('Q');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("15239,9025", displayState);
        }

        /// <summary>
        /// provjera funkcije korjenovanja (+ provjera pravilnog zaokruživanja decimala)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressSquareRoot_SquareRootOfANumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('R');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("1,414213562".ToString(), displayState);
        }

        /// <summary>
        /// Provjera obrade pogreške prilikom korjenovanja negativnog broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressSquareRootOfANegativeNumber_Error()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('M');
            calculator.Press('R');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-E-", displayState);
        }

        /// <summary>
        /// provjera funkcije tangens (+ provjera pravilnog zaokruživanja decimala)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressTangens_TangensOfANumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('4');
            calculator.Press('T');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("1,157821282".ToString(), displayState);
        }

        /// <summary>
        /// Provjera {broj1} {binarni} {unarni} {broj1} = {broj1}{binarni}{broj2}
        /// unarni se izračuna i prikaže ali se ne uzima u obzir u binarnoj operaciji
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressUnaryOperatorAfterBinaryThenEqual_BinaryOperation()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('+');
            calculator.Press('I');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0,5", displayState);

            calculator.Press('3');
            calculator.Press('=');

            displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("5", displayState);
        }

        /// <summary>
        /// Provjera množenja dva broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_ProductOfTwoNumbers_Product()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('8');
            calculator.Press('4');
            calculator.Press('2');
            calculator.Press('6');
            calculator.Press(',');
            calculator.Press('5');
            calculator.Press('*');
            calculator.Press('5');
            calculator.Press('3');
            calculator.Press(',');
            calculator.Press('7');
            calculator.Press('7');
            calculator.Press('2');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("453109,758", displayState);
        }

        /// <summary>
        /// Provjera dijeljenja dva broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_QuotientOfTwoNumbers_Quotient()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('3');
            calculator.Press('0');
            calculator.Press('8');
            calculator.Press('4');
            calculator.Press('8');
            calculator.Press(',');
            calculator.Press('4');
            calculator.Press('5');
            calculator.Press('8');
            calculator.Press('6');
            calculator.Press('8');
            calculator.Press('/');
            calculator.Press('5');
            calculator.Press('3');
            calculator.Press(',');
            calculator.Press('7');
            calculator.Press('7');
            calculator.Press('2');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("573,69", displayState);
        }

        /// <summary>
        /// Provjera ispisuje li se error u slučaju da je rezultat operacije veći od dopuštenog
        /// </summary>
        [TestMethod]
        public void CheckDisplay_ResultIsBiggerThanAllowed_Error()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('1');
            calculator.Press('2');
            calculator.Press('3');
            calculator.Press('4');
            calculator.Press('5');
            calculator.Press('6');
            calculator.Press('7');
            calculator.Press('8');
            calculator.Press('9');
            calculator.Press('0');
            calculator.Press('*');
            calculator.Press('1');
            calculator.Press('2');
            calculator.Press('3');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-E-", displayState);
        }

        /// <summary>
        /// Provjera rada s memorijom
        /// </summary>
        [TestMethod]
        public void CheckDisplay_SaveAndGetNumberFromMemory_SavedNumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('3');
            calculator.Press('4');
            calculator.Press('P');
            calculator.Press('5');
            calculator.Press('G');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("234", displayState);
        }

        /// <summary>
        /// Spremanje više brojeva u memoriju i provjera dohvaća li se samo zadnji
        /// </summary>
        [TestMethod]
        public void CheckDisplay_SaveMoreTimesAndGetLastNumberFromMemory_SavedNumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('P');
            calculator.Press('3');
            calculator.Press('P');
            calculator.Press('4');
            calculator.Press('P');
            calculator.Press('5');
            calculator.Press('G');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("234", displayState);
        }

        /// <summary>
        /// Provjera oduzimanja dva broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_SubtractOfTwoNumbers_Subtract()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('9');
            calculator.Press('4');
            calculator.Press('2');
            calculator.Press('7');
            calculator.Press('8');
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('5');
            calculator.Press('-');
            calculator.Press('1');
            calculator.Press('6');
            calculator.Press(',');
            calculator.Press('8');
            calculator.Press('3');
            calculator.Press('1');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("942765,669", displayState);
        }

        /// <summary>
        /// Provjera zbrajanja dva broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_SumOfTwoNumbers_Sum()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('9');
            calculator.Press('4');
            calculator.Press('2');
            calculator.Press('7');
            calculator.Press('8');
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('5');
            calculator.Press('+');
            calculator.Press('1');
            calculator.Press('6');
            calculator.Press(',');
            calculator.Press('8');
            calculator.Press('3');
            calculator.Press('1');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("942799,331", displayState);
        }

        /// <summary>
        /// Provjera sadržaja na ekranu nakon pritiska binarnog operatora (binarni operator se ne ispisuje na ekranu)
        /// </summary>
        [TestMethod]
        public void CheckDisplay_PressBinaryOperatorAfterNumber_NaturalNumber()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('0');
            calculator.Press('+');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("2", displayState);
        }

        /// <summary>
        /// Provjera oduzimanja dva negativna broja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_SubtractOfTwoNegativeNumbers_Subtract()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('4');
            calculator.Press('2');
            calculator.Press('7');
            calculator.Press('M'); //predznak je moguće dodati u bilo kojem trenutku
            calculator.Press('8');
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('5');
            calculator.Press('-');
            calculator.Press('1');
            calculator.Press('6');
            calculator.Press('M');
            calculator.Press(',');
            calculator.Press('8');
            calculator.Press('3');
            calculator.Press('1');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-42765,669", displayState);
        }

        /// <summary>
        /// Provjera raznih operacija i zaokruživanja
        /// </summary>
        [TestMethod]
        public void CheckDisplay_Operations_Result()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press('S');
            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("0,909297427", displayState);
            calculator.Press('+');
            calculator.Press('3');
            calculator.Press('K');
            displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-0,989992497", displayState);
            calculator.Press('=');

            displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-0,08069507", displayState);
        }

        /// <summary>
        /// Provjera raznih operacija i prioriteta operatora
        /// </summary>
        [TestMethod]
        public void CheckDisplay_Operators_Result()
        {
            calculator = Factory.CreateCalculator();
            calculator.Press('2');
            calculator.Press(',');
            calculator.Press('*'); //provjera uzastopnog unosa različitih binarnih operatora (zadnji se pamti)
            calculator.Press('-');
            calculator.Press('+');
            calculator.Press('3');
            calculator.Press('-'); //provjera uzastopnog unosa istog binarnog operatora
            calculator.Press('-');
            calculator.Press('-');
            calculator.Press('2');
            calculator.Press('Q');
            calculator.Press('Q'); //provjera uzastopnog unosa unarnih operatora (svi se izračunavaju)
            calculator.Press('*');
            calculator.Press('2');
            calculator.Press('-');
            calculator.Press('3');
            calculator.Press('C');
            calculator.Press('1');
            calculator.Press('=');

            string displayState = calculator.GetCurrentDisplayState();
            Assert.AreEqual("-23", displayState);
        }
    }
}
