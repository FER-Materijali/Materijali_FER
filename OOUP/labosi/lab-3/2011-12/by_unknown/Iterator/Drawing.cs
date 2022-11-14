using System.Collections.Generic;

namespace Iterator
{
    abstract class Drawing
    {
        public abstract void AddShape(Shape shape);
        public abstract void RemoveShape(int id);
        public abstract int ShapeCount { get; }
        public abstract Iterator<Shape> GetIterator();
    }

    class DrawingVectorAdapter : Drawing
    {
        protected List<Shape> shapes = new List<Shape>();

        public override void AddShape(Shape shape)
        {
            shapes.Add(shape);
        }

        public override void RemoveShape(int id)
        {
            for (int i = 0; i < shapes.Count; i++)
            {
                if (shapes[i].Id == id)
                {
                    shapes.Remove(shapes[i]);
                }
            }
        }

        public override int ShapeCount
        {
            get { return shapes.Count; }
        }

        public override Iterator<Shape> GetIterator()
        {
            return new VectorDrawingIterator(shapes);
        }
    }

    class DrawingMapAdapter : Drawing
    {
        private Dictionary<int, Shape> shapes = new Dictionary<int, Shape>();

        public override void AddShape(Shape shape)
        {
            shapes.Add(shape.Id, shape);
        }

        public override void RemoveShape(int id)
        {
            shapes.Remove(id);
        }

        public override int ShapeCount
        {
            get { return shapes.Count; }
        }

        public override Iterator<Shape> GetIterator()
        {
            return new MapDrawingIterator(shapes);
        }
    }
}
