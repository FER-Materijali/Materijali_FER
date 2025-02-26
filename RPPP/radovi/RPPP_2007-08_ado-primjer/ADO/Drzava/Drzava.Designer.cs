namespace Drzava
{
  partial class DrzavaForm
  {
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private System.ComponentModel.IContainer components = null;

    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
    protected override void Dispose(bool disposing)
    {
      if (disposing && (components != null))
      {
        components.Dispose();
      }
      base.Dispose(disposing);
    }

    #region Windows Form Designer generated code

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    private void InitializeComponent()
    {
        this.components = new System.ComponentModel.Container();
        System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(DrzavaForm));
        this.firmaDataSet = new UnosDrzava.FirmaDataSet();
        this.drzavaBindingSource = new System.Windows.Forms.BindingSource(this.components);
        this.drzavaTableAdapter = new UnosDrzava.FirmaDataSetTableAdapters.DrzavaTableAdapter();
        this.drzavaBindingNavigator = new System.Windows.Forms.BindingNavigator(this.components);
        this.bindingNavigatorAddNewItem = new System.Windows.Forms.ToolStripButton();
        this.bindingNavigatorCountItem = new System.Windows.Forms.ToolStripLabel();
        this.bindingNavigatorDeleteItem = new System.Windows.Forms.ToolStripButton();
        this.bindingNavigatorMoveFirstItem = new System.Windows.Forms.ToolStripButton();
        this.bindingNavigatorMovePreviousItem = new System.Windows.Forms.ToolStripButton();
        this.bindingNavigatorSeparator = new System.Windows.Forms.ToolStripSeparator();
        this.bindingNavigatorPositionItem = new System.Windows.Forms.ToolStripTextBox();
        this.bindingNavigatorSeparator1 = new System.Windows.Forms.ToolStripSeparator();
        this.bindingNavigatorMoveNextItem = new System.Windows.Forms.ToolStripButton();
        this.bindingNavigatorMoveLastItem = new System.Windows.Forms.ToolStripButton();
        this.bindingNavigatorSeparator2 = new System.Windows.Forms.ToolStripSeparator();
        this.drzavaBindingNavigatorSaveItem = new System.Windows.Forms.ToolStripButton();
        this.toolStripButtonLoad = new System.Windows.Forms.ToolStripButton();
        this.toolStripButtonCancel = new System.Windows.Forms.ToolStripButton();
        this.drzavaDataGridView = new System.Windows.Forms.DataGridView();
        this.oznDrzaveDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        this.nazDrzaveDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        this.iSO3DrzaveDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        this.sifDrzaveDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
        ((System.ComponentModel.ISupportInitialize)(this.firmaDataSet)).BeginInit();
        ((System.ComponentModel.ISupportInitialize)(this.drzavaBindingSource)).BeginInit();
        ((System.ComponentModel.ISupportInitialize)(this.drzavaBindingNavigator)).BeginInit();
        this.drzavaBindingNavigator.SuspendLayout();
        ((System.ComponentModel.ISupportInitialize)(this.drzavaDataGridView)).BeginInit();
        this.SuspendLayout();
        // 
        // firmaDataSet
        // 
        this.firmaDataSet.DataSetName = "FirmaDataSet";
        this.firmaDataSet.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
        // 
        // drzavaBindingSource
        // 
        this.drzavaBindingSource.DataMember = "Drzava";
        this.drzavaBindingSource.DataSource = this.firmaDataSet;
        // 
        // drzavaTableAdapter
        // 
        this.drzavaTableAdapter.ClearBeforeFill = true;
        // 
        // drzavaBindingNavigator
        // 
        this.drzavaBindingNavigator.AddNewItem = this.bindingNavigatorAddNewItem;
        this.drzavaBindingNavigator.BindingSource = this.drzavaBindingSource;
        this.drzavaBindingNavigator.CountItem = this.bindingNavigatorCountItem;
        this.drzavaBindingNavigator.DeleteItem = this.bindingNavigatorDeleteItem;
        this.drzavaBindingNavigator.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.bindingNavigatorMoveFirstItem,
            this.bindingNavigatorMovePreviousItem,
            this.bindingNavigatorSeparator,
            this.bindingNavigatorPositionItem,
            this.bindingNavigatorCountItem,
            this.bindingNavigatorSeparator1,
            this.bindingNavigatorMoveNextItem,
            this.bindingNavigatorMoveLastItem,
            this.bindingNavigatorSeparator2,
            this.bindingNavigatorAddNewItem,
            this.bindingNavigatorDeleteItem,
            this.drzavaBindingNavigatorSaveItem,
            this.toolStripButtonLoad,
            this.toolStripButtonCancel});
        this.drzavaBindingNavigator.Location = new System.Drawing.Point(0, 0);
        this.drzavaBindingNavigator.MoveFirstItem = this.bindingNavigatorMoveFirstItem;
        this.drzavaBindingNavigator.MoveLastItem = this.bindingNavigatorMoveLastItem;
        this.drzavaBindingNavigator.MoveNextItem = this.bindingNavigatorMoveNextItem;
        this.drzavaBindingNavigator.MovePreviousItem = this.bindingNavigatorMovePreviousItem;
        this.drzavaBindingNavigator.Name = "drzavaBindingNavigator";
        this.drzavaBindingNavigator.PositionItem = this.bindingNavigatorPositionItem;
        this.drzavaBindingNavigator.Size = new System.Drawing.Size(479, 25);
        this.drzavaBindingNavigator.TabIndex = 0;
        this.drzavaBindingNavigator.Text = "bindingNavigator1";
        this.drzavaBindingNavigator.RefreshItems += new System.EventHandler(this.drzavaBindingNavigator_RefreshItems);
        // 
        // bindingNavigatorAddNewItem
        // 
        this.bindingNavigatorAddNewItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        this.bindingNavigatorAddNewItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorAddNewItem.Image")));
        this.bindingNavigatorAddNewItem.Name = "bindingNavigatorAddNewItem";
        this.bindingNavigatorAddNewItem.RightToLeftAutoMirrorImage = true;
        this.bindingNavigatorAddNewItem.Size = new System.Drawing.Size(23, 22);
        this.bindingNavigatorAddNewItem.Text = "Add new";
        // 
        // bindingNavigatorCountItem
        // 
        this.bindingNavigatorCountItem.Name = "bindingNavigatorCountItem";
        this.bindingNavigatorCountItem.Size = new System.Drawing.Size(36, 22);
        this.bindingNavigatorCountItem.Text = "of {0}";
        this.bindingNavigatorCountItem.ToolTipText = "Total number of items";
        // 
        // bindingNavigatorDeleteItem
        // 
        this.bindingNavigatorDeleteItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        this.bindingNavigatorDeleteItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorDeleteItem.Image")));
        this.bindingNavigatorDeleteItem.Name = "bindingNavigatorDeleteItem";
        this.bindingNavigatorDeleteItem.RightToLeftAutoMirrorImage = true;
        this.bindingNavigatorDeleteItem.Size = new System.Drawing.Size(23, 22);
        this.bindingNavigatorDeleteItem.Text = "Delete";
        // 
        // bindingNavigatorMoveFirstItem
        // 
        this.bindingNavigatorMoveFirstItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        this.bindingNavigatorMoveFirstItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveFirstItem.Image")));
        this.bindingNavigatorMoveFirstItem.Name = "bindingNavigatorMoveFirstItem";
        this.bindingNavigatorMoveFirstItem.RightToLeftAutoMirrorImage = true;
        this.bindingNavigatorMoveFirstItem.Size = new System.Drawing.Size(23, 22);
        this.bindingNavigatorMoveFirstItem.Text = "Move first";
        // 
        // bindingNavigatorMovePreviousItem
        // 
        this.bindingNavigatorMovePreviousItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        this.bindingNavigatorMovePreviousItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMovePreviousItem.Image")));
        this.bindingNavigatorMovePreviousItem.Name = "bindingNavigatorMovePreviousItem";
        this.bindingNavigatorMovePreviousItem.RightToLeftAutoMirrorImage = true;
        this.bindingNavigatorMovePreviousItem.Size = new System.Drawing.Size(23, 22);
        this.bindingNavigatorMovePreviousItem.Text = "Move previous";
        // 
        // bindingNavigatorSeparator
        // 
        this.bindingNavigatorSeparator.Name = "bindingNavigatorSeparator";
        this.bindingNavigatorSeparator.Size = new System.Drawing.Size(6, 25);
        // 
        // bindingNavigatorPositionItem
        // 
        this.bindingNavigatorPositionItem.AccessibleName = "Position";
        this.bindingNavigatorPositionItem.AutoSize = false;
        this.bindingNavigatorPositionItem.Name = "bindingNavigatorPositionItem";
        this.bindingNavigatorPositionItem.Size = new System.Drawing.Size(50, 21);
        this.bindingNavigatorPositionItem.Text = "0";
        this.bindingNavigatorPositionItem.ToolTipText = "Current position";
        // 
        // bindingNavigatorSeparator1
        // 
        this.bindingNavigatorSeparator1.Name = "bindingNavigatorSeparator1";
        this.bindingNavigatorSeparator1.Size = new System.Drawing.Size(6, 25);
        // 
        // bindingNavigatorMoveNextItem
        // 
        this.bindingNavigatorMoveNextItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        this.bindingNavigatorMoveNextItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveNextItem.Image")));
        this.bindingNavigatorMoveNextItem.Name = "bindingNavigatorMoveNextItem";
        this.bindingNavigatorMoveNextItem.RightToLeftAutoMirrorImage = true;
        this.bindingNavigatorMoveNextItem.Size = new System.Drawing.Size(23, 22);
        this.bindingNavigatorMoveNextItem.Text = "Move next";
        // 
        // bindingNavigatorMoveLastItem
        // 
        this.bindingNavigatorMoveLastItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        this.bindingNavigatorMoveLastItem.Image = ((System.Drawing.Image)(resources.GetObject("bindingNavigatorMoveLastItem.Image")));
        this.bindingNavigatorMoveLastItem.Name = "bindingNavigatorMoveLastItem";
        this.bindingNavigatorMoveLastItem.RightToLeftAutoMirrorImage = true;
        this.bindingNavigatorMoveLastItem.Size = new System.Drawing.Size(23, 22);
        this.bindingNavigatorMoveLastItem.Text = "Move last";
        // 
        // bindingNavigatorSeparator2
        // 
        this.bindingNavigatorSeparator2.Name = "bindingNavigatorSeparator2";
        this.bindingNavigatorSeparator2.Size = new System.Drawing.Size(6, 25);
        // 
        // drzavaBindingNavigatorSaveItem
        // 
        this.drzavaBindingNavigatorSaveItem.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Image;
        this.drzavaBindingNavigatorSaveItem.Image = ((System.Drawing.Image)(resources.GetObject("drzavaBindingNavigatorSaveItem.Image")));
        this.drzavaBindingNavigatorSaveItem.Name = "drzavaBindingNavigatorSaveItem";
        this.drzavaBindingNavigatorSaveItem.Size = new System.Drawing.Size(23, 22);
        this.drzavaBindingNavigatorSaveItem.Text = "Save Data";
        this.drzavaBindingNavigatorSaveItem.Click += new System.EventHandler(this.drzavaBindingNavigatorSaveItem_Click);
        // 
        // toolStripButtonLoad
        // 
        this.toolStripButtonLoad.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
        this.toolStripButtonLoad.ImageTransparentColor = System.Drawing.Color.Magenta;
        this.toolStripButtonLoad.Name = "toolStripButtonLoad";
        this.toolStripButtonLoad.Size = new System.Drawing.Size(78, 22);
        this.toolStripButtonLoad.Text = "Napuni (Load)";
        this.toolStripButtonLoad.Click += new System.EventHandler(this.toolStripButtonLoad_Click);
        // 
        // toolStripButtonCancel
        // 
        this.toolStripButtonCancel.DisplayStyle = System.Windows.Forms.ToolStripItemDisplayStyle.Text;
        this.toolStripButtonCancel.Image = ((System.Drawing.Image)(resources.GetObject("toolStripButtonCancel.Image")));
        this.toolStripButtonCancel.ImageTransparentColor = System.Drawing.Color.Magenta;
        this.toolStripButtonCancel.Name = "toolStripButtonCancel";
        this.toolStripButtonCancel.Size = new System.Drawing.Size(87, 22);
        this.toolStripButtonCancel.Text = "Opoziv (Cancel)";
        this.toolStripButtonCancel.Click += new System.EventHandler(this.toolStripButtonCancel_Click);
        // 
        // drzavaDataGridView
        // 
        this.drzavaDataGridView.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                    | System.Windows.Forms.AnchorStyles.Left)
                    | System.Windows.Forms.AnchorStyles.Right)));
        this.drzavaDataGridView.AutoGenerateColumns = false;
        this.drzavaDataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.oznDrzaveDataGridViewTextBoxColumn,
            this.nazDrzaveDataGridViewTextBoxColumn,
            this.iSO3DrzaveDataGridViewTextBoxColumn,
            this.sifDrzaveDataGridViewTextBoxColumn});
        this.drzavaDataGridView.DataSource = this.drzavaBindingSource;
        this.drzavaDataGridView.Location = new System.Drawing.Point(0, 28);
        this.drzavaDataGridView.Name = "drzavaDataGridView";
        this.drzavaDataGridView.Size = new System.Drawing.Size(479, 313);
        this.drzavaDataGridView.TabIndex = 1;
        // 
        // oznDrzaveDataGridViewTextBoxColumn
        // 
        this.oznDrzaveDataGridViewTextBoxColumn.DataPropertyName = "OznDrzave";
        this.oznDrzaveDataGridViewTextBoxColumn.HeaderText = "OznDrzave";
        this.oznDrzaveDataGridViewTextBoxColumn.Name = "oznDrzaveDataGridViewTextBoxColumn";
        // 
        // nazDrzaveDataGridViewTextBoxColumn
        // 
        this.nazDrzaveDataGridViewTextBoxColumn.DataPropertyName = "NazDrzave";
        this.nazDrzaveDataGridViewTextBoxColumn.HeaderText = "NazDrzave";
        this.nazDrzaveDataGridViewTextBoxColumn.Name = "nazDrzaveDataGridViewTextBoxColumn";
        // 
        // iSO3DrzaveDataGridViewTextBoxColumn
        // 
        this.iSO3DrzaveDataGridViewTextBoxColumn.DataPropertyName = "ISO3Drzave";
        this.iSO3DrzaveDataGridViewTextBoxColumn.HeaderText = "ISO3Drzave";
        this.iSO3DrzaveDataGridViewTextBoxColumn.Name = "iSO3DrzaveDataGridViewTextBoxColumn";
        // 
        // sifDrzaveDataGridViewTextBoxColumn
        // 
        this.sifDrzaveDataGridViewTextBoxColumn.DataPropertyName = "SifDrzave";
        this.sifDrzaveDataGridViewTextBoxColumn.HeaderText = "SifDrzave";
        this.sifDrzaveDataGridViewTextBoxColumn.Name = "sifDrzaveDataGridViewTextBoxColumn";
        // 
        // DrzavaForm
        // 
        this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.ClientSize = new System.Drawing.Size(479, 344);
        this.Controls.Add(this.drzavaDataGridView);
        this.Controls.Add(this.drzavaBindingNavigator);
        this.Name = "DrzavaForm";
        this.Text = "Dr�ava";
        this.Load += new System.EventHandler(this.DrzavaForm_Load);
        ((System.ComponentModel.ISupportInitialize)(this.firmaDataSet)).EndInit();
        ((System.ComponentModel.ISupportInitialize)(this.drzavaBindingSource)).EndInit();
        ((System.ComponentModel.ISupportInitialize)(this.drzavaBindingNavigator)).EndInit();
        this.drzavaBindingNavigator.ResumeLayout(false);
        this.drzavaBindingNavigator.PerformLayout();
        ((System.ComponentModel.ISupportInitialize)(this.drzavaDataGridView)).EndInit();
        this.ResumeLayout(false);
        this.PerformLayout();

    }

    #endregion

    private UnosDrzava.FirmaDataSet firmaDataSet;
    private System.Windows.Forms.BindingSource drzavaBindingSource;
    private UnosDrzava.FirmaDataSetTableAdapters.DrzavaTableAdapter drzavaTableAdapter;
    private System.Windows.Forms.BindingNavigator drzavaBindingNavigator;
    private System.Windows.Forms.ToolStripButton bindingNavigatorAddNewItem;
    private System.Windows.Forms.ToolStripLabel bindingNavigatorCountItem;
    private System.Windows.Forms.ToolStripButton bindingNavigatorDeleteItem;
    private System.Windows.Forms.ToolStripButton bindingNavigatorMoveFirstItem;
    private System.Windows.Forms.ToolStripButton bindingNavigatorMovePreviousItem;
    private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator;
    private System.Windows.Forms.ToolStripTextBox bindingNavigatorPositionItem;
    private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator1;
    private System.Windows.Forms.ToolStripButton bindingNavigatorMoveNextItem;
    private System.Windows.Forms.ToolStripButton bindingNavigatorMoveLastItem;
    private System.Windows.Forms.ToolStripSeparator bindingNavigatorSeparator2;
    private System.Windows.Forms.ToolStripButton drzavaBindingNavigatorSaveItem;
    private System.Windows.Forms.DataGridView drzavaDataGridView;
    private System.Windows.Forms.DataGridViewTextBoxColumn oznDrzaveDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn nazDrzaveDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn iSO3DrzaveDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn sifDrzaveDataGridViewTextBoxColumn;
    private System.Windows.Forms.ToolStripButton toolStripButtonLoad;
    private System.Windows.Forms.ToolStripButton toolStripButtonCancel;
  }
}

