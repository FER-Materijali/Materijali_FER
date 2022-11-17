using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using UTRL1.Automatons;

namespace UTRL1
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			var inputList = new List<string>();
			string tmpStr;
			while(!string.IsNullOrEmpty(tmpStr = Console.ReadLine())) inputList.Add(tmpStr);

			var input = new List<string[]>();
			foreach(string str in inputList[0].Split('|')) input.Add(str.Split(','));

			inputList.RemoveAt(0);

			var automat = new NKA(inputList);
			foreach(var arr in input) Console.WriteLine(automat.GetStateSets(arr));
		}
	}
}
