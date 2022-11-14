using System;
using System.Collections.Generic;
using System.Linq;

namespace Iterator
{
    class Iterator
    {
        static void Main()
        {
            IEnumerable<Shape> shapes = new List<Shape>()
            {
                new ShapeLineSegment(new Point(1.0, 4.0), new Point(5.0, -8.0)),
                new ShapeLineSegment(new Point(2.0, 3.0), new Point(10.0, -4.0)),
                new ShapeLineSegment(new Point(3.0, 2.0), new Point(15.0, -2.0)),
                new ShapeLineSegment(new Point(4.0, 1.0), new Point(20.0, -1.0))
            };

            DrawingVectorAdapter drawingVector = new DrawingVectorAdapter();
            foreach (var shape in shapes.Reverse())
            {
                drawingVector.AddShape(shape);
            }

            DrawingMapAdapter drawingMap = new DrawingMapAdapter();
            foreach (var shape in shapes)
            {
                drawingMap.AddShape(shape);
            }

            Console.WriteLine("Iterating drawing vector");

            Drawing drawing = drawingVector;
            Iterator<Shape> iterator = drawing.GetIterator();
            while (iterator.HasNext)
            {
                Console.WriteLine(iterator.Next);
            }

            Console.WriteLine("Iterating drawing map");

            drawing = drawingMap;
            iterator = drawing.GetIterator();
            while (iterator.HasNext)
            {
                Console.WriteLine(iterator.Next);
            }
        }
    }
}
