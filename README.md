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
$ gcc -o hello hello.c
```
