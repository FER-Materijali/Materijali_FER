using System;
using System.Collections.Generic;
using System.Text;
using System.ComponentModel;

namespace Firma
{
  // Suèelje preko kojega FormToolbar kontrola zna komunicirati 
  // s formom na kojoj se nalazi
  public interface IBusinessObjectForm : INotifyPropertyChanged
  {
    // Navigacija
    void First();
    void Previous();
    void Next();
    void Last();

    // Manipulacija podacima
    void New();
    void Edit();
    void Delete();
    void SaveChanges();
    void CancelChanges();

    // Svojstva koja odreðuju ponašanje i izgled toolbar-a
    bool InEditMode { get;}
    bool CanDoFirst { get;}
    bool CanDoPrevious { get;}
    bool CanDoNext { get;}
    bool CanDoLast { get;}
    bool CanDoNew { get;}
    bool CanDoEdit { get;}
    bool CanDoDelete { get;}
    bool CanDoSaveChanges { get;}
    bool CanDoCancelChanges { get;}

    // Forma odreðuje trenutak kada treba osvježiti toolbar
    event EventHandler NeedToolbarRefresh;
  }
}
