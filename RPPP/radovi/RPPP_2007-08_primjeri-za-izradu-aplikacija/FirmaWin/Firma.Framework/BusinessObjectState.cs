using System;
using System.Collections.Generic;
using System.Text;

namespace NTier
{
  // Stanja u kojima može biti poslovni objekt
  public enum BusinessObjectState
  {
    Unmodified,
    New,
    Modified,
    Deleted
  }
}
