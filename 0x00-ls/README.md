# 0x00. C - ls

## Linux Programming

## Compilation

The program will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic *.c -o hls
```
## Testing

The program should give the same result as the real ls

```
$ ls test
abc  BCD  file  file2  file3  folder1  folder2  folder3
$ ./hls test
abc  BCD  file  file2  file3  folder1  folder2  folder3
$ ls -1
abc
BCD
file
file2
file3
folder1
folder2
folder3
hls
$ ./hls -1
abc
BCD
file
file2
file3
folder1
folder2
folder3
hls
$
```
