import java.awt.*;

class ImagePanel extends Panel
{

    ImagePanel(ImageCanvas imagecanvas, ImageCanvas imagecanvas1, ImageCanvas imagecanvas2)
    {
        GridBagLayout gridbaglayout = new GridBagLayout();
        GridBagConstraints gridbagconstraints = new GridBagConstraints();
        setLayout(gridbaglayout);
        gridbagconstraints.fill = 1;
        gridbagconstraints.insets = new Insets(4, 2, 4, 2);
        gridbagconstraints.weightx = 2D;
        gridbagconstraints.gridwidth = imagecanvas1 != null ? 1 : 0;
        gridbagconstraints.gridheight = 2;
        gridbagconstraints.weighty = 2D;
        gridbaglayout.setConstraints(imagecanvas, gridbagconstraints);
        add(imagecanvas);
        gridbagconstraints.weightx = 1.0D;
        gridbagconstraints.gridheight = 1;
        gridbagconstraints.weighty = 1.0D;
        gridbagconstraints.gridwidth = 0;
        if(imagecanvas1 != null)
        {
            gridbaglayout.setConstraints(imagecanvas1, gridbagconstraints);
            add(imagecanvas1);
            gridbaglayout.setConstraints(imagecanvas2, gridbagconstraints);
            add(imagecanvas2);
        }
    }
}