import java.awt.*;

class MatrixPanel extends Panel
{

    MatrixPanel(MatrixCanvas matrixcanvas, MatrixCanvas matrixcanvas1, MatrixCanvas matrixcanvas2)
    {
        setBackground(new Color(0, 150, 100));
        setLayout(new GridLayout(1, 3));
        add(matrixcanvas);
        add(matrixcanvas1);
        add(matrixcanvas2);
    }
}