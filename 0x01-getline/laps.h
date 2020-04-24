#ifndef __LAPS_H__
#define __LAPS_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void race_state(int *id, size_t size);
void allocate_matrix(int ***arr, size_t col);
void free_matrix(int **arr, size_t n);
void print_matrix(int **arr, size_t n);

#endif /* LAPS.H */
