namespace Prilagodnik
{
    class Prilagodnik
    {
        static void Main()
        {
            Drawing drawing = new DrawingVectorAdapter();
            Shape shape = new ShapeLineSegment(new Point(1.0, 1.0), new Point(5.0, -8.0));
            drawing.AddShape(shape);
            drawing.GetShape(shape.Id).Translate(new Point(4.0, 2.0));
            drawing.RemoveShape(shape.Id);
        }
    }
}
