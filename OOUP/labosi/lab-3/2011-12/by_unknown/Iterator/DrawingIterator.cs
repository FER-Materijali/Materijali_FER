using System.Collections.Generic;

namespace Iterator
{
    interface Iterator<T>
    {
        T Current { get; }
        T Next { get; }
        bool HasNext { get; }
    }

    class VectorDrawingIterator : Iterator<Shape>
    {
        public VectorDrawingIterator(List<Shape> shapes)
        {
            drawing = shapes;
            currentShapeIndex = 0;
        }

        public Shape Current 
        {
            get { return drawing[currentShapeIndex]; }
        }

        public Shape Next 
        {
            get
            {
                currentShapeIndex += 1;
                return drawing[currentShapeIndex - 1];
            }
        }

        public bool HasNext 
        {
            get { return drawing.Count != currentShapeIndex; }
        }

        protected int currentShapeIndex;
        protected List<Shape> drawing;
    }

    class MapDrawingIterator : Iterator<Shape>
    {
        public MapDrawingIterator(Dictionary<int, Shape> shapes)
        {
            drawing = shapes;
            dictEnumerator = shapes.GetEnumerator();
            HasNext = dictEnumerator.MoveNext();
        }

        public Shape Current 
        {
            get { return dictEnumerator.Current.Value; }
        }

        public Shape Next 
        {
            get
            {
                Shape current = dictEnumerator.Current.Value;
                HasNext = dictEnumerator.MoveNext();
                return current;
            }
        }

        public bool HasNext { get; protected set; }

        protected Dictionary<int, Shape>.Enumerator dictEnumerator;
        protected Dictionary<int, Shape> drawing;
    }
}
