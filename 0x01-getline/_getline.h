#ifndef _GETLINE_H
#define _GETLINE_H

#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define READ_SIZE 1024

char *_getline(const int fd);

#endif /* _GETLINE.H */
