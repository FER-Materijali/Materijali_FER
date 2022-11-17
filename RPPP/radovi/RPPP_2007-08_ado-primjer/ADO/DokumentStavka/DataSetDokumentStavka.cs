using System;

namespace MasterDetail {


  partial class DataSetDokumentStavka
  {

    partial class DokumentDataTable
    {





      public override void EndInit()
      {
        base.EndInit();
        ColumnChanging += SampleColumnChangingEvent;
      }

      public void SampleColumnChangingEvent(object sender, System.Data.DataColumnChangeEventArgs e)
      {
        if (e.Column.ColumnName == PostoPorezColumn.ColumnName)
        {
          if (Decimal.Parse(e.ProposedValue.ToString()) <= 0)
          {
            e.Row.SetColumnError("PostoPorez", "Cijena mora biti veća od 0");

          }
          else
          {
            e.Row.SetColumnError("PostoPorez", "");
          }
        }
      }

    }
  }
}
