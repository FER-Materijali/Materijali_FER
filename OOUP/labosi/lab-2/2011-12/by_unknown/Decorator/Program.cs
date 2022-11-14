using System;
using System.IO;

namespace Decorator
{
    class Program
    {
        static void Main(string[] args)
        {
            Param param = new Param()
            { 
                Table = "Person", 
                Column = "Name", 
                Key = "Id" 
            };

            DataBase db = new MyDataBase();
            LogDecorator logDecorator = new LogDecorator(db);
            ExceptionDecorator exceptionDecorator = 
                new ExceptionDecorator(logDecorator);

            logDecorator.Query(param);

            try
            {
                exceptionDecorator.Query(param);
            }
            catch (DataBaseException e)
            {
                Console.WriteLine("Error: " + e.Message);
            }
        }
    }

    public struct Param
    {
        public string Table { get; set; }
        public string Column { get; set; }
        public string Key { get; set; }

        public override string ToString()
        {
            return String.Format("Table: {0}; Column: {1}; Key: {2}",
                Table, Column, Key);
        }
    }

    abstract class DataBase
    {
        public abstract int Query(Param p);
    }

    class MyDataBase : DataBase
    {
        public override int Query(Param p)
        {
            return new Random().Next(-1, 1);
        }
    }

    abstract class Decorator : DataBase
    {
        protected DataBase _dataBase;

        public Decorator(DataBase dataBase)
        {
            _dataBase = dataBase;
        }
    }

    class LogDecorator : Decorator
    {
        private string LogFileName { get; set; }

        public LogDecorator(DataBase dataBase, string fileName = @"var\tmp\mybase.log")
            : base(dataBase)
        {
            LogFileName = fileName;
        }

        public override int Query(Param p)
        {
            int queryResult = _dataBase.Query(p);

            using (StreamWriter sw = File.AppendText(LogFileName))
            {
                sw.WriteLine(p);
                sw.WriteLine("Query result: " + queryResult);
                sw.WriteLine();
            }

            return queryResult;
        }
    }

    class ExceptionDecorator : Decorator
    {
        public ExceptionDecorator(DataBase dataBase)
            : base(dataBase)
        { }

        public override int Query(Param p)
        {
            int queryResult = _dataBase.Query(p);

            if (queryResult < 0)
            {
                throw new DataBaseException();
            }

            return queryResult;
        }
    }

    public class DataBaseException : Exception
    {
        public override string Message
        {
            get  { return "Database Exception"; }
        }
    }
}
