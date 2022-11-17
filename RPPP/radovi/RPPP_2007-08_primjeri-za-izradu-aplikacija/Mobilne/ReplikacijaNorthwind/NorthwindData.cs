using System;
using System.Text;
using System.Windows.Forms;
using System.Data;
using System.Data.SqlServerCe;

namespace NorthwindCE_2556
{
	//The NorthwindData class contains information and objects to work with local data, including a SqlCEConnection,
	//a dataset, connection strings, and error handling. Separating the data and data logic as a separate class from the 
	//form is a good design practice.
	internal class NorthwindData
	{
		private static NorthwindData northwind = null;
		private string  local_DatabaseFile;
		private string  local_ConnString;
		private SqlCeConnection cnNorthwind;
		private DataSet dsNorthwind;

		private NorthwindData()
		{
			local_DatabaseFile = @"My Documents\NorthwindDemo.sdf";
			//Construct the local connecting string.
			local_ConnString = "Data Source= " + local_DatabaseFile;
			cnNorthwind = new SqlCeConnection(local_ConnString);
			dsNorthwind = new DataSet("Northwind");
		}

		public void Close() 
		{
			if ( cnNorthwind.State == ConnectionState.Open ) 
			{
				cnNorthwind.Close();
			}
		}

		public static NorthwindData GetInstance() 
		{
			//Instead of recreating this class each time, return an existing
			//instance of the class.
			if ( northwind == null ) 
			{
				northwind = new NorthwindData();
			}
			return northwind;
		}

		public SqlCeConnection NorthwindConnection  
		{
			get 
			{
				return cnNorthwind;
			}
		}

		public DataSet NorthwindDataSet  
		{
			get 
			{
				return dsNorthwind;
			}
		}

		public string  LocalDatabaseFile  
		{
			get 
			{
				return local_DatabaseFile;
			}
		}

		public string  LocalConnString  
		{
			get 
			{
				return local_ConnString;
			}
		}

		public static void ShowErrors(SqlCeException e)
		{
			SqlCeErrorCollection errors = e.Errors;
			Exception inner = e.InnerException;
			StringBuilder builder = new StringBuilder();

			if (inner != null)
			{
				MessageBox.Show(inner.ToString(), "Inner Exception");
			}

			foreach (SqlCeError error in errors)
			{
				builder.Append("\r Error Code: " + error.HResult.ToString("X"));
				builder.Append("\r Message   : " + error.Message);
				builder.Append("\r Minor Err.: " + error.NativeError);
				builder.Append("\r Source    : " + error.Source);

				foreach (int param in error.NumericErrorParameters)
				{
					if (param != 0)
					{
						builder.Append("\r Num. Par. : " + param.ToString());
					}
				}

				foreach (string errPar in error.ErrorParameters)
				{
					if (errPar != String.Empty)
					{
						builder.Append("\r Err. Par. : " + errPar);
					}					
				}
				
				if (builder.ToString().Length > 0)
				{
					MessageBox.Show(builder.ToString(), "SqlCE Error");
				}
				builder.Remove(0, builder.Length);
			}
		}
	}
}
