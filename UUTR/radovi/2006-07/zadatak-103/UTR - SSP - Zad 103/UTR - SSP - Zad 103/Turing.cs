using System;
using System.Collections;

namespace ProjektAutomati
{
	public class Turing
	{
		public string[] Stanja;
		public string[] ZnakoviTrake;
		public string[] PrazniZnak;
		public string[] Ulazi;
		public string[] Pocetno;
		public string[] Prihvatljiva;
		public string[] Traka= new string[100];
		public string temp;
		
		Hashtable Tablica = new Hashtable();
	
	

		public Turing(string prvi, string drugi)
		{
			this.Stanja = new string[] {"q0","q1","q2","q3","q4","q5","q6","q7","q8","q9"};
			this.ZnakoviTrake = new string[] {"0","1","+","N","J","B"};
			this.PrazniZnak = new string[] {"B"};
			this.Ulazi = new string[] {"0","1","+"};
			this.Pocetno = new string[] {"q0"};
			this.Prihvatljiva = new string[] {"q9"};
			
			temp=prvi + "+" + drugi;
			
			
			for(int k=0; k < this.Traka.Length; k++)
			{
				this.Traka[k]="B";
			}

			int i=20;
			foreach(char c in temp)
			{
				this.Traka[i]=Convert.ToString(c);
				i++;
			}
			Tablica.Add("q0,0","q0,0,R");
			Tablica.Add("q0,1","q0,1,R");
			Tablica.Add("q0,+","q0,+,R");
			Tablica.Add("q0,N","q0,N,R");
			Tablica.Add("q0,J","q0,J,R");
			Tablica.Add("q0,B","q1,B,L");

			Tablica.Add("q1,0","q2,B,L");
			Tablica.Add("q1,1","q3,B,L");
			Tablica.Add("q1,+","q7,B,L");

			Tablica.Add("q2,0","q2,0,L");
			Tablica.Add("q2,1","q2,1,L");
			Tablica.Add("q2,+","q4,+,L");

			Tablica.Add("q3,0","q3,0,L");
			Tablica.Add("q3,1","q3,1,L");
			Tablica.Add("q3,+","q5,+,L");

			Tablica.Add("q4,0","q0,N,R");
			Tablica.Add("q4,1","q0,J,R");
			Tablica.Add("q4,N","q4,N,L");
			Tablica.Add("q4,J","q4,J,L");
			Tablica.Add("q4,B","q0,N,R");
			
			Tablica.Add("q5,0","q0,J,R");
			Tablica.Add("q5,1","q6,N,L");
			Tablica.Add("q5,N","q5,N,L");
			Tablica.Add("q5,J","q5,J,L");
			Tablica.Add("q5,B","q0,J,R");

			Tablica.Add("q6,0","q0,1,R");
			Tablica.Add("q6,1","q6,0,L");
			Tablica.Add("q6,B","q0,1,R");
			
			Tablica.Add("q7,0","q7,0,L");
			Tablica.Add("q7,1","q7,1,L");
			Tablica.Add("q7,N","q7,0,L");
			Tablica.Add("q7,J","q7,1,L");
			Tablica.Add("q7,B","q8,B,R");

			Tablica.Add("q8,0","q8,B,R");
			Tablica.Add("q8,1","q9,1,L");
			Tablica.Add("q8,B","q9,0,L");
			
			
		}


		public class Funkcija
		{
			public string SljedeceStanje;
			public string UpisanZnak;
			public string  Pomak;
			public string[] temp1;
			

			public Funkcija(string sljedece)
			{
				
				temp1 = sljedece.Split(new char [] {','});
				this.SljedeceStanje = temp1[0];
				this.UpisanZnak = temp1[1];
				this.Pomak = temp1[2];
			}	
		}

		public void Radi(string pocetno)
		{
			int j=20;

			string StanjeTemp;
			string Temp;
			string PomakTemp;
			string UpisanZnakTemp;

			Temp = Convert.ToString(Tablica[pocetno + "," + Traka[j]]);
			Funkcija f = new Funkcija(Temp);
			StanjeTemp = f.SljedeceStanje;
			PomakTemp = f.Pomak;
			UpisanZnakTemp = f.UpisanZnak;

			while(1==1)
			{
				Traka[j]=UpisanZnakTemp;

				if(PomakTemp=="R")
					j++;
				else if(PomakTemp=="L")
					j--;
				if(StanjeTemp=="q9")
					break;

				Temp = Convert.ToString(Tablica[StanjeTemp + "," + Traka[j]]);
				Funkcija f1 = new Funkcija(Temp);
				StanjeTemp = f1.SljedeceStanje;
				PomakTemp = f1.Pomak;
				UpisanZnakTemp = f1.UpisanZnak;
			}
		}
	}
	
}
