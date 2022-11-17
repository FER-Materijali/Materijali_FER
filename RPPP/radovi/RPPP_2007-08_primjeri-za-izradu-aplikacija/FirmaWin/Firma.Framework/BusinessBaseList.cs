using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;
using System.Data;
using System.Collections;

namespace NTier
{
  // Osnovna klasa liste poslovnih objekata
  public abstract class BusinessBaseList<T> : BindingList<T>, IBusinessObjectList
      where T : IBusinessObject
  {
    #region Constructors & Init
    protected BusinessBaseList()
    {
    }
    #endregion

    #region Insert
    // Dodaje objekt u listu
    protected override void InsertItem(int index, T item)
    {
      item.SetParent(this);
      base.InsertItem(index, item);
    }
    #endregion

    #region Delete
    // Spremište "obrisanih" poslovnih objekata
    private List<T> deletedItems = new List<T>();

    // Uklanja objekt iz liste
    protected override void RemoveItem(int index)
    {
      T item = this[index];
      if (item.State != BusinessObjectState.New)
      {
        item.Delete();
        deletedItems.Add(item);
      }

      base.RemoveItem(index);
    }
    #endregion

    #region Changes
    // Stvara listu izmijenjenih poslovnih objekata
    public List<T> GetChanges()
    {
      List<T> changes = new List<T>();
      foreach (T item in deletedItems)
      {
        changes.Add(item);
      }
      foreach (T item in this)
      {
        if (item.IsDirty || item.State == BusinessObjectState.New)
          changes.Add(item);
      }

      return changes;
    }
    #endregion

    #region Dirty
    // Odreðuje da li se lista mijenjala (ili njeni elementi)
    public bool IsDirty
    {
      get
      {
        if (deletedItems.Count > 0)
          return true;

        foreach (T item in this)
          if (item.IsDirty)
            return true;

        return false;
      }
    }
    #endregion

    #region IEditableBusinessObjectList Members
    // Stvara listu izmijenjenih poslovnih objekata
    IList IBusinessObjectList.GetChanges()
    {
      return this.GetChanges();
    }
    #endregion
  }
}
