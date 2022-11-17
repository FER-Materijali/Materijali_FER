using System;
using System.Windows.Forms;

class Pozdrav
{
  static void CSharp(string[] args)
  { 
    MessageBox.Show("Pozdrav sa stringom!"); 
  }
  public static void CSharp()
  {
    MessageBox.Show("Pozdrav!");
  }



}


class Proba
{
  static void Main()
  {
    Console.WriteLine("Proba!");
    Pozdrav.CSharp();
  }
}