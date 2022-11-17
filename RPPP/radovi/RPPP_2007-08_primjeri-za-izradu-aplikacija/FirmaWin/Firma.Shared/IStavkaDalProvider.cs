using System;
using System.Collections.Generic;
using System.Text;

namespace Firma
{
  // Suèelje koje implementira DAL objekt stavaka.
  // Potrebno je kako bi zaglavlje znalo uèitati svoje stavke.
  public interface IStavkaDalProvider
  {
    StavkaList FetchAll(int idDokumenta);
  }
}
