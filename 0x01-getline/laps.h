#ifndef __LAPS_H__
#define __LAPS_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LENGTH 10

void swap(int *x, int *y);
void sort_list(int **list, size_t n);
void race_state(int *id, size_t size);
void allocate_matrix(int ***arr);
void free_matrix(int **arr, size_t n);
void print_matrix(int **arr, size_t n);
int insert_element(int **m, int *ptr, size_t n);

#endif /* LAPS.H */
