## Overview

Windows 10 consoles support [virtual terminal sequences](https://msdn.microsoft.com/en-us/library/windows/desktop/mt638032.aspx)
which enable programs to output colored text (among other things). It
is an opt-in feature, which means that the process that wants to use
it must explicitly enable it for itself.

The default command processor (cmd.exe) has it turned on, so it is
possible to `echo` the sequences. It used to be that programs which
ran from within cmd.exe inherited it and did not have to enable it
explicitly.

The Anniversary Update [changed this behavior](https://wpdev.uservoice.com/forums/266908-command-prompt-console-bash-on-ubuntu-on-windo/suggestions/15617610--re-enable-enable-virtual-terminal-processing-by)
and as a result, programs which expect this feature by default,
namely those from the [GnuWin](http://gnuwin32.sourceforge.net/)
project, stopped working inside cmd.exe.

Interestingly, cmd.exe will pass the flag to child processes, if it
is started with the flag already turned on.

**vtcmd** is a shim which turns on the flag and starts cmd.exe, so you
can again use those programs which don't enable it themselves.

## Usage

1. Build it with Visual Studio
2. Run `vtcmd.exe`

Consider modifying your shortcuts. The ones used in the `Win+X` menu are located in `%LOCALAPPDATA%\Microsoft\Windows\WinX\Group3`.
