#include "dog.h"

/**
 * init_dog - initialize a variable of type struct dog
 * @d: pointer to a struct dog to initialize
 * @name: name to set
 * @age: age to set
 * @owner: owner to set
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
