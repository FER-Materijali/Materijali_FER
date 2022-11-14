using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOuP2lab5
{
    abstract class Observer
    {
        protected SlijedBrojeva slijedBrojeva;
        public Observer(SlijedBrojeva sb) 
        {
            slijedBrojeva = sb;
            slijedBrojeva.Attach(this);
        }
        public abstract void Update();
    }
}
