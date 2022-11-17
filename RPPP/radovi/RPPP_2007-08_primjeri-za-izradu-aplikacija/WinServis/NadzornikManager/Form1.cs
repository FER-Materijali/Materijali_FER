using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;
using System.ServiceProcess;
using System.Configuration;



namespace ZPR.ServiceDemo
{
  public partial class Form1 : Form
  {
    public Form1()
    {
      InitializeComponent();
    }

    private void Form1_Load(object sender, EventArgs e)
    {
      Hide();
      CheckServiceInstallation();
      UpdateServiceStatus();
    }

    private ServiceController nadzornikServis = null;

    private void CheckServiceInstallation()
    {
      ServiceController[] installedServices;
      installedServices = ServiceController.GetServices();
      foreach (ServiceController tmpService in installedServices)
      {
        if (tmpService.DisplayName == "NadzornikServis")
        {
          nadzornikServis = tmpService;
          return;
        }
      }
    }

    private void exitToolStripMenuItem_Click(object sender, EventArgs e)
    {
      Application.Exit();
    }

    void UpdateServiceStatus()
    {
      if (nadzornikServis != null)
      {
        nadzornikServis.Refresh();
        notifyIcon1.Text = "NadzornikServis status: " + nadzornikServis.Status.ToString();

        switch (nadzornikServis.Status)
        {
          case ServiceControllerStatus.Running:
            startToolStripMenuItem.Enabled = false;
            stopToolStripMenuItem.Enabled = true;
            pauseToolStripMenuItem.Enabled = true;
            continueToolStripMenuItem.Enabled = false;
            break;
          case ServiceControllerStatus.Stopped:
            startToolStripMenuItem.Enabled = true;
            stopToolStripMenuItem.Enabled = false;
            pauseToolStripMenuItem.Enabled = false;
            continueToolStripMenuItem.Enabled = false;
            break;
          case ServiceControllerStatus.Paused:
            startToolStripMenuItem.Enabled = false;
            stopToolStripMenuItem.Enabled = true;
            pauseToolStripMenuItem.Enabled = false;
            continueToolStripMenuItem.Enabled = true;
            break;
        }
      }
      else
      {
        notifyIcon1.Text = "NadzornikServis not installed";
        startToolStripMenuItem.Enabled = false;
        stopToolStripMenuItem.Enabled = false;
        pauseToolStripMenuItem.Enabled = false;
        continueToolStripMenuItem.Enabled = false;
        directoryToolStripMenuItem.Enabled = false;
      }
    }

    private string GetPath()
    {
      ExeConfigurationFileMap fileMap = new ExeConfigurationFileMap();
      fileMap.ExeConfigFilename = @"NadzornikServis.exe.config";

      System.Configuration.Configuration config = ConfigurationManager.OpenMappedExeConfiguration(fileMap, ConfigurationUserLevel.None);

      return config.AppSettings.Settings["Path"].Value.ToString();
    }

    private void startToolStripMenuItem_Click(object sender, EventArgs e)
    {
      try
      {
        nadzornikServis.Start();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
      finally
      {
        UpdateServiceStatus();
      }
    }

    private void stopToolStripMenuItem_Click(object sender, EventArgs e)
    {
      try
      {
        nadzornikServis.Stop();
      }
      catch (Exception ex)
      {
        MessageBox.Show("Došlo je do pogreške: " + ex.Message);
      }
      finally
      {
        UpdateServiceStatus();
      }
    }

    private void pauseToolStripMenuItem_Click(object sender, EventArgs e)
    {
      nadzornikServis.Pause();
      UpdateServiceStatus();
    }

    private void continueToolStripMenuItem_Click(object sender, EventArgs e)
    {
      nadzornikServis.Continue();
      UpdateServiceStatus();
    }

    private void notifyIcon1_MouseMove(object sender, MouseEventArgs e)
    {
      UpdateServiceStatus();
    }

    private void directoryToolStripMenuItem_Click(object sender, EventArgs e)
    {
      ExeConfigurationFileMap fileMap = new ExeConfigurationFileMap();
      fileMap.ExeConfigFilename = @"NadzornikServis.exe.config";
      System.Configuration.Configuration config = ConfigurationManager.OpenMappedExeConfiguration(fileMap, ConfigurationUserLevel.None);
      folderBrowserDialog1.SelectedPath = config.AppSettings.Settings["Path"].Value.ToString();
      folderBrowserDialog1.ShowDialog();
      config.AppSettings.Settings["Path"].Value = folderBrowserDialog1.SelectedPath.ToString();
      config.Save();
      //od 128-256. Manje od 128 su system reserved!            
      if (nadzornikServis.Status == ServiceControllerStatus.Running)
        nadzornikServis.ExecuteCommand(128);
    }
  }
}