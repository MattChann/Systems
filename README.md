# Work 06: Please Follow the Dir[ections]

Write a program that will gather various information about a directory, specifically:
- list all the files in the directory
- specify which files are directories (if any)
- show the total size of all the regular files the directory
    - note that you do not have to recursively go through any subdirectories to find their size for this part (unless you want to, but that is not a simple task)
- Have the program scan the current directory
- Possible enhancements:
    - Recursively list the files in any subdirectories, update the total to include the total size of subdirectories
    - Print out the size in a more readable format (like using KB, MB, GB for -byte prefixes)
    - Make it look more like $ ls -l


Github link:
https://github.com/mks65/dirinfo.git


Below is sample output, yours may differ, but as long as it presents the information requested above you will receive full credit.
```
$ ./a.out
Statistics for directory: .
Total Diectory Size: 13453 Bytes
Directories:
        .
        ..
Regular files:
        a.out
        dirinfo.c
        dirinfo.c~
        dirstuff.c
        dirstuff.c~
```
```
$ ./a.out
Statistics for directory: .
Total Diectory Size: 17766 Bytes
Directories:
        .
        ..
        dir
        structRW
Regular files:
        a.out
        error.log
        filelist
        files.c
        read.c
        ReadTest
        redirect.c
        redirect.c~
        redirect_full.c
        redirect_full.c~
        redirTest
        statfiles.c
        statfiles.c~
        write.c
        WriteTest
```
