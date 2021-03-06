# Project 4

__Due date: Friday, May 4 at 11:55pm.__

---
**You may discuss any of the assignments with your classmates and instructors
(or anyone else) but all work for all assignments must be entirely your own.
Any sharing or copying of assignments will be considered cheating (this
includes posting of partial or complete solutions on Piazza, GitHub public
repositories or any other public forum). If you get significant help  from
anyone, you should acknowledge it in your submission (and your grade will be
proportional to the part  that you completed on your own). You are responsible
for every line in your program: you need to know what it does and why.**

## Programming requirements:

- The programs should be leak-free: any memory that is allocated should be freed before the program terminates.

- The programs should not produce any zombie processes.

- The programs have to be documented! Any file that you edit should have preamble including
your name as the author, description of the purpose of the program and inline comments
in the functions that you implement.
- The code has to follow C programming conventions.
- The code has to be formatted properly.
- The C code has to look like a high level programming language.

In addition, you are required to make at least 5 commits to your repository.
Each time you make a significant change/improvement to your solutions, you
should commit and push the changes to the remote repository. This way, if there
are any problems with your local copy of the files, you have a recent version of
the code available. Your commits should be distributed over time - they should
not be all made within an hour before the due date.



## Problem 1
Write a program called `list_home`. When a user executes this program it should
display the content of their home directory regardless of the actual
working directory.

Running your program should produce results equivalent to running `ls -l ~`,
except your program should not expect any command line arguments.



 __Examples:__

Here is a sample run of `list_home` on my machine:

```bash
$ ./list_home
total 452
drwxrwxr-x  4 asia asia   4096 Sep 26  2016 bin
drwxrwxr-x  4 asia asia   4096 Jul 31  2017 canopy
drwxrwxr-x  2 asia asia   4096 Feb  6  2017 canvas
-rw-rw-r--  1 asia asia  14830 Jan 15 13:59 ContentQuestionsPreV2.1.docx
drwxrwxr-x 11 asia asia   4096 Jan  2  2017 Data
drwxrwxr-x  7 asia asia   4096 Apr 23 16:10 Desktop
drwxr-xr-x 15 asia asia  20480 Apr 23 13:44 Downloads
drwxrwxr-x  2 asia asia   4096 Jul 31  2017 enthought
drwxrwxr-x  4 asia asia   4096 Jan  3  2017 freediams
drwxrwxr-x  3 asia asia   4096 Aug 21  2017 git
-rw-rw-r--  1 asia asia     94 Jan 25  2017 gtkrc-eclipse
drwxrwxr-x  2 asia asia   4096 Oct 18  2015 MC-Projects
-rw-rw-r--  1 asia asia   6203 Apr  6  2015 missfont.log
-rw-rw-r--  1 asia asia  98544 Aug 20  2016 packages_list_14.04
drwx------  2 asia asia   4096 Apr 23 16:07 PDF
-rw-rw-r--  1 asia asia  83786 Aug 20  2016 pkg_list
-rw-r--r--  1 root root 110004 Aug 18  2017 powertop.html
-rw-rw-r--  1 asia asia  22305 Sep 24  2017 problem4_NY.png
drwxr-xr-x  6 asia asia   4096 Mar 13 13:57 snap
-rw-rw-r--  1 asia asia   3008 Aug 20  2016 sources.list
drwxr-xr-x  2 asia asia   4096 Aug 30  2014 Templates
drwxrwxr-x  3 asia asia   4096 Jan 27  2016 texmf
drwxrwxr-x 17 asia asia   4096 Apr 10 14:19 tmp
-rw-r--r--  1 asia asia      6 Aug 20  2016 upstart-dbus-bridge.18758.pid
-rw-r--r--  1 asia asia      6 Aug 20  2016 upstart-file-bridge.18758.pid
-rw-r--r--  1 asia asia      6 Aug 20  2016 upstart-udev-bridge.18758.pid
drwxrwxr-x  6 asia asia   4096 Jan 15 12:49 VirtualBox VMs
drwxrwxr-x  2 asia asia   4096 Jan 29  2017 Wallpapers
drwxrwxr-x  3 asia asia   4096 Sep 17  2014 workspace
```

and here is the output generated by running `ls -l ~`:

```bash
$ ls -l ~
total 452
drwxrwxr-x  4 asia asia   4096 Sep 26  2016 bin
drwxrwxr-x  4 asia asia   4096 Jul 31  2017 canopy
drwxrwxr-x  2 asia asia   4096 Feb  6  2017 canvas
-rw-rw-r--  1 asia asia  14830 Jan 15 13:59 ContentQuestionsPreV2.1.docx
drwxrwxr-x 11 asia asia   4096 Jan  2  2017 Data
drwxrwxr-x  7 asia asia   4096 Apr 23 16:10 Desktop
drwxr-xr-x 15 asia asia  20480 Apr 23 13:44 Downloads
drwxrwxr-x  2 asia asia   4096 Jul 31  2017 enthought
drwxrwxr-x  4 asia asia   4096 Jan  3  2017 freediams
drwxrwxr-x  3 asia asia   4096 Aug 21  2017 git
-rw-rw-r--  1 asia asia     94 Jan 25  2017 gtkrc-eclipse
drwxrwxr-x  2 asia asia   4096 Oct 18  2015 MC-Projects
-rw-rw-r--  1 asia asia   6203 Apr  6  2015 missfont.log
-rw-rw-r--  1 asia asia  98544 Aug 20  2016 packages_list_14.04
drwx------  2 asia asia   4096 Apr 23 16:07 PDF
-rw-rw-r--  1 asia asia  83786 Aug 20  2016 pkg_list
-rw-r--r--  1 root root 110004 Aug 18  2017 powertop.html
-rw-rw-r--  1 asia asia  22305 Sep 24  2017 problem4_NY.png
drwxr-xr-x  6 asia asia   4096 Mar 13 13:57 snap
-rw-rw-r--  1 asia asia   3008 Aug 20  2016 sources.list
drwxr-xr-x  2 asia asia   4096 Aug 30  2014 Templates
drwxrwxr-x  3 asia asia   4096 Jan 27  2016 texmf
drwxrwxr-x 17 asia asia   4096 Apr 10 14:19 tmp
-rw-r--r--  1 asia asia      6 Aug 20  2016 upstart-dbus-bridge.18758.pid
-rw-r--r--  1 asia asia      6 Aug 20  2016 upstart-file-bridge.18758.pid
-rw-r--r--  1 asia asia      6 Aug 20  2016 upstart-udev-bridge.18758.pid
drwxrwxr-x  6 asia asia   4096 Jan 15 12:49 VirtualBox VMs
drwxrwxr-x  2 asia asia   4096 Jan 29  2017 Wallpapers
drwxrwxr-x  3 asia asia   4096 Sep 17  2014 workspace

```

Your implementation will need create a new process (`fork()` and run a new program within that process' space (`execve`).
The executable binary for `ls` is `/bin/ls`.



__Your program should be implemented in the file called `list_home.c`.__


## Problem 2

Write a program called `remind_me`. This program will print a message on the console after a specific number of seconds elapses.

The program's syntax and description is as follows:

```
remind_me   time   [ message-text ]
```

__Description:__

The `remind_me` command displays the `message-text` on the user’s console after at least the integral number of seconds specified by the `time` operand.  The `remind_me` command displays the process-id of the background process that it creates to keep track of the time and returns immediately to the shell to allow the user to continue doing other tasks.

__Operands:__

The following operands are supported:

`time`	A non-negative number of minutes to delay before displaying the `message-text` on the console.

`message-text`	A possibly empty text string of unlimited length. (This string
  may or may not be enclosed in quotes. )

 __Examples:__

 ```
 $ ./remind_me 10 hello earthlings!
 ./remind_me process-id 4471
 $ ls
 total 236
 drwxrwxr-x  2 asia asia  4096 Apr 23 17:37 .
 drwxrwxr-x 10 asia asia  4096 Apr 23 16:47 ..
 ...

 //user continues working

 //10 seconds later

 hello earthlings!

 $

 ```

 ```
 $ ./remind_me 360 "time to go to class!"
 ./remind_me process-id 6616
 $ // user continues working
  ...

  // 10 minutes later

  time to go to class!

  $

 ```
(Note that the user may need to hit the "Enter" key for the prompt to be redisplayed after the message is shown.)

__Restrictions:__

- Your program is not allowed to use the `sleep()` function.
- The program should return control of the terminal back to the user as soon as possible (not only after the message is printed).
- Your program should not create any zombie processes.

__Useful functions:__

`alarm` - arranges for a `SIGALRM` signal to be delivered to the calling process in
 the specified number of seconds. Read the manual page (`man alarm`) for
details on how to use it.

You also will need to use `pause`, `fork` and `signal` calls.



__Your program should be implemented in the file called `remind_me.c`.__
