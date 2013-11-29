#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destroy(struct Person *who)
{
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("Age: %d\n", who->age);
  printf("Height: %d\n", who->height);
  printf("Weight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
  struct Person *jennifer = Person_create("Jennifer Userton", 25, 165, 60);
  struct Person *chloe = Person_create("Chloe the Employment Fox", 5, 40, 19);

  printf("Jennifer is at memory location %p:\n", jennifer);
  Person_print(jennifer);

  printf("Chloe is at memory location %p:\n", chloe);
  Person_print(chloe);

  Person_destroy(jennifer);
  Person_destroy(chloe);

  return 0;
}
