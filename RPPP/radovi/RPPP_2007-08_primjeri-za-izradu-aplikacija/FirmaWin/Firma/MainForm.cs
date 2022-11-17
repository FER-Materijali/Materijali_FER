using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace Firma
{
  // Glavna forma
  public partial class MainForm : Form
  {
    #region Form Instance
    // Instanca glavne forme. 
    // Statièka varijabla da se glavnoj formi lakše pristupi iz ostalih, nevezanih, klasa.
    private static MainForm instance;
    public static MainForm Instance
    {
      get { return instance; }
    }
    #endregion

    #region Constructors & Init
    public MainForm()
    {
      InitializeComponent();
      // "Publishiranje" glavne forme
      instance = this;

      menuStrip1.MdiWindowListItem.DropDownOpening += MdiWindowListItem_DropDownOpening;


      ClearStatusBar();
    }
    #endregion

    #region StatusBar
    // Inicijalno postavljanje statusne trake
    public void ClearStatusBar()
    {
      sblFunction.Text = sblStatus.Text = sblModuleName.Text = string.Empty;
      sblUser.Text = "Korisnik: " + FirmaApp.User;
      sblStatus.ForeColor = Color.FromKnownColor(KnownColor.ControlText);
      sblStatus.BackColor = Color.FromKnownColor(KnownColor.Control);
    }

    // Postavljanje statusne trake
    public void SetStatusBar(StatusBarInfo info)
    {
      if (info != null)
      {
        sblModuleName.Text = info.NazivModula;
        sblFunction.Text = info.Funkcija;
        sblStatus.Text = info.Message;
        sblUser.Text = info.User;
        if (info.IsError)
        {
          sblStatus.ForeColor = Color.Yellow;
          sblStatus.BackColor = Color.Red;
        }
        else
        {
          sblStatus.ForeColor = Color.FromKnownColor(KnownColor.ControlText);
          sblStatus.BackColor = Color.FromKnownColor(KnownColor.Control);
        }
      }
      else
      {
        ClearStatusBar();
      }
    }
    #endregion

    #region Key Events Propagation
    // Prosljeðivanje KeyDown eventa trenutno aktivnoj child formi
    private void MainForm_KeyDown(object sender, KeyEventArgs e)
    {
      if (ActiveMdiChild != null && ActiveMdiChild is BaseForm)
        ((BaseForm)ActiveMdiChild).InvokeKeyDown(e);
    }
    #endregion

    #region MenuItem Clicks
    private void izlazToolStripMenuItem_Click(object sender, EventArgs e)
    {
      Application.Exit();
    }

    private void artiklToolStripMenuItem_Click(object sender, EventArgs e)
    {
      using (new StatusBusy())
      {
        ArtiklForm f = new ArtiklForm();
        f.MdiParent = this;
        f.Show();
      }
    }

    private void dokumentToolStripMenuItem_Click(object sender, EventArgs e)
    {
      using (new StatusBusy())
      {
        DokumentForm f = new DokumentForm();
        f.MdiParent = this;
        f.Show();
      }
    }

    private void partnerToolStripMenuItem_Click(object sender, EventArgs e)
    {
      using (new StatusBusy())
      {
        PartnerForm f = new PartnerForm();
        f.MdiParent = this;
        f.Show();
      }
    }

    private void dokumentWizardToolStripMenuItem_Click(object sender, EventArgs e)
    {
      DokumentWizard.Run();
    }

    void MdiWindowListItem_DropDownOpening(object sender, EventArgs e)
    {
      // ukloni separator ako je zadnji u listi
      ToolStripItemCollection items = menuStrip1.MdiWindowListItem.DropDownItems;
      if (items[items.Count - 1] is ToolStripSeparator)
      {
        items.RemoveAt(items.Count - 1);
      }
    }

    #endregion

    #region Prozori
    private void kaskadnoPoravnanjeToolStripMenuItem_Click(object sender, EventArgs e)
    {
      LayoutMdi(MdiLayout.Cascade);
    }

    private void horizontalnoPoravnanjeToolStripMenuItem_Click(object sender, EventArgs e)
    {
      LayoutMdi(MdiLayout.TileHorizontal);
    }

    private void vertikalnoPoravnanjeToolStripMenuItem_Click(object sender, EventArgs e)
    {
      LayoutMdi(MdiLayout.TileVertical);
    }
    #endregion

    private void artiklToolStripTablice_Click(object sender, EventArgs e)
    {
      using (new StatusBusy())
      {
        ArtiklBllProvider bll = new ArtiklBllProvider();
        GenericForm f = new GenericForm("Artikl", bll.FetchAll(), bll, typeof(Artikl));
        f.MdiParent = this;
        f.Show();
      }
    }

    private void drzavaToolStripTablice_Click(object sender, EventArgs e)
    {
      using (new StatusBusy())
      {
        //DrzavaBllProvider bll = new DrzavaBllProvider();
        //GenericForm f = new GenericForm("Drzava", bll.FetchAll(), bll, typeof(Drzava));
        //f.MdiParent = this;
        //f.Show();
      }
    }

    private void mjestoToolStripTablice_Click(object sender, EventArgs e)
    {
      using (new StatusBusy())
      {
        MjestoBllProvider bll = new MjestoBllProvider();
        GenericForm f = new GenericForm("Mjesto", bll.FetchAll(), bll, typeof(Mjesto));
        f.MdiParent = this;
        f.Show();
      }
    }

    private void HelpStripMenuItem_Click(object sender, EventArgs e)
    {
      //Help.ShowHelp(this,@"Doc\Firma.chm");
      Help.ShowHelp(this, helpProvider1.HelpNamespace);
    }
  }
}