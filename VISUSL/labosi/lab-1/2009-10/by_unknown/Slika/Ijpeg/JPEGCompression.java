import java.applet.Applet;
import java.awt.*;
import java.io.PrintStream;
import java.util.Date;

public class JPEGCompression extends Applet
{

    public void makebutton(Button button, GridBagLayout gridbaglayout, GridBagConstraints gridbagconstraints)
    {
        gridbaglayout.setConstraints(button, gridbagconstraints);
        add(button);
    }

    public void init()
    {
        GridBagLayout gridbaglayout = new GridBagLayout();
        GridBagConstraints gridbagconstraints = new GridBagConstraints();
        setLayout(gridbaglayout);
        gridbagconstraints.fill = 1;
        gridbagconstraints.weightx = 2D;
        gridbagconstraints.weighty = 1.0D;
        gridbagconstraints.gridwidth = 2;
        gridbagconstraints.gridheight = 1;
        java.awt.Image image = getImage(getDocumentBase(), getParameter("image"));
        rgbCanvas = new ImageCanvas(this, image, false);
        rgbCanvas.setSelectable(true);
        ImagePanel imagepanel = new ImagePanel(rgbCanvas, null, null);
        gridbaglayout.setConstraints(imagepanel, gridbagconstraints);
        add(imagepanel);
        yCanvas = new ImageCanvas(this);
        iCanvas = new ImageCanvas(this);
        qCanvas = new ImageCanvas(this);
        gridbagconstraints.gridwidth = 3;
        gridbagconstraints.weightx = 3D;
        ImagePanel imagepanel1 = new ImagePanel(yCanvas, iCanvas, qCanvas);
        gridbaglayout.setConstraints(imagepanel1, gridbagconstraints);
        add(imagepanel1);
        ydctCanvas = new ImageCanvas(this);
        idctCanvas = new ImageCanvas(this);
        qdctCanvas = new ImageCanvas(this);
        ImagePanel imagepanel2 = new ImagePanel(ydctCanvas, idctCanvas, qdctCanvas);
        gridbagconstraints.gridwidth = 0;
        gridbaglayout.setConstraints(imagepanel2, gridbagconstraints);
        add(imagepanel2);
        gridbagconstraints.weightx = 1.0D;
        gridbagconstraints.weighty = 0.20000000000000001D;
        gridbagconstraints.gridwidth = 2;
        b6 = new Button("    QM1: non-uniform quantization    ");
        makebutton(b6, gridbaglayout, gridbagconstraints);
        b5 = new Button("  QM2: low non-uniform quantization  ");
        makebutton(b5, gridbaglayout, gridbagconstraints);
        gridbagconstraints.gridwidth = 0;
        b7 = new Button("  QM3: high non-uniform  quantization  ");
        makebutton(b7, gridbaglayout, gridbagconstraints);
        gridbagconstraints.gridwidth = 2;
        b2 = new Button("       QM4: constant quantization       ");
        makebutton(b2, gridbaglayout, gridbagconstraints);
        b1 = new Button("QM5: low constant quantization ");
        makebutton(b1, gridbaglayout, gridbagconstraints);
        gridbagconstraints.gridwidth = 0;
        b3 = new Button("      QM6: high constant quantization      ");
        makebutton(b3, gridbaglayout, gridbagconstraints);
        gridbagconstraints.weighty = 0.20000000000000001D;
        gridbagconstraints.weightx = 0.10000000000000001D;
        b4 = new Button("     SUBMIT     ");
        gridbagconstraints.fill = 3;
        makebutton(b4, gridbaglayout, gridbagconstraints);
        gridbagconstraints.fill = 1;
        QMatrix = new MatrixCanvas(QTable, 8, 8, "Quantization Table", true);
        DCTMatrix = new MatrixCanvas(UTable, 8, 8, "DCT (8x8 block)", false);
        QDCTMatrix = new MatrixCanvas(UTable, 8, 8, "Quantized 8x8 block", false);
        MatrixPanel matrixpanel = new MatrixPanel(QMatrix, DCTMatrix, QDCTMatrix);
        gridbagconstraints.weightx = 0.0D;
        gridbagconstraints.weighty = 1.5D;
        gridbagconstraints.gridheight = 1;
        gridbaglayout.setConstraints(matrixpanel, gridbagconstraints);
        add(matrixpanel);
        gridbagconstraints.weighty = 1.0D;
        qydctCanvas = new ImageCanvas(this);
        qidctCanvas = new ImageCanvas(this);
        qqdctCanvas = new ImageCanvas(this);
        ImagePanel imagepanel3 = new ImagePanel(qydctCanvas, qidctCanvas, qqdctCanvas);
        gridbagconstraints.weightx = 3D;
        gridbagconstraints.gridwidth = 3;
        gridbaglayout.setConstraints(imagepanel3, gridbagconstraints);
        add(imagepanel3);
        yOutCanvas = new ImageCanvas(this);
        iOutCanvas = new ImageCanvas(this);
        qOutCanvas = new ImageCanvas(this);
        ImagePanel imagepanel4 = new ImagePanel(yOutCanvas, iOutCanvas, qOutCanvas);
        gridbaglayout.setConstraints(imagepanel4, gridbagconstraints);
        add(imagepanel4);
        rgbOutCanvas = new ImageCanvas(this);
        ImagePanel imagepanel5 = new ImagePanel(rgbOutCanvas, null, null);
        gridbagconstraints.weightx = 1.0D;
        gridbagconstraints.gridwidth = 0;
        gridbaglayout.setConstraints(imagepanel5, gridbagconstraints);
        add(imagepanel5);
        Dimension dimension = gridbaglayout.minimumLayoutSize(this);
        System.out.println("layout min size: " + dimension.width + " x " + dimension.height);
        drawDone = false;
    }

    public boolean mouseDown(Event event, int i, int j)
    {
        System.out.println("Applet: mouse click");
        if(!drawDone)
        {
            rgbCanvas.setSelectable(false);
            drawDone = true;
            rgbCanvas.drawn();
            yCanvas.drawn();
            QMatrix.setinfo(1, 0.0F);
            makeYIQ();
            QMatrix.setinfo(2, 0.0F);
            makeDCT();
            QMatrix.setinfo(3, 0.0F);
            quantize_DCT();
            QMatrix.setinfo(4, 0.0F);
            makeIDCT();
            QMatrix.setinfo(5, 0.0F);
            makeRGB();
            QMatrix.setinfo(11, ratio);
            total = 0;
        } else
        if(event.target instanceof ImageCanvas)
        {
            yCanvas.initdraw();
            iCanvas.initdraw();
            qCanvas.initdraw();
            ((ImageCanvas)event.target).rectdraw();
            Point point = ((ImageCanvas)event.target).getSelection();
            int ai[] = new int[64];
            int ai1[] = QMatrix.getMatrix(2);
            int ai2[] = new int[64];
            for(int k = 0; k < 64; k++)
            {
                if((ImageCanvas)event.target == yCanvas)
                    ai[k] = (int)yDCTvalues[point.x][point.y][k];
                else
                if((ImageCanvas)event.target == iCanvas)
                    ai[k] = (int)iDCTvalues[point.x][point.y][k];
                if((ImageCanvas)event.target == qCanvas)
                    ai[k] = (int)qDCTvalues[point.x][point.y][k];
                ai2[k] = ai[k] / ai1[k];
            }

            DCTMatrix.setMatrix(ai, 8, 8);
            QDCTMatrix.setMatrix(ai2, 8, 8);
        }
        return true;
    }

    public boolean action(Event event, Object obj)
    {
        if(event.target == b1)
        {
            QMatrix.getMatrix(1);
            return false;
        }
        if(event.target == b2)
        {
            QMatrix.getMatrix(3);
            return false;
        }
        if(event.target == b3)
        {
            QMatrix.getMatrix(4);
            return false;
        }
        if(event.target == b5)
        {
            QMatrix.getMatrix(11);
            return false;
        }
        if(event.target == b6)
        {
            QMatrix.getMatrix(12);
            return false;
        }
        if(event.target == b7)
        {
            QMatrix.getMatrix(13);
            return false;
        }
        if(event.target == b4)
            if(!drawDone)
            {
                showStatus("The java program is running, please wait");
                rgbCanvas.setSelectable(false);
                drawDone = true;
                QMatrix.setinfo(1, 0.0F);
                rgbCanvas.drawn();
                yCanvas.drawn();
                makeYIQ();
                showStatus("make DCT");
                makeDCT();
                QMatrix.setinfo(0, 0.0F);
                showStatus("quantize DCT");
                quantize_DCT();
                makeIDCT();
                QMatrix.setinfo(0, 0.0F);
                makeRGB();
                QMatrix.setinfo(2, 0.0F);
                QMatrix.setinfo(11, ratio);
                total = 0;
            } else
            {
                showStatus("The java program");
                QMatrix.resetinfo();
                System.out.println("It takes a while, please wait");
                QMatrix.setinfo(0, 0.0F);
                quantize_DCT();
                makeIDCT();
                QMatrix.setinfo(0, 0.0F);
                makeRGB();
                QMatrix.setinfo(11, ratio);
                total = 0;
                return false;
            }
        return true;
    }

    public boolean keyDown(Event event, int i)
    {
        System.out.println("Applet: key press");
        System.out.println("key: " + i);
        if(i == 10)
            QMatrix.getMatrix(0);
        return false;
    }

    private void makeYIQ()
    {
        showStatus("generating YIQ images");
        Dimension dimension = rgbCanvas.getImageSize();
        xb = dimension.width / 8;
        yb = dimension.height / 8;
        w = xb * 8;
        h = yb * 8;
        System.out.println("YIQ: xb = " + xb + " yb = " + yb + " w = " + w + " h = " + h);
        float af[] = new float[w * h];
        int i = 0;
        for(int j = 0; j < h; j++)
        {
            for(int k = 0; k < w; k++)
                af[i++] = rgb2y((int)rgbCanvas.getImageValue(k, j));

        }

        yCanvas.setImageValues(af, w, h, QMatrix, 0);
        yCanvas.setSelectable(true);
        float af1[] = new float[xb * yb * 16];
        float af2[] = new float[xb * yb * 16];
        int ai[] = new int[4];
        i = 0;
        for(int i1 = 0; i1 < h; i1 += 2)
        {
            for(int j1 = 0; j1 < w; j1 += 2)
            {
                ai[0] = (int)rgbCanvas.getImageValue(j1, i1);
                ai[1] = (int)rgbCanvas.getImageValue(j1 + 1, i1);
                ai[2] = (int)rgbCanvas.getImageValue(j1, i1 + 1);
                ai[3] = (int)rgbCanvas.getImageValue(j1 + 1, i1 + 1);
                int l = rgb_average(ai, 4);
                af1[i] = rgb2i(l);
                af2[i++] = rgb2q(l);
            }

        }

        iCanvas.setImageValues(af1, w / 2, h / 2, -153, 153, QMatrix, 0);
        iCanvas.setSelectable(true);
        qCanvas.setImageValues(af2, w / 2, h / 2, -136, 136, QMatrix, 0);
        qCanvas.setSelectable(true);
    }

    private int rgb2y(int i)
    {
        int j = (int)(0.29899999999999999D * (double)((i & 0xff0000) >> 16) + 0.58699999999999997D * (double)((i & 0xff00) >> 8) + 0.114D * (double)(i & 0xff));
        return j << 16 | j << 8 | j;
    }

    private float rgb2i(int i)
    {
        float f = (float)(0.59599999999999997D * (double)((i & 0xff0000) >> 16) - 0.27500000000000002D * (double)((i & 0xff00) >> 8) - 0.32100000000000001D * (double)(i & 0xff));
        return f;
    }

    private float rgb2q(int i)
    {
        float f = (float)((0.21199999999999999D * (double)((i & 0xff0000) >> 16) - 0.52800000000000002D * (double)((i & 0xff00) >> 8)) + 0.311D * (double)(i & 0xff));
        return f;
    }

    private int rgb_average(int ai[], int i)
    {
        int ai1[] = new int[3];
        int j = 0xff0000;
        for(int k = 0; k < 3; k++)
        {
            ai1[k] = 0;
            for(int l = 0; l < i; l++)
                ai1[k] += ai[l] & j;

            j >>= 8;
            ai1[k] = (ai1[k] >> 8 * (2 - k)) / 4;
        }

        return ai1[0] << 16 | ai1[1] << 8 | ai1[2];
    }

    private void makeDCT()
    {
        int i = 201;
        showStatus("generating DCT images");
        System.out.println("DCT: xb = " + xb + " yb = " + yb);
        QMatrix.setinfo(0, 0.0F);
        yDCTvalues = new float[xb][yb][64];
        q_Yvalues = new float[xb][yb][64];
        boolean flag = false;
        for(int j = 0; j < yb; j++)
        {
            for(int k = 0; k < xb; k++)
            {
                yCanvas.getBlockPixels(yDCTvalues[k][j], k, j);
                dct_2d(yDCTvalues[k][j], 8);
            }

            if(j == yb / 3)
                QMatrix.setinfo(i++, 0.0F);
            if(j == (2 * yb) / 3)
                QMatrix.setinfo(i++, 0.0F);
        }

        QMatrix.setinfo(i++, 0.0F);
        ydctCanvas.setImageValues(blocks2image(yDCTvalues, xb, yb, 8, 8), w, h, QMatrix, 0);
        iDCTvalues = new float[xb / 2][yb / 2][64];
        q_Ivalues = new float[xb / 2][yb / 2][64];
        qDCTvalues = new float[xb / 2][yb / 2][64];
        q_Qvalues = new float[xb / 2][yb / 2][64];
        flag = false;
        for(int l = 0; l < yb / 2; l++)
        {
            for(int i1 = 0; i1 < xb / 2; i1++)
            {
                iCanvas.getBlockPixels(iDCTvalues[i1][l], i1, l);
                qCanvas.getBlockPixels(qDCTvalues[i1][l], i1, l);
                dct_2d(iDCTvalues[i1][l], 8);
                dct_2d(qDCTvalues[i1][l], 8);
            }

            if(l > 0 && (l % yb) / 4 == 0)
                QMatrix.setinfo(i++, 0.0F);
        }

        idctCanvas.setImageValues(blocks2image(iDCTvalues, xb / 2, yb / 2, 8, 8), w / 2, h / 2, QMatrix, 0);
        QMatrix.setinfo(i++, 0.0F);
        qdctCanvas.setImageValues(blocks2image(qDCTvalues, xb / 2, yb / 2, 8, 8), w / 2, h / 2, QMatrix, 0);
    }

    private void quantize_DCT()
    {
        showStatus("Quantizing");
        int ai[] = QMatrix.getMatrix(2);
        zz_q_Yvalues = new float[xb][yb][128];
        zz_q_Ivalues = new float[xb / 2][yb / 2][128];
        zz_q_Qvalues = new float[xb / 2][yb / 2][128];
        QMatrix.fpaint();
        total = 0;
        for(int i = 0; i < xb; i++)
        {
            for(int j = 0; j < yb; j++)
            {
                for(int l = 0; l < 64; l++)
                    q_Yvalues[i][j][l] = (float)(int)(yDCTvalues[i][j][l] / (float)ai[l]) * (float)ai[l];

                zz(q_Yvalues[i][j], zz_q_Yvalues[i][j]);
            }

        }

        qydctCanvas.setImageValues(blocks2image(q_Yvalues, xb, yb, 8, 8), w, h, QMatrix, 0);
        for(int k = 0; k < yb / 2; k++)
        {
            for(int i1 = 0; i1 < xb / 2; i1++)
            {
                for(int j1 = 0; j1 < 64; j1++)
                {
                    q_Ivalues[i1][k][j1] = (float)(int)(iDCTvalues[i1][k][j1] / (float)ai[j1]) * (float)ai[j1];
                    q_Qvalues[i1][k][j1] = (float)(int)(qDCTvalues[i1][k][j1] / (float)ai[j1]) * (float)ai[j1];
                }

                zz(q_Qvalues[i1][k], zz_q_Qvalues[i1][k]);
                zz(q_Ivalues[i1][k], zz_q_Ivalues[i1][k]);
            }

        }

        ratio = (float)(xb * yb * 64 * 3) / (float)total;
        qidctCanvas.setImageValues(blocks2image(q_Ivalues, xb / 2, yb / 2, 8, 8), w / 2, h / 2, QMatrix, 0);
        qqdctCanvas.setImageValues(blocks2image(q_Qvalues, xb / 2, yb / 2, 8, 8), w / 2, h / 2, QMatrix, 0);
    }

    private void zz(float af[], float af1[])
    {
        int i = 0;
        int j = 0;
        for(int k = 0; k < 64; k++)
            if(af[ZTable[k]] != 0.0F)
            {
                if(i > 0)
                    af1[j++] = i;
                af1[j++] = af[ZTable[k]];
                i = 0;
            } else
            {
                if(i == 0)
                    af1[j++] = 0.0F;
                i++;
            }

        total += j;
    }

    private void makeIDCT()
    {
        showStatus("generating new YIQ images");
        System.out.println("inverse DCT: xb = " + xb + " yb = " + yb);
        QMatrix.setinfo(0, 0.0F);
        for(int i = 0; i < yb; i++)
        {
            for(int j = 0; j < xb; j++)
                idct_2d(q_Yvalues[j][i], 8);

            if(i == yb / 2)
                QMatrix.setinfo(0, 0.0F);
        }

        QMatrix.setinfo(0, 0.0F);
        yOutCanvas.setImageValues(blocks2image(q_Yvalues, xb, yb, 8, 8), w, h, -128, 127, QMatrix, 0);
        QMatrix.setinfo(0, 0.0F);
        for(int k = 0; k < yb / 2; k++)
        {
            for(int l = 0; l < xb / 2; l++)
            {
                idct_2d(q_Ivalues[l][k], 8);
                idct_2d(q_Qvalues[l][k], 8);
            }

            if(k == yb / 4)
                QMatrix.setinfo(0, 0.0F);
        }

        QMatrix.setinfo(0, 0.0F);
        iOutCanvas.setImageValues(blocks2image(q_Ivalues, xb / 2, yb / 2, 8, 8), w / 2, h / 2, -128, 127, QMatrix, 0);
        QMatrix.setinfo(0, 0.0F);
        qOutCanvas.setImageValues(blocks2image(q_Qvalues, xb / 2, yb / 2, 8, 8), w / 2, h / 2, -128, 127, QMatrix, 0);
    }

    private void makeRGB()
    {
        showStatus("generating final image");
        int ai[] = {
            0, 0, 1, 0, 0, 1, 1, 1
        };
        float af[] = new float[w * h];
        for(int l = 0; l < h; l += 2)
        {
            for(int i1 = 0; i1 < w; i1 += 2)
            {
                float f1 = iOutCanvas.getImageValue(i1 / 2, l / 2);
                float f2 = qOutCanvas.getImageValue(i1 / 2, l / 2);
                for(int j1 = 0; j1 < 8; j1 += 2)
                {
                    float f = yOutCanvas.getImageValue(i1 + ai[j1], l + ai[j1 + 1]);
                    int i = Math.min((int)((double)f + 0.95499999999999996D * (double)f1 + 0.61799999999999999D * (double)f2) + 128, 255);
                    int j = Math.min((int)(0.997D * (double)f - 0.27100000000000002D * (double)f1 - 0.64500000000000002D * (double)f2) + 128, 255);
                    int k = Math.min((int)(((double)f - 1.1100000000000001D * (double)f1) + 1.7D * (double)f2) + 128, 255);
                    af[(l + ai[j1 + 1]) * w + (i1 + ai[j1])] = i << 16 | j << 8 | k;
                }

            }

        }

        rgbOutCanvas.setImageValues(af, w, h, QMatrix, 0);
    }

    private void dct_2d(float af[], int i)
    {
        float af1[][] = new float[i][i];
        float f2 = (float)Math.sqrt(2D / (double)i);
        float f3 = (float)(1.0D / Math.sqrt(2D));
        for(int j = 0; j < i; j++)
        {
            for(int k = 0; k < i; k++)
            {
                af1[j][k] = 0.0F;
                for(int i1 = 0; i1 < i; i1++)
                {
                    float f = k != 0 ? 1.0F : f3;
                    af1[j][k] += (double)(f * af[i1 * i + j]) * Math.cos(((2D * (double)i1 + 1.0D) * (double)k * 3.1415926535897931D) / (double)(2 * i));
                }

                af1[j][k] *= f2;
            }

            for(int j1 = 0; j1 < i; j1++)
                af[j1 * i + j] = af1[j][j1];

        }

        for(int l = 0; l < i; l++)
        {
            for(int k1 = 0; k1 < i; k1++)
            {
                af1[k1][l] = 0.0F;
                for(int l1 = 0; l1 < i; l1++)
                {
                    float f1 = k1 != 0 ? 1.0F : f3;
                    af1[k1][l] += (double)(f1 * af[l * i + l1]) * Math.cos(((2D * (double)l1 + 1.0D) * (double)k1 * 3.1415926535897931D) / (double)(2 * i));
                }

                af1[k1][l] *= f2;
            }

            for(int i2 = 0; i2 < i; i2++)
                af[l * i + i2] = af1[i2][l];

        }

    }

    private void idct_2d(float af[], int i)
    {
        float af1[][] = new float[i][i];
        float f = (float)Math.sqrt(2D / (double)i);
        for(int j = 0; j < i; j++)
        {
            float f1 = (float)(1.0D / Math.sqrt(i)) * af[j * i];
            for(int l = 0; l < i; l++)
            {
                af1[l][j] = 0.0F;
                for(int i1 = 1; i1 < i; i1++)
                    af1[l][j] += (double)af[j * i + i1] * Math.cos(((2D * (double)l + 1.0D) * (double)i1 * 3.1415926535897931D) / (double)(2 * i));

                af1[l][j] *= f;
                af1[l][j] += f1;
            }

            for(int j1 = 0; j1 < i; j1++)
                af[j * i + j1] = af1[j1][j];

        }

        for(int k = 0; k < i; k++)
        {
            float f2 = (float)(1.0D / Math.sqrt(i)) * af[k];
            for(int k1 = 0; k1 < i; k1++)
            {
                af1[k][k1] = 0.0F;
                for(int l1 = 1; l1 < i; l1++)
                    af1[k][k1] += (double)af[l1 * i + k] * Math.cos(((2D * (double)k1 + 1.0D) * (double)l1 * 3.1415926535897931D) / (double)(2 * i));

                af1[k][k1] *= f;
                af1[k][k1] += f2;
            }

            for(int i2 = 0; i2 < i; i2++)
                af[i2 * i + k] = af1[k][i2];

        }

    }

    private float[] blocks2image(float af[][][], int i, int j, int k, int l)
    {
        float af1[] = new float[i * i * k * l];
        int i1 = k * l;
        for(int j1 = 0; j1 < j; j1++)
        {
            for(int k1 = 0; k1 < i; k1++)
            {
                for(int l1 = 0; l1 < l; l1++)
                {
                    for(int i2 = 0; i2 < k; i2++)
                        af1[j1 * i1 * i + k1 * 8 + l1 * 8 * i + i2] = af[k1][j1][l1 * k + i2];

                }

            }

        }

        return af1;
    }

    public JPEGCompression()
    {
        dat = new Date();
        ccc = 222;
    }

    ImageCanvas rgbCanvas;
    ImageCanvas yCanvas;
    ImageCanvas iCanvas;
    ImageCanvas qCanvas;
    ImageCanvas ydctCanvas;
    ImageCanvas idctCanvas;
    ImageCanvas qdctCanvas;
    ImageCanvas qydctCanvas;
    ImageCanvas qidctCanvas;
    ImageCanvas qqdctCanvas;
    ImageCanvas yOutCanvas;
    ImageCanvas iOutCanvas;
    ImageCanvas qOutCanvas;
    ImageCanvas rgbOutCanvas;
    MatrixCanvas QMatrix;
    MatrixCanvas DCTMatrix;
    MatrixCanvas QDCTMatrix;
    int QTable[] = {
        16, 11, 10, 16, 24, 40, 51, 61, 12, 12, 
        14, 19, 26, 58, 60, 55, 14, 13, 16, 24, 
        40, 57, 69, 56, 14, 17, 22, 29, 51, 87, 
        80, 62, 18, 22, 37, 56, 68, 109, 103, 77, 
        24, 35, 55, 64, 81, 104, 113, 92, 49, 64, 
        78, 87, 103, 121, 120, 101, 72, 92, 95, 98, 
        112, 100, 103, 99
    };
    int ZTable[] = {
        0, 1, 8, 16, 9, 2, 3, 10, 17, 24, 
        32, 25, 18, 11, 4, 4, 12, 19, 26, 33, 
        40, 48, 41, 34, 27, 20, 13, 6, 7, 14, 
        21, 28, 35, 42, 49, 56, 57, 50, 43, 36, 
        29, 22, 15, 23, 30, 37, 44, 51, 58, 59, 
        52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 
        47, 55, 62, 63
    };
    int UTable[];
    int total;
    float ratio;
    float yDCTvalues[][][];
    float iDCTvalues[][][];
    float qDCTvalues[][][];
    float q_Yvalues[][][];
    float q_Ivalues[][][];
    float q_Qvalues[][][];
    float zz_q_Yvalues[][][];
    float zz_q_Ivalues[][][];
    float zz_q_Qvalues[][][];
    int w;
    int h;
    int xb;
    int yb;
    float dctmin;
    float dctmax;
    boolean drawDone;
    Button b1;
    Button b2;
    Button b3;
    Button b4;
    Button b5;
    Button b6;
    Button b7;
    Panel p0;
    Date dat;
    int last_time;
    int curr_time;
    Event eet;
    Object oob;
    int ccc;
}