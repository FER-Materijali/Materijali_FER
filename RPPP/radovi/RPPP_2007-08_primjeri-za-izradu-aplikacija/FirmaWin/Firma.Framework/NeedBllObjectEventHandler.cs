using System;
using System.Collections.Generic;
using System.Text;

namespace NTier
{
  // Delegat kojim poslovni objekt traži BLL objekt u svrhu validacije
  public delegate IBllObject NeedBllObjectEventHandler();
}
