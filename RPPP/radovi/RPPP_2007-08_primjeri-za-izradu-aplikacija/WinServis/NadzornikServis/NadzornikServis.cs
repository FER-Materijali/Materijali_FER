using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.ServiceProcess;
using System.Text;
using System.Configuration;

namespace ZPR.ServiceDemo
{
  public partial class NadzornikServis : ServiceBase
  {
    bool isPaused;

    public NadzornikServis()
    {
      InitializeComponent();
    }

    protected override void OnShutdown()
    {
      // Treat the service being stopped.
      this.OnStop();
    }

    protected override void OnStart(string[] args)
    {
      isPaused = false;
      SetPath();
      fileSystemWatcher1.EnableRaisingEvents = true;
      EventLog.WriteEntry("NadzornikServis: STARTED at " + DateTime.Now.ToShortTimeString());
    }

    protected override void OnStop()
    {
      // Add code here to perform any tear-down necessary to stop your service.
      // Calculate the necessary times. if the Service is not currently paused
      //   the timeElapsed must be changed to consider the time its been
      //   running since a start or continue.
      fileSystemWatcher1.EnableRaisingEvents = false;
      EventLog.WriteEntry("NadzornikServis: STOPPED at " + DateTime.Now.ToShortTimeString());
    }

    protected override void OnContinue()
    {
      // Begin measuring the elapsed time. This means setting the
      //   timeStart back to the current time, and resetting isPaused
      //   to false  
      base.OnContinue();
      if (isPaused)
      {
        fileSystemWatcher1.EnableRaisingEvents = true;
        SetPath();
        EventLog.WriteEntry("NadzornikServis: CONTINUED at " + DateTime.Now.ToShortTimeString());
      }
    }

    // OnPause occurs when the user asks a running Service to pause. In order 
    //   for this method to be called the CanPauseAndContinue property must be 
    //   set to true. (It is false by default.)
    protected override void OnPause()
    {
      // Save the time that's elapsed so far in timeElapsed,
      //   and wait for the user to either Stop the service or 
      //   resume it.
      base.OnPause();
      if (!isPaused)
      {
        fileSystemWatcher1.EnableRaisingEvents = false;
        EventLog.WriteEntry("NadzornikServis: PAUSED at " + DateTime.Now.ToShortTimeString());
      }
      isPaused = true;
    }

    private void fileSystemWatcher1_Changed(object sender, System.IO.FileSystemEventArgs e)
    {
      EventLog.WriteEntry("NadzornikServis: " + e.FullPath + " " + e.ChangeType.ToString());
    }

    private void fileSystemWatcher1_Renamed(object sender, System.IO.RenamedEventArgs e)
    {
      EventLog.WriteEntry("NadzornikServis: " + e.OldFullPath + " RENAMED TO " + e.FullPath);
    }

    protected override void OnCustomCommand(int command)
    {
      base.OnCustomCommand(command);
      if (command == 128)
      {
        SetPath();
      }
    }

    private void SetPath()
    {
      ConfigurationManager.RefreshSection("appSettings");
      fileSystemWatcher1.Path = ConfigurationManager.AppSettings["Path"].ToString();
      EventLog.WriteEntry("NadzornikServis: WATCHING - " + fileSystemWatcher1.Path);
    }
  }
}
