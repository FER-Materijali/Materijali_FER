using System;
using System.Collections.Generic;
using System.Text;
using System.Collections;

namespace NTier
{
  // Suèelje koje implementira svaki BLL objekt
  public interface IBllObject
  {
    void Validate(object businessObject, string propertyName);
    void SaveChanges(IList changes);
  }
}
