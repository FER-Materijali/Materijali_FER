using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using System.Reflection;

namespace Firma
{
  public static class Utils
  {
    // Postavljanje NULL vrijednosti u property. 
    // Koristi se za problem koji osnovih .NET kontrola 
    // (ne reagiraju na izmjenu vrijednosti kada se upisuje NULL).
    public static void SetNull(Control c, string bindedProperty, object businessObject)
    {
      // Naði definiciju data-bindinga
      Binding b = c.DataBindings[bindedProperty];
      if (b != null)
      {
        // Naði property na poslovnom objektu na koji sam bindan
        PropertyInfo p = businessObject.GetType().GetProperty(b.BindingMemberInfo.BindingField, 
                                                              BindingFlags.Instance | BindingFlags.Public);
        if (p != null) 
        {
          // Postavi null u property
          if (p.PropertyType.Equals(typeof(string)))
          {
            p.SetValue(businessObject, string.Empty, null);
          }
          else
          {
            p.SetValue(businessObject, null, null);
          }
        }
        else
        {
          throw new ArgumentException();
        }
      }
      else
      {
        throw new ArgumentException();
      }
    }
  }
}
