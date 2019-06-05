Name: Nikhil Gosike


RUN 1: Nik Gos

Output:

First:     Nik                 
Last:      Gos                 
Initial:   L                   
Age:       21                  
Salary:    70000

The program ran normally and as expected.

At 43

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x70 | 0xe0 | 0xff | 0xff | 0xff | 0x7f | 0x00 | 0x00 | 0x00
  char representation| p | | | | | NULL | NULL | NULL

  At 53

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x4c | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | L | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x10 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation|  | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL

  At 65

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0x4e| 0x69 | 0x6b | 0x00 | 0x00 | 0x47 | 0x6f | 0x73
  char representation| N | i | k | NULL | NULL | G | o | s
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x4c | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | L | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x10 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation|  | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL 


RUN 2: Nikhi Gos

Output:

First:     NikhiGos            
Last:      Gos                 
Initial:   L                   
Age:       21                  
Salary:    70000  

The program did run normally, but not as expected. Rather than printing "Nikhi" as the first name, it printed "NikhiGos". The reason for this is because "Nikhi" is not null terminated after "i". C views Strings as arrays of characters and looks for NULL to indicate the end of the string. If a string is non-null terminated, C will continue to read sequentially through memory until a NULL is found. The NULL is found only after "Gos".

  At 43

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x70 | 0xe0 | 0xff | 0xff | 0xff | 0x7f | 0x00 | 0x00 | 0x00
  char representation| p | | | | | NULL | NULL | NULL

  At 53

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x4c | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | L | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x10 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation|  | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL

  At 63

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0x4e| 0x69 | 0x6b | 0x68 | 0x69 | 0x47 | 0x6f | 0x73
  char representation| N | i | k | h | i | G | o | s
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x4c | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | L | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x10 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation|  | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL

RUN 3: Nik GosikeGosi

Output:

First:     Nik            
Last:      GosikeGosi                
Initial:   e                  
Age:       21                  
Salary:    70000  

The program did run normally, but not as expected. Rather than printing "L" as the first name, it printed "e". The reason for this is that once we call strcopy(), the "L" character at the byte storing m is being overwritten to "e". To see this consider the structure of p. We see that the last name is only 5 bytes. When calling strcopy, it correctly stores the characters "Gosik" sequentially in memory. However, for the rest of the string, it continues to sequentially copy these characters into the struct the next byte after last name is m, which is why e is written to this memory address. It should be noted that "Gosi" is written into the 1st 4 bytes of the padding, including a null character in the 5th byte of the padding to indicate the end of the string. 

  At 43

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x70 | 0xe0 | 0xff | 0xff | 0xff | 0x7f | 0x00 | 0x00 | 0x00
  char representation| p | | | | | NULL | NULL | NULL

  At 53

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x4c | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | L | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x10 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation|  | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL

  At 63

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0x4e| 0x69 | 0x6b | 0x00 | 0x00 | 0x47 | 0x6f | 0x73
  char representation| N | i | k | NULL | NULL | G | o | s
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x69 | 0x6b | 0x65 | 0x47 | 0x6f | 0x73 | 0x69 | 0x00
  char representation| i | k | e | G | o | s | i | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x10 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation|  | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL


RUN 4: Nik GosikeGosik

Output:

First:     Nik            
Last:      GosikeGosik                 
Initial:   e                  
Age:       0                  
Salary:    33  

The program did run normally, but not as expected. Rather than printing "L" as the first name, it printed "e". In addition, it printed an age of 0 rather than 21 and a salary of 33, not 70000. The "e" is printed for the same reason as with the last run. Again, after the "e", "Gosik" becomes written into the 5 bytes of the padding. After the the padding is filled, 0x00 or the null character is written to the first byte to indicate the end of the last name string. The 8 bytes of the personal record is a pointer and stores a memory.Before adding the last name, the address of the personal record is 0x00602010. By overwriting the 0x10 at m+16, we are essentially shifting the memory address the personal record is pointing to by 0x10 to 0x00602000. By accessing this memory address, we have the value of the int at this address is 0. This gets printed as the Age. To print the Salary, we need to access the memory 8 bytes after at 0x00602008, which stores the value 0x21 or 33, which is why the Salary is printed to be 33.

  At 43

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x70 | 0xe0 | 0xff | 0xff | 0xff | 0x7f | 0x00 | 0x00 | 0x00
  char representation| p | | | | | NULL | NULL | NULL

  At 53

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x4c | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | L | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x10 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation|  | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL

  At 63

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0x4e| 0x69 | 0x6b | 0x00 | 0x00 | 0x47 | 0x6f | 0x73
  char representation| N | i | k | NULL | NULL | G | o | s
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x69 | 0x6b | 0x65 | 0x47 | 0x6f | 0x73 | 0x69 | 0x6b
  char representation| i | k | e | G | o | s | i | k
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x00 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL



RUN 5: Nik GosikeGosikeG

Output:

First:     Nik                 
Last:      GosikeGosikeG       
Initial:   e                   
Segmentation fault (core dumped)

The program did not run normally. Instead of printing the initial "L", "e" is printed. The reason for this is the same as the above two runs. The major issue comes from the segmentation default which crashes the program. The last two letters of the last name, "eG" and the null character, which indicates the end of the string, essentially overwrites the correct memory address storing the personal record at 0x00602010. So, when the program tries to print the data fields of the personal record, it tries to access the memory at address 0x4765, it causes a segmentation fault. This memory address is actually unaccessible by the program and, because of that, causes the exception to be thrown.

  At 43

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | @ | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x60 | 0xe0 | 0xff | 0xff | 0xff | 0x7f | 0x00 | 0x00 | 0x00
  char representation| ' (grave accent) | | | | | NULL | NULL | NULL

  At 53

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0xd0 | 0x07 | 0x40 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| | | @ | | NULL | NULL | NULL | NULL
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x00 | 0x05 | 0x4c | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| NULL | | L | NULL | NULL | NULL | NULL | NULL
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x10 | 0x20 | 0x60 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation|  | " " (space) | ' (grave accent) | NULL | NULL | NULL | NULL | NULL

  At 63

  memory address | m | m+1 | m+2 | m+3| m+4 | __m+5__ | __m+6__ | __m+7__
  ---|---|---|---|---|---|---|---|---
  hex representation| 0x4e| 0x69 | 0x6b | 0x00 | 0x00 | 0x47 | 0x6f | 0x73
  char representation| N | i | k | NULL | NULL | G | o | s
  __memory address__ | __m+8__| __m+9__  | __m+10__  |  __m+11__ | __m+12__ | __m+13__| __m+14__ | __m+15__
  hex representation| 0x69 | 0x6b | 0x65 | 0x47 | 0x6f | 0x73 | 0x69 | 0x6b
  char representation| i | k | e | G | o | s | i | k
  __memory address__ | __m+16__| __m+17__  | __m+18__  |  __m+19__ | __m+20__ | __m+21__| __m+23__ | __m+24__
  hex representation| 0x65 | 0x47 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00 | 0x00
  char representation| e | G | NULL | NULL | NULL | NULL | NULL | NULL