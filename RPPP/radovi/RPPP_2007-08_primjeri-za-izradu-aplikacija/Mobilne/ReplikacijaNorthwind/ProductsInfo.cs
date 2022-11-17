using System;

namespace NorthwindCE_2556
{
	/// <summary>
	/// Summary description for ProductsInfo.
	/// </summary>
	internal class ProductDataObject 
	{
		private int _id;
		private string  _name;
		private string  _price;

		public ProductDataObject( int idValue,  string  nameValue,  string  priceValue) 
		{
			_id = idValue;
			_name = nameValue;
			_price = priceValue;
		}
		public int ID  
		{
			get 
			{
				return _id;
			}
		}

		public string  Name  
		{
			get 
			{
				return _name;
			}
		}

		public string  UnitPrice  
		{
			get 
			{
				return _price;
			}
		}
	}
}
