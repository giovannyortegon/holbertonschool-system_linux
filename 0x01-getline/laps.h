#ifndef LAPS_H
#define LAPS_H

#include<stdio.h>
#include<stdlib.h>

/**
 * struct race - strucuture of cars in the race
 * @id:   number of cars
 * @laps: counter of laps
 * @next: pointer to another node
 */
typedef struct race
{
	int id;
	int laps;
	struct race *next;
} RaceCar;

RaceCar *new_car(int id);
void free_cars(RaceCar *cars);
void insert_car(RaceCar **cars, int id);
void race_state(int *id, size_t size);

#endif /* LAPS.H */
