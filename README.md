# CErrLook
Tiny command-line tool which goal is to slightly improve existing ErrLook tool from Microsoft.

When using from `cmd.exe` change codepage to your system one to make error messages readable. Example for Russian:

```
C:\Users\developer\cerrlook\build>cerrlook.exe 0xc0000005
Dec:    -1073741819
Hex:    0xC0000005
Module: <system>
Text:   ╬Єърчрэю т фюёЄєях.


C:\Users\developer\cerrlook\build>chcp 1251
Текущая кодовая страница: 1251

C:\Users\developer\cerrlook\build>cerrlook.exe 0xc0000005
Dec:    -1073741819
Hex:    0xC0000005
Module: <system>
Text:   Отказано в доступе.
```

You can specify modules on command-line to resolve error codes which not a part of the system:

```
C:\Users\developer\cerrlook\build>cerrlook.exe 12007
Can't get message for code '12007': 0x0000013D

C:\Users\developer\cerrlook\build>cerrlook.exe wininet 12007
Dec:    12007
Hex:    0x00002EE7
Module: wininet
Text:   The server name could not be resolved.
```

It accepts codes both in decimal and hexadecimal forms:

```
C:\Users\developer\cerrlook\build>cerrlook.exe wininet 12007
Dec:    12007
Hex:    0x00002EE7
Module: wininet
Text:   The server name could not be resolved.

C:\Users\developer\cerrlook\build>cerrlook.exe wininet 0x00002EE7
Dec:    12007
Hex:    0x00002EE7
Module: wininet
Text:   The server name could not be resolved.
```