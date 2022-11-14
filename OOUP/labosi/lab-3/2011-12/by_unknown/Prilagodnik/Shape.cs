using System;

namespace Prilagodnik
{
    abstract class Shape
    {
        private static int shapeCount = 0;

        public int Id { get; protected set; }
        public Point Position { get; protected set; }

        public abstract void Translate(Point point);

        public Shape(Point position)
        {
            shapeCount++;
            Position = position;
            Id = shapeCount;
        }

        public override bool Equals(object obj)
        {
            Shape shape = obj as Shape;

            if (shape == null)
            {
                return false;
            }

            return Id == shape.Id;
        }

        public override int GetHashCode()
        {
            return Id.GetHashCode();
        }

        public override string ToString()
        {
            return Id.ToString();
        }
    }

    class ShapeLineSegment : Shape
    {
        public Point StartPosition
        {
            get { return Position; }
        }

        public Point EndPosition { get; protected set; }

        public ShapeLineSegment(Point start, Point end)
            : base(start)
        {
            EndPosition = end;
        }

        public override void Translate(Point point)
        {
            Console.WriteLine("Translating line segment to " + point);
            EndPosition.X += point.X - StartPosition.X;
            EndPosition.Y += point.Y - StartPosition.Y;
            StartPosition.X = point.X;
            StartPosition.Y = point.Y;
        }
    }
}
