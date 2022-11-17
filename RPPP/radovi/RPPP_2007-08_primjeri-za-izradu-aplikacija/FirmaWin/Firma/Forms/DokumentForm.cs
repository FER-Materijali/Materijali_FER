using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

using NTier;

namespace Firma
{
  // Forma dokumenta
  public partial class DokumentForm : BaseForm
  {
    #region Constructors & Init
    public DokumentForm()
    {
      InitializeComponent();

      // Dohvat svih partnera, artikala i dokumenata za lookup
      // Dohvat svih dokumenata
      partnerInfoBindingSource.DataSource = partnerBll.FetchAll();
      artiklBindingSource.DataSource = artiklBll.FetchAll();
      dokumentBindingSource.DataSource = dokumentBll.FetchAll();
      prethDokumentBindingSource.DataSource = dokumentBindingSource.DataSource;

      // Postavljanje stanja forme
      State = BusinessObjectState.Unmodified;

      // Povezivanje na objekte - programski radi definiranja formata prikaza
      postoPorezTextBox.DataBindings.Add(new Binding("Text", dokumentBindingSource, "PostoPorez", true, DataSourceUpdateMode.OnPropertyChanged, string.Empty, "p"));
      iznosDokumentaTextBox.DataBindings.Add(new Binding("Text", dokumentBindingSource, "IznosDokumenta", true, DataSourceUpdateMode.OnPropertyChanged, string.Empty, "C2"));
    }
    #endregion

    #region BLL Objects
    // BLL slojevi pojedinih klasa
    private DokumentBllProvider dokumentBll = new DokumentBllProvider();
    private PartnerBllProvider partnerBll = new PartnerBllProvider();
    private ArtiklBllProvider artiklBll = new ArtiklBllProvider();
    private StavkaBllProvider stavkaBll = new StavkaBllProvider();

    // Metoda preko koje æe poslovni objekt doæi do BLL sloja kako bi obavio validaciju unosa
    private IBllObject Dokument_NeedBllObject()
    {
      return dokumentBll;
    }

    // Metoda preko koje æe poslovni objekt doæi do BLL sloja kako bi obavio validaciju unosa
    private IBllObject Stavka_NeedBllObject()
    {
      return stavkaBll;
    }
    #endregion

    #region Dokument Changed
    // Osvježavanje unosa i pridruživanje metode za BLL objekt poslovnom objektu
    private void dokumentBindingSource_CurrentChanged(object sender, EventArgs e)
    {
      // as za razliku od obiène pretvorbe tipa neæe puknuti s InvalidCastException
      // ako tip nije ispravan nego æe vratiti null.
      Dokument d = dokumentBindingSource.Current as Dokument;

      // Ako se radi o novom poslovnom objektu 
      // koji još ne zna gdje mu je BLL objekt... ažuriraj.
      if (d != null)
      {
        if (!d.HasBllObject)
          d.NeedBllObject += new NeedBllObjectEventHandler(Dokument_NeedBllObject);
        
        // Alternativa je umjesto narednog retka staviti u Load forme 
        // DataSource na dokumentBindingsource a DataMember na Stavke
        // Nedostatak takvog pristupa je moguænost dodavanja praznog retka
        // u grid (CancelEdit ne funkcionira kako bi trebao).
        stavkaBindingSource.DataSource = d.Stavke;
      }
    }

    private void dokumentBindingSource_CurrentItemChanged(object sender, EventArgs e)
    {
      this.Text = "Dokument";
      if (dokumentBindingSource.Current != null)
      {
        this.Text = ((Dokument)dokumentBindingSource.Current).ToString();
      }
    }
    #endregion

    #region Stavka Changed
    // Osvježavanje unosa i pridruživanje metode za BLL objekt poslovnom objektu
    private void stavkaBindingSource_CurrentChanged(object sender, EventArgs e)
    {
      // as za razliku od obiène pretvorbe tipa neæe puknuti s InvalidCastException
      // ako tip nije ispravan nego æe vratiti null.
      Stavka s = stavkaBindingSource.Current as Stavka;

      // Ako se radi o novom poslovnom objektu koji još ne zna gdje mu
      // je BLL objekt... ažuriraj.
      if (s != null && !s.HasBllObject)
      {
        s.NeedBllObject += new NeedBllObjectEventHandler(Stavka_NeedBllObject);
      }
    }
    #endregion

    #region Ponašanje forme i kontrola
    // Obriši sve oznake za pogrešku
    private void ClearError()
    {
      dokumentErrorProvider.Clear();
      stavkaErrorProvider.Clear();

      StatusBar.IsError = false;
      StatusBar.Message = string.Empty;
    }

    // Izvodi se nakon što forma uðe u stanje izmjene
    protected override void AfterEdit()
    {
      base.AfterEdit();

      Dokument doc = (Dokument)dokumentBindingSource.Current;
      doc.ClearErrors();
      //foreach (Stavka s in doc.Stavke)
        //s.ClearErrors();
    }

    // Izvodi se nakon što forma uðe u stanje novog unosa
    protected override void AfterNew()
    {
      base.AfterNew();

      Dokument doc = (Dokument)dokumentBindingSource.Current;
      doc.ClearErrors();
      foreach (Stavka s in doc.Stavke)
        s.ClearErrors();
    }

    // Osvježavanje kontrola
    private void DokumentForm_PropertyChanged(object sender, PropertyChangedEventArgs e)
    {
      if (e.PropertyName.Equals("InEditMode"))
      {
        dokumentPanel.Enabled = InEditMode;
        stavkaBindingSource.AllowNew = InEditMode;
        stavkaDataGridView.ReadOnly = !InEditMode;
      }
      else if (e.PropertyName.Equals("State"))
      {
        brDokumentaTextBox.Enabled = vrDokumentaTextBox.Enabled = State == BusinessObjectState.New;

        if (State == BusinessObjectState.Unmodified)
        {
          dokumentErrorProvider.Clear();
          stavkaErrorProvider.Clear();
        }
      }
    }

    // Ako nema pogreške oèisti kontrolu, inaèe...
    private void DokumentControlEnter(object sender, EventArgs e)
    {
      if (InEditMode)
      {
        string error = dokumentErrorProvider.GetError(sender as Control);
        StatusBar.IsError = !string.IsNullOrEmpty(error);
        StatusBar.Message = error;
      }
      else
      {
        ClearError();
      }
    }

    private void DokumentControlLeave(object sender, EventArgs e)
    {
      // Brisanjem teksta neæe se automatski postaviti NULL odnosno string.Empty u odreðeni property
      // Ova metoda zaobilazi ovaj nedostatak .NETa koji je inaèe riješen u veæini 3rd party komponentama

      if (dokumentBindingSource.Current != null)
      {
        if (sender is TextBox && string.IsNullOrEmpty((sender as TextBox).Text))
        {
          Utils.SetNull(sender as Control, "Text", dokumentBindingSource.Current);
        }
      }

      StatusBar.IsError = false;
      StatusBar.Message = string.Empty;
    }

    protected override void Zoom()
    {
      if (InEditMode)
      {
        if (idPartneraComboBox.Focused)
        {
          PartnerForm f = new PartnerForm();
          f.StartPosition = FormStartPosition.CenterScreen;
          if (f.ShowDialog() == DialogResult.OK)
          {
            // Potrebno zbog bindinga na lookup u sluèaju novounesenih partnera
            partnerInfoBindingSource.DataSource = partnerBll.FetchAll();

            Partner p = (Partner)f.Selected;
            (dokumentBindingSource.Current as Dokument).IdPartnera = p.IdPartnera;
          }
        }
        else if (idPrethDokumentaComboBox.Focused)
        {
          DokumentForm f = new DokumentForm();
          f.StartPosition = FormStartPosition.CenterScreen;
          if (f.ShowDialog() == DialogResult.OK)
          {
            // Potrebno zbog bindinga na lookup u sluèaju novounesenih dokumenata
            prethDokumentBindingSource.DataSource = dokumentBll.FetchAll();

            Dokument d = (Dokument)f.Selected;
            (dokumentBindingSource.Current as Dokument).IdPrethDokumenta = d.IdDokumenta;
          }
        }
        else if (stavkaDataGridView.SelectedCells.Count == 1 
          && stavkaDataGridView.SelectedCells[0].ColumnIndex == 0 
          || stavkaDataGridView.SelectedCells[0].ColumnIndex == 1)
        {
          ArtiklForm f = new ArtiklForm();
          f.StartPosition = FormStartPosition.CenterScreen;
          if (f.ShowDialog() == DialogResult.OK)
          {
            // Potrebno zbog bindinga na lookup u sluèaju novounesenih artikala
            artiklBindingSource.DataSource = artiklBll.FetchAll();

            Artikl a = (Artikl)f.Selected;
            Stavka s = null;
            if (stavkaDataGridView.Rows[stavkaDataGridView.SelectedCells[0].RowIndex].IsNewRow)
            {
              stavkaBindingSource.CancelEdit();
              Dokument dok = (Dokument)dokumentBindingSource.Current;
              s = new Stavka();
              dok.Stavke.Add(s);
            }
            else
            {
              s = (Stavka)stavkaBindingSource.Current;
            }

            s.SifArtikla = a.SifArtikla;
            s.NazArtikla = a.NazArtikla;
            s.JedMjereArtikla = a.JedMjere;
            s.JedCijArtikla = a.CijArtikla;
          }
        }
        StatusBar.RefreshStatusBar();
      }
    }

    // Osvježavanje svojstava stavke. Ovo bi se inaèe trebalo raditi u poslovnom
    // objektu stavke ali to u ovom primjeru nije moguæe zbog jednostavnijeg dizajna frameworka
    private void stavkaDataGridView_CellValueChanged(object sender, DataGridViewCellEventArgs e)
    { 
      if (e.RowIndex == -1)
        return;

      if (e.ColumnIndex == 0 || e.ColumnIndex == 1)
      {
        try
        {
          // Šifra
          object sifArtikla = stavkaDataGridView[e.ColumnIndex, e.RowIndex].Value;
          if (sifArtikla != null)
          {
            Artikl a = artiklBll.Fetch((int)sifArtikla);
            if (a != null)
            {
              Stavka s = stavkaBindingSource.Current as Stavka;
              s.JedCijArtikla = a.CijArtikla;
              s.JedMjereArtikla = a.JedMjere;
            }
          }
        }
        catch (InvalidCastException)
        {
          // Nije unesena ispravna vrijednost. Zanemari. Validacija æe to uloviti.
        }
      }
    }
    #endregion

    #region Spremanje & brisanje
    // Spremanje svih izmjena
    protected override void DoSaveChanges()
    {
      dokumentBll.SaveChanges(((DokumentList)dokumentBindingSource.DataSource).GetChanges());
    }

    // Brisanje
    protected override void DoDelete()
    {
      // Uklanjanje poslovnog objekta iz liste dohvaæenih objekata (oznaèava objekt obrisanim)
      dokumentBindingSource.RemoveCurrent();
      // Sprema izmjene u bazu. Objekti oznaèeni za brisanje biti æe uklonjeni iz baze.
      dokumentBll.SaveChanges(((DokumentList)dokumentBindingSource.DataSource).GetChanges());
    }
    #endregion
  }
}