using System;

namespace UnosArtikala {
    
    
  public partial class DataSetArtikli {
    partial class ArtiklDataTable
    {

      public override void EndInit()
      {
        base.EndInit();
        ColumnChanging += ArtiklColumnChangingEvent;
        ColumnChanged += ArtiklColumnChangedEvent;
      }

      // Validacija se izvodi pri promjeni vrijednosti stupca u tablici Artikl

      public void ArtiklColumnChangingEvent(object sender, System.Data.DataColumnChangeEventArgs e)
      {
        if (e.Column.ColumnName == CijArtiklaColumn.ColumnName)
        {
          if (Decimal.Parse(e.ProposedValue.ToString()) < 0)
          {
            e.Row.SetColumnError("CijArtikla", "Cijena mora biti veća ili jednaka 0");
            
          }
          else
          {
            e.Row.SetColumnError("CijArtikla", "");
          }
        }

        if (e.Column.ColumnName == SifArtiklaColumn.ColumnName)
        {
          if (e.ProposedValue != DBNull.Value)
          {
            if (Decimal.Parse(e.ProposedValue.ToString()) <= 0)
            {
              e.Row.SetColumnError("SifArtikla", "Šifra mora biti veća od 0");
            }
            else
            {
              e.Row.SetColumnError("SifArtikla", "");
            }
          }
        }
      }

      // Dogadja se nakon promjene vrijednosti stupca - završavamo uredjivanje
      // Time promjene pohranjujemo u dataset, ali HasErrors je i dalje true ako pogreske postoje
      
      public void ArtiklColumnChangedEvent(object sender, System.Data.DataColumnChangeEventArgs e)
      {
        e.Row.EndEdit();
      }


    }
  }
}
