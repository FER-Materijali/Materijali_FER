using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace UTRL1.Automatons
{
	public class NKA
	{
		private List<string> allowedStates = new List<string>();
		private List<string> allowedSimbols = new List<string>();
		private List<string> acceptedStates = new List<string>();
		private string initState;

		private Dictionary<string,string[]> transitionFunction = new Dictionary<string, string[]>();

		public NKA (List<string> definition)
		{
			this.allowedStates.AddRange(definition[0].Split(','));
			this.allowedSimbols.AddRange(definition[1].Split(','));
			this.acceptedStates.AddRange(definition[2].Split(','));

			this.initState = definition[3];

			definition.RemoveRange(0,4);

			foreach(string funDef in definition) transitionFunction.Add(funDef.Split(new string[] {"->"}, StringSplitOptions.None)[0], funDef.Split(new string[] {"->"}, StringSplitOptions.None)[1].Split(','));
		}

		public string GetStateSets(string[] inputArray) {
			string returnString = string.Empty;

			var currentStates = new List<string>();
			var nextStates = new List<string>();

			currentStates.Add(this.initState);
			if(this.transitionFunction.ContainsKey(this.initState + ",$"))
				currentStates.AddRange(this.transitionFunction[this.initState + ",$"]);

			currentStates.Sort();

			foreach(string input in inputArray) {
				foreach(string state in currentStates) {
					if(state == "#") break;
					if(this.transitionFunction.ContainsKey(state + "," + input)) {
						nextStates.AddRange(this.transitionFunction[state + "," + input]);
						foreach(string eState in this.transitionFunction[state + "," + input]) {
							if(this.transitionFunction.ContainsKey(eState + ",$")) {
								nextStates.AddRange(this.transitionFunction[eState + ",$"]);
							}
						}
					}
				}

				if(nextStates.Count == 0) nextStates.Add("#");

				nextStates.Sort();

				returnString += string.Join(",", currentStates) + "|";

				currentStates.Clear();
				currentStates.AddRange(nextStates);
				nextStates.Clear();
			}

			returnString += string.Join(",", currentStates);

			return returnString;
		}
	}
}

