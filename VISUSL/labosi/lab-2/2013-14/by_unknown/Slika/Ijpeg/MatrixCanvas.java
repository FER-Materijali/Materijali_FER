import java.awt.*;
import java.io.PrintStream;

public class MatrixCanvas extends Panel
{

    MatrixCanvas(int ai[], int i, int j, String s, boolean flag)
    {
        text_str = new String("The program is running ");
        System.out.println("creating matrix " + i + " x " + j);
        matrix = ai;
        width = i;
        height = j;
        font = new Font("Helvetica", 1, 12);
        editable = flag;
        mrect = new Rectangle(0, 0, 0, 0);
        currx = curry = 0;
        setLayout(new BorderLayout());
        add("North", new Label(s, 1));
        if(flag)
        {
            input = new TextField("ps" + String.valueOf(matrix[0]), 5);
            add("South", input);
        }
    }

    public void setMatrix(int ai[], int i, int j)
    {
        matrix = ai;
        width = i;
        height = j;
        repaint();
    }

    public int[] getMatrix(int i)
    {
        if(i == 0)
            new_value(0);
        else
        if(i == 1)
            new_value(1);
        else
        if(i == 3)
            new_value(3);
        else
        if(i == 4)
            new_value(4);
        else
        if(i == 11)
            new_value(11);
        else
        if(i == 12)
            new_value(12);
        else
        if(i == 13)
            new_value(13);
        repaint();
        return matrix;
    }

    public void fpaint()
    {
        repaint();
    }

    public void paint(Graphics g)
    {
        Rectangle rectangle = bounds();
        fm = g.getFontMetrics(font);
        w = fm.stringWidth("0000");
        h = fm.getHeight();
        Point point = new Point(rectangle.width / 2 - (width * w) / 2, (rectangle.height / 2 - (height * h) / 2) + h);
        mrect.reshape(point.x, point.y - h, width * w, height * h);
        g.drawRect(mrect.x, mrect.y - 1, mrect.width + 5, mrect.height + 6);
        int i = 0;
        for(int j = 0; j < height; j++)
        {
            for(int k = 0; k < width; k++)
                if(matrix[i] >= 100)
                    g.drawString(" " + String.valueOf(matrix[i++]), point.x + w * k, point.y + h * j);
                else
                if(matrix[i] >= 10 && matrix[i] < 100)
                    g.drawString("   " + String.valueOf(matrix[i++]), point.x + w * k, point.y + h * j);
                else
                if(matrix[i] >= 0 && matrix[i] < 10)
                    g.drawString("     " + String.valueOf(matrix[i++]), point.x + w * k, point.y + h * j);
                else
                if(matrix[i] < 0 && matrix[i] > -10)
                    g.drawString("   " + String.valueOf(matrix[i++]), point.x + w * k, point.y + h * j);
                else
                if(matrix[i] <= -10 && matrix[i] > -100)
                    g.drawString(" " + String.valueOf(matrix[i++]), point.x + w * k, point.y + h * j);
                else
                    g.drawString(String.valueOf(matrix[i++]), point.x + w * k, point.y + h * j);

        }

        if(editable)
        {
            Color color = g.getColor();
            g.setColor(getBackground());
            g.drawRect(mrect.x + oldx * w + 2, mrect.y + oldy * h + 2, w + 1, h);
            g.setColor(Color.red);
            g.drawRect(mrect.x + currx * w + 2, mrect.y + curry * h + 2, w + 1, h);
            g.setColor(color);
        }
    }

    public boolean mouseDown(Event event, int i, int j)
    {
        if(editable && mrect.inside(i, j))
        {
            System.out.println("Matrix click at: " + i + "," + j);
            oldx = currx;
            oldy = curry;
            currx = (i - mrect.x) / w;
            curry = (j - mrect.y) / h;
            int k = matrix[curry * width + currx];
            input.setText("ps" + String.valueOf(k));
            repaint();
        }
        return true;
    }

    public void resetinfo()
    {
        text_str = new String("Your submission being processed ");
    }

    public void setinfo(int i, float f)
    {
        text_str = new String(text_str.concat("*"));
        if(i == 11)
        {
            String s = new String(String.valueOf(f));
            String s1 = new String(s.substring(0, s.length() - 3));
            input.setText("The compression ratio is " + s1);
        } else
        {
            input.setText(text_str);
        }
        repaint();
    }

    public boolean action(Event event, Object obj)
    {
        return true;
    }

    private void new_value(int i)
    {
        if(i == 1)
        {
            for(int j = 0; j < height; j++)
            {
                for(int l1 = 0; l1 < width; l1++)
                    matrix[j * width + l1] = 2;

            }

            repaint();
            return;
        }
        if(i == 4)
        {
            for(int k = 0; k < height; k++)
            {
                for(int i2 = 0; i2 < width; i2++)
                    matrix[k * width + i2] = 128;

            }

            repaint();
            return;
        }
        if(i == 3)
        {
            for(int l = 0; l < height; l++)
            {
                for(int j2 = 0; j2 < width; j2++)
                    matrix[l * width + j2] = 32;

            }

            repaint();
            return;
        }
        if(i == 11)
        {
            for(int i1 = 0; i1 < height; i1++)
            {
                for(int k2 = 0; k2 < width; k2++)
                    matrix[i1 * width + k2] = Math.max(new_matrix1[i1 * width + k2] / 2, 1);

            }

            repaint();
            return;
        }
        if(i == 12)
        {
            for(int j1 = 0; j1 < height; j1++)
            {
                for(int l2 = 0; l2 < width; l2++)
                    matrix[j1 * width + l2] = new_matrix1[j1 * width + l2];

            }

            repaint();
            return;
        }
        if(i == 13)
        {
            for(int k1 = 0; k1 < height; k1++)
            {
                for(int i3 = 0; i3 < width; i3++)
                    matrix[k1 * width + i3] = Math.min(new_matrix1[k1 * width + i3] * 4, 300);

            }

            repaint();
            return;
        }
        String s = new String(input.getText());
        String s1 = new String(s.substring(0, 2));
        new String(s.substring(2, s.length()));
        int j3 = 2;
        for(String s2 = new String(s.substring(2, 3)); s2.compareTo(" ") == 0; s2 = new String(s.substring(++j3, j3 + 1)));
        Integer integer = new Integer(s.substring(j3, s.length()));
        if(s1.compareTo("nm") == 0 || s1.compareTo("NM") == 0)
            if(integer.intValue() == 5)
            {
                for(int k3 = 0; k3 < height; k3++)
                {
                    for(int i9 = 0; i9 < width; i9++)
                        matrix[k3 * width + i9] = 2;

                }

            } else
            if(integer.intValue() == 4)
            {
                for(int l3 = 0; l3 < height; l3++)
                {
                    for(int j9 = 0; j9 < width; j9++)
                        matrix[l3 * width + j9] = 32;

                }

            } else
            if(integer.intValue() == 6)
            {
                for(int i4 = 0; i4 < height; i4++)
                {
                    for(int k9 = 0; k9 < width; k9++)
                        matrix[i4 * width + k9] = 128;

                }

            } else
            if(integer.intValue() == 2)
            {
                for(int j4 = 0; j4 < height; j4++)
                {
                    for(int l9 = 0; l9 < width; l9++)
                        matrix[j4 * width + l9] = Math.max(new_matrix1[j4 * width + l9] / 2, 1);

                }

            } else
            if(integer.intValue() == 1)
            {
                for(int k4 = 0; k4 < height; k4++)
                {
                    for(int i10 = 0; i10 < width; i10++)
                        matrix[k4 * width + i10] = new_matrix1[k4 * width + i10];

                }

            } else
            if(integer.intValue() == 3)
            {
                for(int l4 = 0; l4 < height; l4++)
                {
                    for(int j10 = 0; j10 < width; j10++)
                        matrix[l4 * width + j10] = Math.min(new_matrix1[l4 * width + j10] * 2, 300);

                }

            }
        if(s1.compareTo("ga") == 0 || s1.compareTo("GA") == 0)
        {
            for(int i5 = 0; i5 < height; i5++)
            {
                for(int k10 = 0; k10 < width; k10++)
                    matrix[i5 * width + k10] = Math.min(matrix[i5 * width + k10] + integer.intValue(), 300);

            }

        }
        if(s1.compareTo("gs") == 0 || s1.compareTo("GS") == 0)
        {
            for(int j5 = 0; j5 < height; j5++)
            {
                for(int l10 = 0; l10 < width; l10++)
                    matrix[j5 * width + l10] = Math.max(matrix[j5 * width + l10] - integer.intValue(), 1);

            }

        }
        if(s1.compareTo("gt") == 0 || s1.compareTo("GT") == 0)
        {
            for(int k5 = 0; k5 < height; k5++)
            {
                for(int i11 = 0; i11 < width; i11++)
                    matrix[k5 * width + i11] = Math.min(matrix[k5 * width + i11] * integer.intValue(), 300);

            }

        }
        if(s1.compareTo("gd") == 0 || s1.compareTo("GD") == 0)
        {
            for(int l5 = 0; l5 < height; l5++)
            {
                for(int j11 = 0; j11 < width; j11++)
                    matrix[l5 * width + j11] = Math.max(matrix[l5 * width + j11] / integer.intValue(), 1);

            }

        }
        if(s1.compareTo("la") == 0 || s1.compareTo("LA") == 0)
        {
            for(int i6 = 0; i6 < curry; i6++)
                matrix[i6 * width + currx] = Math.min(matrix[i6 * width + currx] + integer.intValue(), 300);

            for(int k11 = 0; k11 <= currx; k11++)
                matrix[curry * width + k11] = Math.min(matrix[curry * width + k11] + integer.intValue(), 300);

        }
        if(s1.compareTo("ls") == 0 || s1.compareTo("LS") == 0)
        {
            for(int j6 = 0; j6 < curry; j6++)
                matrix[j6 * width + currx] = Math.max(matrix[j6 * width + currx] - integer.intValue(), 1);

            for(int l11 = 0; l11 <= currx; l11++)
                matrix[curry * width + l11] = Math.max(matrix[curry * width + l11] - integer.intValue(), 1);

        }
        if(s1.compareTo("lt") == 0 || s1.compareTo("LT") == 0)
        {
            for(int k6 = 0; k6 < curry; k6++)
                matrix[k6 * width + currx] = Math.min(matrix[k6 * width + currx] * integer.intValue(), 300);

            for(int i12 = 0; i12 <= currx; i12++)
                matrix[curry * width + i12] = Math.min(matrix[curry * width + i12] * integer.intValue(), 300);

        }
        if(s1.compareTo("ld") == 0 || s1.compareTo("LD") == 0)
        {
            for(int l6 = 0; l6 < curry; l6++)
                matrix[l6 * width + currx] = Math.max(matrix[l6 * width + currx] / integer.intValue(), 1);

            for(int j12 = 0; j12 <= currx; j12++)
                matrix[curry * width + j12] = Math.max(matrix[curry * width + j12] / integer.intValue(), 1);

        }
        if(s1.compareTo("ia") == 0 || s1.compareTo("IA") == 0)
        {
            for(int i7 = 0; i7 <= curry; i7++)
            {
                for(int k12 = 0; k12 <= currx; k12++)
                    matrix[i7 * width + k12] = Math.min(matrix[i7 * width + k12] + integer.intValue(), 300);

            }

        } else
        if(s1.compareTo("oa") == 0 || s1.compareTo("OA") == 0)
        {
            for(int j7 = 0; j7 <= curry; j7++)
            {
                for(int l12 = currx + 1; l12 < width; l12++)
                    matrix[j7 * width + l12] = Math.min(matrix[j7 * width + l12] + integer.intValue(), 300);

            }

            for(int i13 = curry + 1; i13 < height; i13++)
            {
                for(int k15 = 0; k15 < width; k15++)
                    matrix[i13 * width + k15] = Math.min(matrix[i13 * width + k15] + integer.intValue(), 300);

            }

        } else
        if(s1.compareTo("is") == 0 || s1.compareTo("IS") == 0)
        {
            for(int k7 = 0; k7 <= curry; k7++)
            {
                for(int j13 = 0; j13 <= currx; j13++)
                    matrix[k7 * width + j13] = Math.max(matrix[k7 * width + j13] - integer.intValue(), 1);

            }

        } else
        if(s1.compareTo("os") == 0 || s1.compareTo("OS") == 0)
        {
            for(int l7 = 0; l7 <= curry; l7++)
            {
                for(int k13 = currx + 1; k13 < width; k13++)
                    matrix[l7 * width + k13] = Math.max(matrix[l7 * width + k13] - integer.intValue(), 1);

            }

            for(int l13 = curry + 1; l13 < height; l13++)
            {
                for(int l15 = 0; l15 < width; l15++)
                    matrix[l13 * width + l15] = Math.max(matrix[l13 * width + l15] - integer.intValue(), 1);

            }

        } else
        if(s1.compareTo("it") == 0 || s1.compareTo("IT") == 0)
        {
            for(int i8 = 0; i8 <= curry; i8++)
            {
                for(int i14 = 0; i14 <= currx; i14++)
                    matrix[i8 * width + i14] = Math.min(matrix[i8 * width + i14] * integer.intValue(), 300);

            }

        } else
        if(s1.compareTo("ot") == 0 || s1.compareTo("OT") == 0)
        {
            for(int j8 = 0; j8 <= curry; j8++)
            {
                for(int j14 = currx + 1; j14 < width; j14++)
                    matrix[j8 * width + j14] = Math.min(matrix[j8 * width + j14] * integer.intValue(), 300);

            }

            for(int k14 = curry + 1; k14 < height; k14++)
            {
                for(int i16 = 0; i16 < width; i16++)
                    matrix[k14 * width + i16] = Math.min(matrix[k14 * width + i16] * integer.intValue(), 300);

            }

        } else
        if(s1.compareTo("id") == 0 || s1.compareTo("ID") == 0)
        {
            for(int k8 = 0; k8 <= curry; k8++)
            {
                for(int l14 = 0; l14 <= currx; l14++)
                    matrix[k8 * width + l14] = Math.max(matrix[k8 * width + l14] / integer.intValue(), 1);

            }

        } else
        if(s1.compareTo("od") == 0 || s1.compareTo("OD") == 0)
        {
            for(int l8 = 0; l8 <= curry; l8++)
            {
                for(int i15 = currx + 1; i15 < width; i15++)
                    matrix[l8 * width + i15] = Math.max(matrix[l8 * width + i15] / integer.intValue(), 1);

            }

            for(int j15 = curry + 1; j15 < height; j15++)
            {
                for(int j16 = 0; j16 < width; j16++)
                    matrix[j15 * width + j16] = Math.max(matrix[j15 * width + j16] / integer.intValue(), 1);

            }

        } else
        if((s1.compareTo("ps") == 0 || s1.compareTo("PS") == 0) && matrix[curry * width + currx] != integer.intValue())
        {
            matrix[curry * width + currx] = Math.min(Math.max(integer.intValue(), 1), 300);
            System.out.println("martix: new value = " + integer.intValue());
        }
        repaint();
    }

    int matrix[];
    int width;
    int height;
    Font font;
    FontMetrics fm;
    boolean editable;
    Rectangle mrect;
    int w;
    int h;
    TextField input;
    int currx;
    int curry;
    int oldx;
    int oldy;
    String text_str;
    int work_matrix[];
    int new_matrix0[] = {
        16, 11, 10, 16, 24, 40, 51, 61, 12, 12, 
        14, 19, 26, 58, 60, 55, 14, 13, 16, 24, 
        40, 57, 69, 56, 14, 17, 22, 29, 51, 87, 
        80, 62, 18, 22, 37, 56, 68, 109, 103, 77, 
        24, 35, 55, 64, 81, 104, 113, 92, 49, 64, 
        78, 87, 103, 121, 120, 101, 72, 92, 95, 98, 
        112, 100, 103, 99
    };
    int new_matrix1[] = {
        16, 11, 10, 16, 24, 40, 51, 61, 12, 12, 
        14, 19, 26, 58, 60, 55, 14, 13, 16, 24, 
        40, 57, 69, 56, 14, 17, 22, 29, 51, 87, 
        80, 62, 18, 22, 37, 56, 68, 109, 103, 77, 
        24, 35, 55, 64, 81, 104, 113, 92, 49, 64, 
        78, 87, 103, 121, 120, 101, 72, 92, 95, 98, 
        112, 100, 103, 99
    };
}