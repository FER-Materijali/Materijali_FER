using System;
using System.Collections.Generic;
using System.Text;
using System.Data;

namespace NTier
{
  // Suèelje koje implementira svaki poslovni objekt
  public interface IBusinessObject
  {
    bool IsDirty { get;}
    BusinessObjectState State { get;}
    void SetParent(IBusinessObjectList parent);
    void Load(IDataReader dr);
    void Delete();
    bool HasBllObject { get;}
    event NeedBllObjectEventHandler NeedBllObject;

    void Edit();
    void CancelChanges();
    void SaveChanges();

    bool InEdit { get;}

    void ClearErrors();

    void Validate(string p);
  }
}
