using System;
using System.Collections.Generic;

namespace Prilagodnik
{
    interface IVector<T>
    {
        void Add(T item);
        void Remove(T item);
        int Count { get; }

        T this[int i] { get; }
    }

    class Vector<T> : IVector<T>
    {
        protected List<T> items = new List<T>();

        public void Add(T item)
        {
            Console.WriteLine("Adding a new shape with ID={0} to VectorDrawing", item);
            items.Add(item);
        }

        public void Remove(T item)
        {
            Console.WriteLine("Removing the shape with ID={0} from VectorDrawing", item);
            items.Remove(item);
        }

        public int Count
        {
            get { return items.Count; }
        }

        public T this[int i]
        {
            get
            {
                Console.WriteLine("Getting the shape on index={0} from VectorDrawing", i);
                return items[i];
            }
        }
    }
}
