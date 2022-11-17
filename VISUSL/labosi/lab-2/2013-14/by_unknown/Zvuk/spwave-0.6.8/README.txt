
	spwave - a speech file editor.


Introduction
------------

spwave is a speech file editor supporting several sound formats including
WAV, AIFF, MP3, Ogg Vorbis, raw, and more. The program is designed for
research use, so stability and usability are regarded as important. spwave
runs on multiple platforms including Windows, Mac OS, and Linux.

spwave has the following features.

- Support for multiple platforms: Windows, Mac OS, Linux (Motif, gtk), etc.
- Support for WAV, AIFF, MP3, Ogg Vorbis, raw, and text files by using plug-ins.
- Support for many bits/samples: 8bits, 16bits, 24bits, 32bits, 32bits float, 64bits double.
- Converting the sampling frequency and the bits/sample of a file.
- Playing, zooming, cropping, deleting, extracting, etc. of a selected region.
- Fade-in, fade-out, gain adjustment, channel swapping, etc of a selected region.
- Editing file information that supports comments of WAV and AIFF, and ID3 tag of MP3.
- Analysis of a selected region using several analysis types,
  e.g. spectrum, smoothed spectrum, phase, unwrapped phase and group delay.
- Undoing and redoing without limitation of the number of times.
- Waveform extraction by drag & drop.


Install
-------

On Windows and Mac OS, you can install spwave just by unpacking the archive.
However, if you want to move the executable to another folder, you have to
move plug-ins with it. If you don't do that, spwave can load no files.
Linux version requires installing plug-ins (spPlugin 0.8.2 or higher) before
installing spwave.  Uninstallation can be done simply by removing files.


Usage
-----

You can run the Linux version with following command.

 % spwave

Windows and Mac OS version will start with double-clicking on the executable
binary. If you choose "Open..." menu in "File" menu, a dialog box to select
file will popup. The data format of the selected file will be autodetected
when it is a supported format. Otherwise, a dialog box to select data format
will popup, select suitable format. You can set region of the waveform by
dragging a mouse, and play sound with clicking the middle button of the
mouse. If your mouse is not 3 button mouse, the sound will be played with
choosing "Play Between Marks" menu which is created by clicking the right
button. On Mac OS, control+click and option+click mean the right button and
the middle button, respectively.

spwave accepts some command-line options listed below. Linux version will
display help messages with "-help" option. While the Windows version will not
show such help, command-line options have effect on the program. Almost all
of these parameters also can be set by the preference dialog. Mac OS version
does not support command-line options.

usage: spwave [options...] [filename...]
options:
    -f -freq ???                                    : sampling frequency for raw data [Hz]
    -c -channel ???                                 : number of channel for raw data
    -b -bit ???                                     : bits per sample for raw data
    -F -format ???                                  : file format for raw data (raw|swap|little|big|text)
    -play play_command                              : sound play command
    -useplay  (use_play[False])                     : use play command forcedly
    -buf audio_buffer_size                          : audio buffer size
    -tf -tformat time_format[0]                     : time format index (0-3)
    -label ???                                      : label file for first input file
    -reg                                            : label file specified by "-label" is region label
    -lf -lformat label_format[0]                    : label format index (0-12)
    -rf -rformat region_label_format[0]             : region label format index (0-11)
    -temp temp_dir[~/.spwave_tmp]                   : temporary directory
    -wavefg wave_fg[black]                          : wave foreground color
    -wavebg wave_bg[white]                          : wave background color
    -pointfg point_fg[red]                          : pointer foreground color
    -stringfg string_fg[red]                        : string foreground color
    -labelfg label_fg[blue]                         : label foreground color
    -scalefg scale_fg[grey50]                       : scale foreground color
    -width window_width[800]                        : window width
    -height window_height[200]                      : window height
    -fwidth freq_width[400]                         : window width for frequency data
    -fheight freq_height[300]                       : window height for frequency data
    -usedef  (use_default[False])                   : use default format when opening file
    -acswap  (alt_ctrl_swap[False])                 : alt-ctrl swap for shortcut keys
    -lreg  (link_region_label[False])               : link label to selection
    -info  (display_info_area[False])               : display information area
    -finfo  (display_freq_info_area[False])         : display frequency information area
    -debug ???                                      : debug level
    -h -help                                        : display this message


Supported Files
---------------

- Reading and Writing

  * Raw file (8bits PCM, 16bits PCM, 24bits PCM, 32bits PCM, 32bits float PCM, 
    64bits double PCM, ulaw, alaw)
  * WAV file (8bits PCM, 16bits PCM, 24bits PCM, 32bits PCM, ulaw, alaw)
  * AIFF file (8bits PCM, 16bits PCM, 24bits PCM, 32bits PCM)
  * AIFC file (8bits PCM, 16bits PCM, 24bits PCM, 32bits PCM, ulaw, alaw)
  * MP3 file (MPEG1 layer 3, writing MP3 requires another plugin package)
  * Ogg Vorbis file
  * AU/SND file (8bit PCM, 16bit PCM, 24bit PCM, 32bit PCM, ulaw, alaw, G721, G723)
  * PARIS file (16bit PCM, 24bit PCM)
  * NIST file (16bit PCM, 24bit PCM, 32bit PCM, ulaw, alaw)
  * IRCAM file (16bit PCM, 32bit PCM, ulaw, alaw)
  * Text file

- Reading Only

  * MP3 file (MPEG2 layer 3, also supports VBR)
  * RMP file (MPEG1 layer 3, MPEG2 layer 3, also supports VBR)


Supported Platforms
-------------------

spwave is known to work at least on Linux (Redhat 4.2 and Redhat 6.2), 
Microsoft Windows 98/2000/XP, Cygwin and Mac OS 8.1, 9.1 and 10.1.


Bugs
----

Motif version will be unstable when the version of 'kinput2' which is a
program to input Kanji on X client is old. This is caused by incompatibility
between Motif and kinput2. You can solve this promlem by upgrading kinput2 or
quitting kinput2. Another way to solve the problem is adding following line
to ~/.Xdefaults.

spwave*preeditType: none

If the memory assigned to spwave is not sufficient on Mac OS, spwave will
exit immediately with beep. In this case, you should assign more memory to
spwave before next execution. Shortcuts using the control key and the shift
key are not supported when the version of appearance is before 1.0.1. Also
there are problems that playing sound will be interrupted by displaing menus
and that turning on the virtual memory causes audible gaps. Writing Ogg
Vorbis files is currently not supported on Mac OS 9.

A level meter introduced from version 0.6.7 does not display exact amplitude.


Bug Report
----------

If you have questions or find bugs, please send me an e-mail. Please include
the following information when you report bugs.
 - Version of spwave (or the file name of the downloaded archive)
 - Version of the operating system (e.g. Windows 98 SE, Mac OS 8.1, etc. 
   Please write libc version if the OS is Linux)
 - Symptoms in delail
 - Version of the plugin if the bug is associated with a particular file. 
   e.g. the bug is related to writing MP3 files.

Including `spwave' in the subject of the e-mail is also helpful for me.


License
-------

spwave is free software. Please see LICENSE.txt included in the archive
for more information.


Official Site
-------------

The official web site is:
  http://www.itakura.nuee.nagoya-u.ac.jp/people/banno/spLibs/spwave/
  
You can download latest version and get information about bugs as well as
some FAQs from this site.


Thanks To
---------

spwave uses the following libraries. I'd like to thank developers of the
libraries.

  * AU/SND, PARIS, NIST, IRCAM, WAV ADPCM, ... (introduced from version 0.6.8)
    - libsndfile (http://www.zip.com.au/~erikd/libsndfile/)
      Reading and writing of many of above formats was made possible by
      libsndfile. Thanks Erik.

  * Ogg Vorbis (introduced from version 0.6.8)
    - libvorbis and libogg (http://www.vorbis.com/)
 
  * MP3 reading (included in spMpeg plugin package)
    - FreeAmp's (http://www.freeamp.org/) decoding engine 

I also would like to thank people who send me patches, bug reports, and
requests.


Hideki BANNO
E-mail: banno@itakura.nuee.nagoya-u.ac.jp
