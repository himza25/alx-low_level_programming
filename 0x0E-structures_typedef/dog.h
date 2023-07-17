#ifndef DOG_H
#define DOG_H

void init_dog(struct dog *d, char *name, float age, char *owner);

/**
 * struct dog - Structure for dog
 * @name: First member
 * @age: Second member
 * @owner: Third member
 *
 * Description: Longer description of the structure
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

#endif /* DOG_H */
