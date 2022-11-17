
	spwave - 音声ファイルエディタ


はじめに
--------

spwaveは，WAV，AIFF，MP3，Ogg Vorbisなど様々なフォーマットに対応した音声
ファイルエディタです．音声の研究に用いることを前提としており，使いやすく，
安定したプログラムを目指しています．また，spwave は，マルチプラットホーム
に対応しており，Windows，Mac OS，Linuxなどで動作します．

spwaveは，次のような特徴を持っています．

- マルチプラットホーム: Windows，Mac OS，Linux（Motif，gtk）など
- プラグインを用いた入出力による様々なフォーマットへの対応
  （WAV，AIFF，MP3，Ogg Vorbis，rawなど）
- 対応するビット/サンプルは，8bit，16bit，24bit，32bit，32bit float，64bit double
- サンプリング周波数やビット/サンプルの変換
- 任意区間の再生，拡大，切り出し，削除，取り出し
- 任意区間のフェードイン，フェードアウト，ゲイン調節，チャネル入れ換え
- ファイル情報の編集（WAVファイルやAIFFファイルのコメントや，MP3のID3タグに対応）
- 回数ほぼ無制限のアンドゥーとリドゥー
- 任意区間の様々な方式（スペクトル，平滑化スペクトル，位相アンラップド位相，群遅延）での分析
- ドラッグ&ドロップによる指定範囲の取り出し


インストール
------------

Windows，Mac OSでのバイナリパッケージのインストールは基本的にアーカイブを解凍
するだけです．ただし，実行ファイルを移動させるときは，必ずプラグインも同じ
フォルダ構成で移動させて下さい．実行ファイル単体だけを移動した場合には，起動は
しますがファイルが全く読み込めなくなります．Linuxでは，プラグイン（spPlugin 
0.8.2以上）のインストールが別途必要となります．アンインストールはファイルを
削除するだけです．


使用方法
--------

起動方法は，Linux版では，コマンドラインから，

 % spwave

と打ち込んで下さい．WindowsとMac OSでは，実行ファイルをダブルクリックして
下さい．すると，メインウィンドウが開きます．ファイルメニューから，"開く"
を選ぶと，ダイアログが開きますので，読み込みたいファイルを指定して下さい．
サポートされているファイルの場合は，フォーマットを自動判定して読み込みます．
それ以外のファイルでは，フォーマットを選択するダイアログが開きますので，
適切なフォーマットを選択して下さい．波形の範囲指定はマウスのドラッグにより
可能で，マウスが3つボタンの場合は，中ボタンで再生することができます．
3つボタンでない場合は，マウスの右ボタンをクリックすると，メニューが
開きますので，そこから"指定範囲を再生"を選択して下さい．なお，Mac OSでは
Control+クリックとOption+クリックがそれぞれ右ボタンと中ボタンを意味します．

また，コマンドラインオプションも結構用意されています．Linux版では，
-help オプションを付けて起動すると，コマンドラインオプションのリストが
表示されます（Windows版では，DOS窓から -help を付けて起動してもリストは
でませんが，プログラムには反映されます）．オプションによって設定できる
パラメータのほとんどは設定ダイアログによっても変更することができます．
なお，Mac OSではコマンドラインオプションはサポートされていません．
以下がコマンドラインオプションのリストです．

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


対応ファイル一覧
----------------

- 読み込み & 書き込み

  書き込みの際の，WAVファイルやAIFFファイルのコメント，MP3ファイルのID3タグに対応しています

  * Rawファイル（8bit PCM，16bit PCM，24bit PCM，32bit PCM，32bit float PCM，
    64bit double PCM，ulaw，alaw）
  * WAVファイル（8bit PCM，16bit PCM，24bit PCM，32bit PCM，ulaw，alaw）
  * AIFFファイル（8bit PCM，16bit PCM，24bit PCM，32bit PCM）
  * AIFCファイル（8bit PCM，16bit PCM，24bit PCM，32bit PCM，ulaw，alaw）
  * MP3ファイル（MPEG1 layer 3，書き込みには別途プラグインのダウンロードが必要です）
  * Ogg Vorbisファイル
  * AU/SNDファイル（8bit PCM, 16bit PCM, 24bit PCM, 32bit PCM, ulaw, alaw, G721, G723）
  * PARISファイル（16bit PCM, 24bit PCM）
  * NISTファイル（16bit PCM, 24bit PCM, 32bit PCM, ulaw, alaw）
  * IRCAMファイル（16bit PCM, 32bit PCM, ulaw, alaw）
  * テキストファイル

- 読み込みのみ

  * MP3ファイル（MPEG2 layer 3，VBRも可）
  * RMPファイル（MPEG1 layer 3，MPEG2 layer 3，VBRも可）


動作確認
--------

現在の所，Linux（Redhat 4.2, Redhat 6.2），Microsoft Windows 98/2000/XP，
Cygwin，Mac OS 8.1，9.1，10.1などでの動作が確認されています．


バグ
----

Motif版では，kinput2が立ち上がっていて，そのkinput2のバージョンが古いと，
不安定になります．これは，Motifとkinput2の相性の問題のようです．その場合は，
kinput2のバージョンを上げるか，kinput2を終了させて下さい．もしくは，
~/.Xdefaults などに，

spwave*preeditType: none

と書けば直ると思います．また，Unix環境で，LANGがja_JP.SJISの場合，ほとんどの
環境で部分的に文字化けします．これは，gccでSJISを含むファイルをコンパイル
したときの現象のようです．というわけで，Unix環境では，ja_JP.SJISを
使わないことをおすすめします．

GTKバージョンを使用している人で，日本語が化ける場合は，ホームディレクトリに
".gtkrc"を作成して下さい．".gtkrc"の作成方法は，GIMPを起動したことがある人は，

  % cp ~/.gimp/gtkrc ~/.gtkrc

とすれば作成できます．

Mac OS版では，spwaveに割り当てられたメモリーが足りない場合は，ビープ音とともに
終了してしまいます．そのような場合には，より多くのメモリーを割り当てて下さい．
また，アピアランス1.0.1がサポートされていない環境では，コントロールキー及び
シフトキーを使ったショートカットが使用できません．さらに，現在のバージョンでは，
メニューを表示すると音声の再生が停止してしまうという問題点もあります．また，
仮想メモリがオンになっていると，音飛びが発生しやすくなります．それから，Mac 
OS 9以下において，Ogg Vorbisの書き込みは，サポートしていません．

また，バージョン0.6.7からはレベルメーターが付きましたが，時間の同期と値はあまり
正確ではないので注意して下さい．


質問やバグ報告
--------------

質問がある場合やバグを発見した場合，ぜひ電子メールで連絡下さい．ただし，質問の
場合，この文書やホームページに載っていることに関しては，返事を出せないかもしれ
ません．あと，返事は遅れることも結構ありますので（ごめんなさい），そんなときは
気長に待っていて下さい．また，返事をせずに回答だけをホームページに掲載すること
もたまにありますので（同様の質問が短期間に集中した場合など），そんなときは，
再度ホームページをチェックしてみるのも良いかもしれません．

バグ報告の際は，できるだけ以下の項目は記述して下さい．

 - spwaveのバージョン（0.6.5-1など．ダウンロードしたアーカイブ名でも構いません）
 - OSのバージョン（Windows98 SE，Mac OS 8.1など．Linuxの場合はlibcのバージョンも書いてください）
 - 症状（何をするとどうなるのかをできるだけ詳しくお願いします）
 - プラグインのバージョン（特定のファイルの読み書きに関するバグの場合．
   例えばMP3出力プラグインのバグなど）

また，サブジェクトにspwaveの文字を入れて頂けると助かります．


ライセンス
----------

spwaveはフリーソフトウェアです．詳しくは，アーカイブに含まれている
LICENSE.txtを見て下さい．


オフィシャルサイト
------------------

オフィシャルサイトは，

  http://www.itakura.nuee.nagoya-u.ac.jp/people/banno/spLibs/spwave/index-j.html

です．最新版のダウンロードやバグに関する最新情報を得ることができます．よくある
質問に対する回答も掲載してありますので，問題が発生した場合はまずこちらを見る
ことをお勧めします．


Thanks To
---------

ファイルの読み書きには以下のライブラリが使用されています．それぞれのライブラリを
開発し，公開されている方に感謝致します．

  * AU/SND, PARIS, NIST, IRCAM, WAV ADPCM, ... (バージョン0.6.8から)
    - libsndfile (http://www.zip.com.au/~erikd/libsndfile/)
      上記のフォーマットの読み書きはこのlibsndfileによって可能になりました．
      開発者のErikさん，いろいろとありがとうございます．

  * Ogg Vorbis (バージョン0.6.8から)
    - libvorbis と libogg (http://www.vorbis.com/)

  * MP3読み込み (spMpegのプラグインに含まれています)
    - FreeAmp(http://www.freeamp.org/)のデコードエンジン

また，パッチを作成して下さった方，バグ報告や要望などを送って下さった方，
ありがとうございました．今後ともよろしくお願いします．


坂野秀樹（Banno Hideki）
E-mail: banno@itakura.nuee.nagoya-u.ac.jp
