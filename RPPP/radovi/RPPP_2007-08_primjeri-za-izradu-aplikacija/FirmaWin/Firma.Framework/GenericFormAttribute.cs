using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;

namespace NTier
{
  // Atribut kojim se oznaèavaju svojstva koja æe se pokazati na univerzalnoj formi.
  [AttributeUsage(AttributeTargets.Property)]
  public sealed class GenericFormAttribute : Attribute
  {
    #region Vars
    private string displayName = string.Empty;
    private string displayFormat = string.Empty;
    private HorizontalAlignment ha = HorizontalAlignment.Left;
    #endregion

    #region Constructors
    public GenericFormAttribute(string displayName)
    {
      this.displayName = displayName;
    }

    public GenericFormAttribute(string displayName, string displayFormat)
      : this(displayName)
    {
      this.displayFormat = displayFormat;
    }

    public GenericFormAttribute(string displayName, HorizontalAlignment textAlignment)
      : this(displayName)
    {
      this.ha = textAlignment;
    }

    public GenericFormAttribute(string displayName, string displayFormat, HorizontalAlignment textAlignment)
      : this(displayName, displayFormat)
    {
      this.ha = textAlignment;
    }
    #endregion

    #region Properties
    public string DisplayName
    {
      get { return displayName; }
    }

    public string DisplayFormat
    {
      get { return displayFormat; }
    }

    public HorizontalAlignment TextAlignment
    {
      get { return ha; }
    }
    #endregion
  }
}
