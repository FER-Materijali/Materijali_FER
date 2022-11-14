using System;
using System.Drawing;
using System.Windows.Forms;

namespace raytracing
{
   /// <summary>
   /// Klasa koja stvara realisticnu sliku pomocu ray tracinga. Svi potrebni
   /// parametri unose se pomocu datoteke Input.txt.
   /// </summary>
   public class Picture : Form
   {
      private int screenResolution;
      private Scene scene;
      private Screen screen;
      private Ray ray;
      private Point eyePosition;

      /// <summary>
      /// handler za gasenje prozora
      /// </summary>
      /// <param name="sender">tko salje</param>
      /// <param name="e">dogadaj</param>
      void Application_ApplicationExit ( object sender, EventArgs e )
      {
         Environment.Exit(0);
      }

      /// <summary>
      /// Konstruktor koji pomocu klase FileReader iz datoteke Input.txt uzima i
      /// postavlja sve potebne parametre za crtanje slike : poziciju oka, rezoluciju
      /// ekrana (slike), velicinu ekrana, poziciju svijetla u sceni, broj objekata u
      /// sceni, te parametre svih kugli u sceni.
      /// </summary>
      public Picture ()
      {
         Application.ApplicationExit += new EventHandler(Application_ApplicationExit);
         this.Paint += new PaintEventHandler(Picture_Paint);
         FileReader fileReader = new FileReader("Input.txt");
         fileReader.read();
         this.ClientSize = new Size(fileReader.getScreenResolution(), fileReader.getScreenResolution());
         eyePosition = fileReader.getEyePosition();
         screenResolution = fileReader.getScreenResolution();
         screen = new Screen(fileReader.getScreenSize(), screenResolution);
         scene = new Scene(fileReader.getLightPosition(), fileReader.getNumberOfObjects(), fileReader.getSphereParameters());
      }

      void Picture_Paint ( object sender, PaintEventArgs e )
      {
         for(int j = 0; j < screenResolution; j++)
         {
            for(int i = 0; i < screenResolution; i++)
            {

               Point screenPoint = screen.getPoint(i, j);
               ray = new Ray(eyePosition, screenPoint);

               ColorVector colors = scene.traceRay(ray, 1);
               Color c = Color.FromArgb(Convert.ToInt32(255 * colors.getRed()), Convert.ToInt32(255 * colors.getGreen()), Convert.ToInt32(255 * colors.getBlue()));

               e.Graphics.DrawRectangle(new Pen(c), i, j, 1, 1);
            }
         }
      }

      private void InitializeComponent()
      {
          this.SuspendLayout();
          // 
          // Picture
          // 
          this.ClientSize = new System.Drawing.Size(338, 262);
          this.Name = "Picture";
          this.Load += new System.EventHandler(this.Picture_Load);
          this.ResumeLayout(false);

      }

      private void Picture_Load(object sender, EventArgs e)
      {

      }
   }
}