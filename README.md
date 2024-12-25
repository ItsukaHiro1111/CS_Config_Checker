# CS_Config_Checker
Very simple C++ program to check if your "autoexec.cfg" has any conflict line (same command, same button, same bind, same alias)

# How to use
- Download EXE File from Release
- Scan virus, incase you want. Note that the the result can be false positive, as I didnt sign the file, just compile using TDM-GCC 9.2.0 32bit.

or
- Compile yourself using cpp file.
- Place .exe file in the same folder with you autoexec.cfg
- Run it.

# Blacklist

Some alias or binds can have the same commands, so it may be marked as conflict.

To prevent that, add a line `//blacklist` before and after the part you want to exclude.
```
//blacklist
bind leftarrow .
bind rightarrow .
//blacklist
```
