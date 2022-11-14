using System;

namespace Prilagodnik
{
    abstract class Drawing
    {
        public abstract void AddShape(Shape shape);
        public abstract void RemoveShape(int id);
        public abstract Shape GetShape(int id);
        public abstract int ShapeCount { get; }
    }

    class DrawingVectorAdapter : Drawing
    {
        protected Vector<Shape> shapes = new Vector<Shape>();

        public override void AddShape(Shape shape)
        {
            Console.WriteLine("Adding a new shape with ID={0} to VectorAdapter", shape.Id);
            shapes.Add(shape);
        }

        public override void RemoveShape(int id)
        {
            Console.WriteLine("Removing the shape with ID={0} from VectorAdapter", id);
            shapes.Remove(GetShape(id));
        }

        public override Shape GetShape(int id)
        {
            Console.WriteLine("Getting the shape with ID={0} from VectorAdapter", id);

            for (int i = 0; i < shapes.Count; i++)
            {
                if (shapes[i].Id == id)
                {
                    return shapes[i];
                }
            }

            return null;
        }

        public override int ShapeCount
        {
            get { return shapes.Count; }
        }
    }
}
