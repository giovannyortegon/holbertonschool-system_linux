#include "laps.h"
/**
 * race_state - states of the race
 * @id:	array of cars
 * @size:	length of array
 */
void race_state(int *id, size_t size)
{
	static RaceCar *cars;
	RaceCar *Cars;

	size_t i;

	if (id == NULL && size == 0)
	{
		free_cars(cars);
		return;
	}
	for (i = 0; i < size; i++)
		insert_car(&cars, id[i]);
	Cars = cars;
	printf("Race state:\n");
	while (Cars != NULL)
	{
		printf("Car %d [%d laps]\n", Cars->id, Cars->laps);
		Cars = Cars->next;
	}
}
/**
 * insert_car - inserting new cars
 * @cars:	list of cars
 * @id:	id of cars
 */
void insert_car(RaceCar **cars, int id)
{
	RaceCar *curr, *car;

	if (*cars == NULL || (*cars)->id > id)
	{
		car = new_car(id);
		car->next = (*cars);
		(*cars) = car;
		printf("Car %d joined the race\n", car->id);
	}
	else
	{
		car = (*cars);
		while (car->next != NULL && car->next->id <= id)
		{
			car = car->next;
		}
		if (car->id == id)
		{
			car->laps++;
			return;
		}
		curr = new_car(id);
		curr->next = car->next;
		car->next = curr;
		printf("Car %d joined the race\n", curr->id);
	}
}
/**
 * new_car - create a new cars
 * @id:	car identification
 * Return:	new car
 */
RaceCar *new_car(int id)
{
	RaceCar *car;

	car = (RaceCar *) malloc(sizeof(RaceCar));
	if (car == NULL)
		exit(EXIT_FAILURE);

	car->id = id;
	car->laps = 0;
	car->next = NULL;
	return (car);
}
/**
 * free_cars - free list of cars
 * @cars:	list of cars
 */
void free_cars(RaceCar *cars)
{
	RaceCar *tmp;

	while (cars != NULL)
	{
		tmp = cars;
		cars = cars->next;
		free(tmp);
	}
}
