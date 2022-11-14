using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Factory
{
    class Program
    {
        static void Main()
        {
            string testObjects = String.Join(Environment.NewLine, "1", "2", "3", "2", "1", "3");
            byte[] byteArray = Encoding.ASCII.GetBytes(testObjects);
            StreamReader stream = new StreamReader(new MemoryStream(byteArray));

            ICollection<Object> drawing = new List<Object>();
            LoadDrawing(stream, drawing);

            foreach (var obj in drawing)
            {
                Console.WriteLine(obj.Load());
            }
        }

        static void LoadDrawing(StreamReader inputStream, ICollection<Object> drawing)
        {
            while (!inputStream.EndOfStream)
            {
                string line = inputStream.ReadLine();
                Object obj = ObjectFactory.CreateObject(line[0]);
                drawing.Add(obj);
            }
        }
    }

    abstract class Object
    {
        public abstract int Load();
    }

    class Object1 : Object
    {
        public override int Load()
        {
            return 1;
        }
    }

    class Object2 : Object
    {
        public override int Load()
        {
            return 2;
        }
    }

    class Object3 : Object
    {
        public override int Load()
        {
            return 3;
        }
    }

    class ObjectFactory
    {
        public static Object CreateObject(char obj)
        {
            switch (obj)
            {
                case '1':
                    return new Object1();
                case '2':
                    return new Object2();
                case '3':
                    return new Object3();
                default:
                    return null;
            }
        }
    }
}
