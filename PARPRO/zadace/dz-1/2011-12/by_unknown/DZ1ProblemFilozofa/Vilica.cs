using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DZ1ProblemFilozofa
{
    enum StanjeVilice
    {
        prljavo,
        cisto
    };

    class Vilica
    {
        StanjeVilice stanje = StanjeVilice.prljavo;
        public StanjeVilice Stanje
        {
            get { return this.stanje; }
        }
        bool imamVilicu = false;
        public bool ImamVilicu
        {
            get { return this.imamVilicu; }
            set { this.imamVilicu = value; }
        }

        public Vilica(bool imamVilicu)
        {
            this.imamVilicu = imamVilicu;
        }

        public void OcistiVilicu()
        {
            stanje = StanjeVilice.cisto;
        }

        public void ZaprljajVilicu()
        {
            stanje = StanjeVilice.prljavo;
        }
    }
}
