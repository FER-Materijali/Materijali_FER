namespace Prilagodnik
{
    class Point
    {
        public double X { get; set; }
        public double Y { get; set; }

        public Point(double x, double y)
        {
            X = x;
            Y = y;
        }

        public override string ToString()
        {
            return string.Format("X:{0}, Y:{1}", X, Y);
        }
    }
}
