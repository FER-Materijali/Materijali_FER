using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.Collections;

using NTier;

namespace Firma
{
  // Wizard forma poslovnih partnera
  public partial class PartnerWizardForm : WizardBaseForm
  {
    #region Constructors & Init
    public PartnerWizardForm()
    {
      using (new StatusBusy())
      {
        InitializeComponent();

        // Dohvat svih partnera
        partnerBindingSource.DataSource = partnerBll.FetchAll();

        // Dohvat svih mjesta kako bi se omoguæio lookup
        MjestoList mjesta = (new MjestoBllProvider()).FetchAll();
        sjedisteMjestoBindingSource.DataSource = mjesta;
        isporukaMjestoBindingSource.DataSource = mjesta;

        // Povezivanje na objekte - programski radi definiranja formata prikaza
        // Prikazivanje/skrivanje panela ovisno o svojstvu Checked odabira tvrtka/osoba 
        osobaPanel.DataBindings.Add(new Binding("Visible", osobaCheck, "Checked"));
        tvrtkaPanel.DataBindings.Add(new Binding("Visible", tvrtkaCheck, "Checked"));
      }
    }
    #endregion

    #region BLL Objects
    // BLL sloj
    private PartnerBllProvider partnerBll = new PartnerBllProvider();

    // Metoda preko koje æe poslovni objekt doæi do BLL sloja kako bi obavio validaciju unosa
    private IBllObject Partner_NeedBllObject()
    {
      return partnerBll;
    }
    #endregion

    #region Partner Changed
    // Osvježavanje unosa i pridruživanje metode za BLL objekt poslovnom objektu
    private void partnerBindingSource_CurrentChanged(object sender, EventArgs e)
    {
      // as za razliku od obiène pretvorbe tipa neæe puknuti s InvalidCastException
      // ako tip nije ispravan nego æe vratiti null.
      Partner p = partnerBindingSource.Current as Partner;

      // Ako se radi o novom poslovnom objektu koji još ne zna gdje mu
      // je BLL objekt... ažuriraj.
      if (p != null && !p.HasBllObject)
      {
        p.NeedBllObject += new NeedBllObjectEventHandler(Partner_NeedBllObject);
      }

      // Osvježavanje izgleda forme
      if (p == null)
      {
        osobaCheck.Checked = false;
        tvrtkaCheck.Checked = false;
      }
      else if (p.TipPartnera == TipPartnera.Tvrtka)
      {
        osobaCheck.Checked = false;
        tvrtkaCheck.Checked = true;
      }
      else
      {
        osobaCheck.Checked = true;
        tvrtkaCheck.Checked = false;
      }

      if (p != null)
      {
        groupBox3.Enabled = p.State == BusinessObjectState.New;

        if (p.State == BusinessObjectState.Unmodified)
          p.Edit();

        if (p.TipPartnera == TipPartnera.Osoba)
        {
          osobaPanel.Visible = true;
          tvrtkaPanel.Visible = false;
          osobaPanel.BringToFront();
        }
        else if (p.TipPartnera == TipPartnera.Tvrtka)
        {
          tvrtkaPanel.Visible = true;
          osobaPanel.Visible = false;
          tvrtkaPanel.BringToFront();
        }
      }
    }

    private void partnerBindingSource_CurrentItemChanged(object sender, EventArgs e)
    {
      this.Text = "Partner";
      if (partnerBindingSource.Current != null)
      {
        this.Text = "Partner: " + ((Partner)partnerBindingSource.Current).ToString();
      }

      Partner p = partnerBindingSource.Current as Partner;
      if (p.TipPartnera == TipPartnera.Osoba)
      {
        osobaPanel.Visible = true;
        tvrtkaPanel.Visible = false;
        osobaPanel.BringToFront();
      }
      else if (p.TipPartnera == TipPartnera.Tvrtka)
      {
        tvrtkaPanel.Visible = true;
        osobaPanel.Visible = false;
        tvrtkaPanel.BringToFront();
      }
    }
    #endregion

    #region Ponašanje forme i kontrola
    private void ClearError()
    {
      partnerErrorProvider.Clear();
    }

    private void PartnerControlLeave(object sender, EventArgs e)
    {
      // Sa NULL vrijednostima osnovne .NET kontrole imaju problema.
      // Problem je što se brisanjem teksta neæe postaviti NULL odnosno string.Empty o odreðeni property

      // Ova metoda zaobilazi ovaj nedostatak koji je inaèe riješen u veæini 3rd party komponentama

      if (partnerBindingSource.Current != null)
      {
        if (sender is TextBox && string.IsNullOrEmpty((sender as TextBox).Text))
        {
          Utils.SetNull(sender as Control, "Text", partnerBindingSource.Current);
        }
        else if (sender is ComboBox && string.IsNullOrEmpty((sender as ComboBox).Text))
        {
          Utils.SetNull(sender as Control, "SelectedValue", partnerBindingSource.Current);
        }
      }
    }

    private void tvrtkaCheck_CheckedChanged(object sender, EventArgs e)
    {
      Partner p = partnerBindingSource.Current as Partner;
      if (p != null)
      {
        if (tvrtkaCheck.Checked)
        {
          p.TipPartnera = TipPartnera.Tvrtka;
        }
        else
        {
          p.TipPartnera = TipPartnera.Osoba;
        }
      }
    }
    #endregion

    #region Wizard Actions
    private void buttonCancel_Click(object sender, EventArgs e)
    {
      result = WizardResult.Cancel;
      this.Close();
    }

    private void buttonNext_Click(object sender, EventArgs e)
    {
      try
      {
        IList izmjene = ((PartnerList)partnerBindingSource.DataSource).GetChanges();
        if (izmjene != null && izmjene.Count > 0)
          partnerBll.SaveChanges(izmjene);

        foreach (Partner p in izmjene)
          p.Edit();

        result = WizardResult.Next;
        this.Close();
      }
      catch (Exception err)
      {
        MessageBox.Show(err.Message, "Pogreška", MessageBoxButtons.OK, MessageBoxIcon.Error);
      }
    }

    private void buttonPartner_Click(object sender, EventArgs e)
    {
      Partner p = partnerBindingSource.AddNew() as Partner;
      p.TipPartnera = TipPartnera.Osoba;
    }
    #endregion

    #region Business Object
    public Partner Partner
    {
      get
      {
        if (partnerBindingSource != null && partnerBindingSource.Current != null)
        {
          return partnerBindingSource.Current as Partner;
        }
        else
        {
          return null;
        }
      }
    }
    #endregion

    private void PartnerWizardForm_Activated(object sender, EventArgs e)
    {
      buttonCancel.Left = 560;
      buttonPrevious.Left = 452;
      buttonNext.Left = 316;
    }
  }
}