package web3d;

import shout3d.*;
import javax.swing.*;
import javax.swing.event.*;

public class Web3DApplet extends Shout3DApplet{

  private JSlider slider;
  private Web3DPanel web3DPanel;

  /**
   * Metoda koja se zove prilikom inicijalizacije appleta.
   */
  public void initShout3DPanel(){
    this.panel=new Web3DPanel(this,640,460);//za slider ostavljamo 20 tocaka visine
    web3DPanel=(Web3DPanel)panel;
    /***********
     Nakon sto smo kreirali novi panel (Web3DPanel), ovdje je potrebno napraviti jos
     jednu stvar. Potrebno je instancirati JSlider (this.slider), postaviti mu
     potrebne dimenzije i dodati ga na applet (this.add(slider)).

     Da bi mogli pratiti promjene polozaja slidera i reagirati na njih, potrebno je
     nasem slideru dodati objekt klase ChangeListener (tj. napraviti svoju klasu koja implementira
     sucelje ChangeListener, te je metodom slider.addChangeListener() dodijeliti nasem slideru).
     U toj klasi potrebno je definirati metodu stateChanged() u kojoj zapravo odredujemo
     sto se desava pri pomicanju slidera.
    ************/

  }


}