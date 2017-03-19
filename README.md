# cs162


## Setup
### Mac OS X
in the VM folder (~/documents/cs162-vm/), 
- `vagrant up` to set up VM. if this fails, use `vagrant provision` to fix
- `vagrant halt` to stop the VM.
next time to run VM, just `vagrant up` + `vagrant ssh`.

> see section1_tools
1. Open Finder
2. In the menu bar, select `Go` -> `Connect to Server...`
3. The server address is `smb://192.168.162.162/vagrant`
4. The username is `vagrant` and the password is `vagrant`
You should be able to see the contents of the vagrant user's home directory.


## Compile File

```bash
$ gcc programname.c -o programname
# if you don't supply -c, gcc will both compile and link for you behind  the scenes.
```

## gdb debugger tool

[manual](http://www.unknownroad.com/rtfm/gdbtut/gdbtoc.html)
[easy-tutorial](http://blog.csdn.net/haoel/article/details/2879)

```bash
## compile with debugging symbols
$ gcc -g programname.c -o programname

## run programs with the debugger
$ gdb programname
# next use the `run` command in gdb to start execution

## restart a program running in a debugger
$ kill
$ run 

## quit the debugger
$ quit


## debugging
$ l  # showing program
$ break 16 # set breakpoint at line 16
$ break func # set breakpoint at func()
$ info break # list breakpoints
$ r # run program
$ n # next program
$ c # continue
$ p i # print variable 
```


