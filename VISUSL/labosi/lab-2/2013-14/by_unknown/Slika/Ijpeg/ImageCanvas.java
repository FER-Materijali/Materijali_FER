import java.applet.Applet;
import java.awt.*;
import java.awt.image.*;
import java.io.PrintStream;

public class ImageCanvas extends Canvas
{

    ImageCanvas(Applet applet1)
    {
        cout = 222;
        applet = applet1;
        drawFlag = false;
        image = null;
        imageUpdate = false;
        selectable = false;
    }

    ImageCanvas(Applet applet1, Image image1, boolean flag)
    {
        cout = 222;
        applet = applet1;
        drawFlag = false;
        image = image1;
        imageUpdate = true;
        selectable = flag;
    }

    public void drawn()
    {
        drawFlag = true;
        image2pixels();
    }

    public void setImage(Image image1)
    {
        image = image1;
        repaint();
    }

    public Dimension getImageSize()
    {
        if(image != null)
            return new Dimension(width, height);
        else
            return new Dimension(0, 0);
    }

    public boolean selectable()
    {
        return selectable;
    }

    public void setSelectable(boolean flag)
    {
        selectable = flag;
        currx = curry = 0;
        repaint();
    }

    public void select(int i, int j)
    {
        if(selectable)
        {
            currx = i;
            curry = j;
            repaint();
        }
    }

    public Point getSelection()
    {
        return new Point(currx, curry);
    }

    public void setImageValues(float af[], int i, int j, MatrixCanvas matrixcanvas, int k)
    {
        setImageValues(af, i, j, 0, 0, matrixcanvas, k);
    }

    public void setImageValues(float af[], int i, int j, int k, int l, MatrixCanvas matrixcanvas, int i1)
    {
        QMatrix = matrixcanvas;
        disp = i1;
        values = af;
        width = i;
        height = j;
        xb = width / 8;
        yb = height / 8;
        if(k != 0 && l != 0)
        {
            pixels = normalize(values, i, j, k, l);
        } else
        {
            pixels = new int[width * height];
            int j1 = 0;
            for(int k1 = 0; k1 < height; k1++)
            {
                for(int l1 = 0; l1 < width; l1++)
                    pixels[j1] = (int)af[j1++] | 0xff000000;

                if(disp == 1 && (k1 % height) / 4 == 0)
                    QMatrix.setinfo(cout++, 0.0F);
            }

        }
        System.out.println("creating image " + width + " x " + height);
        image = createImage(new MemoryImageSource(width, height, ColorModel.getRGBdefault(), pixels, 0, width));
        repaint();
    }

    public float getImageValue(int i, int j)
    {
        if(image != null)
            return values[j * width + i];
        else
            return 0.0F;
    }

    public void getBlockValues(float af[], int i, int j)
    {
        int k = 0;
        for(int l = 0; l < 8; l++)
        {
            for(int i1 = 0; i1 < 8; i1++)
                af[k++] = values[j * 64 * xb + i * 8 + l * 8 * xb + i1];

        }

    }

    public void getBlockPixels(float af[], int i, int j)
    {
        int k = 0;
        for(int l = 0; l < 8; l++)
        {
            for(int i1 = 0; i1 < 8; i1++)
                af[k++] = (pixels[j * 64 * xb + i * 8 + l * 8 * xb + i1] & 0xff) - 128;

        }

    }

    public void paint(Graphics g)
    {
        bounds();
        System.out.println("drawing canvas");
        if(image != null)
        {
            g.drawImage(image, 0, 0, this);
            width = image.getWidth(applet);
            height = image.getHeight(applet);
            System.out.println(" drawing image " + width + " x " + height);
            if(imageUpdate && drawFlag)
            {
                image2pixels();
                imageUpdate = false;
            }
            if(selectable && selected)
            {
                Color color = g.getColor();
                g.setColor(Color.yellow);
                g.drawRect(currx * 8, curry * 8, 8, 8);
                g.setColor(color);
            }
        }
    }

    public void initdraw()
    {
        selected = false;
        repaint();
    }

    public void rectdraw()
    {
        selected = true;
        repaint();
    }

    public boolean mouseDown(Event event, int i, int j)
    {
        System.out.println("Image canvas: mouse click " + i + "," + j);
        if(selectable)
        {
            currx = i / 8;
            curry = j / 8;
            System.out.println("  (" + currx + "," + curry + ")");
            repaint();
            return false;
        } else
        {
            return true;
        }
    }

    private void image2pixels()
    {
        if(image != null)
        {
            System.out.println("pixels from image (" + width + " x " + height + ")");
            pixels = new int[width * height];
            PixelGrabber pixelgrabber = new PixelGrabber(image, 0, 0, width, height, pixels, 0, width);
            try
            {
                System.out.println("grabbing pixels...");
                pixelgrabber.grabPixels();
                System.out.println("done grabbing pixels");
            }
            catch(InterruptedException _ex)
            {
                System.err.println("interrupted waiting for pixels!");
                return;
            }
            System.out.println(" => got pixels " + width * height);
            values = new float[width * height];
            int i = 0;
            for(int j = 0; j < height; j++)
            {
                for(int k = 0; k < width; k++)
                    values[i] = pixels[i++] & 0xffffff;

            }

        }
    }

    private int[] normalize(float af[], int i, int j, float f, float f1)
    {
        System.out.println("normalize: [" + f + "," + f1 + "] -> [0,255]");
        int ai[] = new int[i * j];
        int l = 0;
        for(int i1 = 0; i1 < j; i1++)
        {
            for(int j1 = 0; j1 < i; j1++)
            {
                int k = (int)((double)((af[l] - f) / (f1 - f)) * 255D);
                ai[l++] = 0xff000000 | k << 16 | k << 8 | k;
            }

            if(disp == 1 && (i1 % j) / 4 == 0)
                QMatrix.setinfo(cout++, 0.0F);
        }

        return ai;
    }

    Applet applet;
    boolean drawFlag;
    Image image;
    float values[];
    int pixels[];
    int width;
    int height;
    int xb;
    int yb;
    int currx;
    int curry;
    boolean selectable;
    boolean imageUpdate;
    boolean selected;
    MatrixCanvas QMatrix;
    int disp;
    int cout;
}