using System;
using System.Threading;

namespace Singleton
{
    class Program
    {
        static void Main()
        {
            Thread t1 = new Thread(TestSingleton);
            t1.Name = "Thread 1";
            Thread t2 = new Thread(TestSingleton);
            t2.Name = "Thread 2";
            
            t1.Start();
            t2.Start();

            // Ispis 1:
            //Thread 1: Instance is null
            //Thread 2: Instance is null
            //Thread 1: Creating a new instance
            //Thread 1: Returning instance
            //Thread 1: Working...
            //Thread 2: Instance has been created by another thread
            //Thread 2: Returning instance
            //Thread 2: Working...
            //
            // Ispis 2:
            //Thread 1: Instance is null
            //Thread 1: Creating a new instance
            //Thread 1: Returning instance
            //Thread 2: Returning instance
            //Thread 1: Working...
            //Thread 2: Working...
        }

        static void TestSingleton()
        {
            // using singleton
            Singleton.Instance.Work();
        }
    }

    sealed class Singleton
    {
        private static volatile Singleton _instance;
        private static object _syncObject = new Object();

        public static Singleton Instance 
        {
            get 
            {
                if (_instance == null)
                {
                    Console.WriteLine(Thread.CurrentThread.Name + 
                        ": Instance is null");

                    lock (_syncObject)
                    {
                        if (_instance == null)
                        {
                            Console.WriteLine(Thread.CurrentThread.Name + 
                                ": Creating a new instance");
                            _instance = new Singleton();
                        }
                        else
                        {
                            Console.WriteLine(Thread.CurrentThread.Name + 
                                ": Instance has been created by another thread");
                        }
                    }
                }

                Console.WriteLine(Thread.CurrentThread.Name + 
                    ": Returning instance");
                return _instance; 
            }
        }

        private Singleton() 
        { }

        public void Work()
        {
            Console.WriteLine(Thread.CurrentThread.Name + ": Working...");
        }
    }
}
