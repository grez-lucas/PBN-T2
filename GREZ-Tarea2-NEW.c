#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//quicksort implementation SOURCE: https://www.programiz.com/dsa/quick-sort
// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
// function to find the partition position
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}

struct hero
{
    int id;
    char *name;
    int intelligence;
    int strength;
    int speed;
    int durability;
    int power;
    int combat;
    char *full_name;
    char *alter_egos;
    char *aliases__001;
    char *place_of_birth;
    char *first_appearance;
    char *publisher;
    char *allignment;
    char *gender;
    char *race;
    char *height__001;
    char *height__002;
    char *weight__001;
    char *weight__002;
    char *eye_color;
    char *hair_color;
    char *work__occupation;
    char *work__base;
    char *connections__group_affiliation;
    char *connections__relatives;
};

int attrComparator(const void *v1, const void *v2){
    const struct hero *p1 = (struct hero *)v1;
    const struct hero *p2 = (struct hero *)v2;
    if (p1->durability < p2->durability)
        return -1;
    else if (p1->durability > p2->durability)
        return +1;
    else if (p1->power < p2->power)
        return -1;
    else if (p1->power > p2->power)
        return +1;
    else if (p1->strength < p2->strength)
        return -1;
    else if (p1->strength > p2->strength)
        return +1;
    else if (p1->speed < p2->speed)
        return -1;
    else if (p1->speed > p2->speed)
        return +1;
    else if (p1->combat < p2->combat)
        return -1;
    else if (p1->combat > p2->combat)
        return +1;
    else if (p1->intelligence < p2->intelligence)
        return -1;
    else if (p1->intelligence > p2->intelligence)
        return +1;
    else
        return 0;
}

struct hero getHero(char *line)
{
    int valueTypeOrder[] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    line +=1;
    char *token = strtok(line, ";");
    int i = 0;
    static struct hero hero;
    char *dupestr = (char *)malloc(2070);

    while (token != NULL)
    {
        dupestr = strdup(token);
        //printf("%s\n",dupestr);
        switch(i) {
        case 0: hero.id = atoi(dupestr);
        case 1: hero.name = dupestr;
        case 2: hero.intelligence = atoi(dupestr);
        case 3: hero.strength = atoi(dupestr);
        case 4: hero.speed = atoi(dupestr);
        case 5: hero.durability = atoi(dupestr);
        case 6: hero.power = atoi(dupestr);
        case 7: hero.combat = atoi(dupestr);
        case 8: hero.full_name = dupestr;
        case 9: hero.alter_egos = dupestr;
        case 10: hero.aliases__001 = dupestr;
        case 11: hero.place_of_birth = dupestr;
        case 12: hero.first_appearance = dupestr;
        case 13: hero.publisher = dupestr;
        case 14: hero.allignment = dupestr;
        case 15: hero.gender = dupestr;
        case 16: hero.race = dupestr;
        case 17: hero.height__001 = dupestr;
        case 18: hero.height__002 = dupestr;
        case 19: hero.weight__001 = dupestr;
        case 20: hero.weight__002 = dupestr;
        case 21: hero.eye_color = dupestr;
        case 22: hero.hair_color = dupestr;
        case 23: hero.work__occupation = dupestr;
        case 24: hero.work__base = dupestr;
        case 25: hero.connections__group_affiliation = dupestr;
        case 26: hero.connections__relatives = dupestr;
        default: break;

        }
    token = strtok(NULL, ";");
    i++;
    }
    return (hero);
}

struct hero *buildDB(){
    static struct hero * hero_arr; 
    hero_arr = malloc(731 * sizeof(struct hero) );
    int i = 0;

    FILE *input_file;
    input_file = fopen("data.txt", "r");

    char *line = (char *)malloc(2070); // line pointer declaration
    char *dupestr = (char *)malloc(2070);

    struct hero hero;

    while (fgets(line, 2070, input_file))
    {
        dupestr = strdup(line);
        //printf("%s\n", line);
        
        hero = getHero(dupestr);
        hero_arr[i] = hero;

        /*printf("%d ", hero.id);
        printf("%s\n", hero.name);*/
        i++;
    } 

    free(dupestr);
    free(line);
    return hero_arr;
}

struct hero topHero(struct hero *database, char *target_name, char *attribute)
{
    int input;
    int betterBy = 1;
    int selectedAttribute;
    static struct hero *hero_arr;
    struct hero target_hero;

    // search for target hero
    for (int i = 0; i < 731; i++)
    {
        if (strcmp(database[i].name, target_name) == 0)
        {
            target_hero = database[i]; // WATCHOUT for what is a copy and what is database info
            break;
        };
    } printf("DEBUG: taget_hero name: %s\n" , target_hero.name);
    hero_arr = calloc(11, sizeof(struct hero));
    // define selectedAttribute
    int counter = 0;
    if (strcmp(attribute, "id") == 0)
        selectedAttribute = 0;
    else if (strcmp(attribute, "intelligence") == 0)
        selectedAttribute = 1;
    else if (strcmp(attribute, "strength") == 0)
        selectedAttribute = 2;
    else if (strcmp(attribute, "speed") == 0)
        selectedAttribute = 3;
    else if (strcmp(attribute, "durability") == 0)
        selectedAttribute = 4;
    else if (strcmp(attribute, "power") == 0)
        selectedAttribute = 5;
    else if (strcmp(attribute, "combat") == 0)
        selectedAttribute = 6;
    else
        selectedAttribute = 7;
    printf("DEBUG: selectedAttribute: %d\n" , selectedAttribute);
    //search for top heroes by selectedAttribute and fill hero_arr
    while (hero_arr[9].name == 0 && selectedAttribute != 7)
    {
        switch (selectedAttribute)
        {
        case 0:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].id - target_hero.id == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 1:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].intelligence - target_hero.intelligence == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 2:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].strength - target_hero.strength == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 3:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].speed - target_hero.speed == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 4:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].durability - target_hero.durability == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 5:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].power - target_hero.power == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 6:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].combat - target_hero.combat == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;

        }
        betterBy += 1;
    }
    printf("DEBUG: 1st hero's name: %s\n" , hero_arr[0].name);
    // print result
    switch (selectedAttribute)
    {
    case 0:
        printf("%s: %d" , target_hero.name, target_hero.id);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].id);
        }
        break;
    case 1:
        printf("%s: %d\n" , target_hero.name, target_hero.intelligence);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].intelligence);
        }
        break;
    case 2:
        printf("%s: %d\n" , target_hero.name, target_hero.strength);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].strength);
        }
        break;
    case 3:
        printf("%s: %d\n" , target_hero.name, target_hero.speed);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].speed);
        }
        break;
    case 4:
        printf("%s: %d\n" , target_hero.name, target_hero.durability);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].durability);
        }
        break;
    case 5:
        printf("%s: %d\n" , target_hero.name, target_hero.power);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].power);
        }
        break;
    case 6:
        printf("%s: %d\n" , target_hero.name, target_hero.combat);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].combat);
        }
        break;
    }
    printf("de que superheroe desea ver su informacion?\n");
    scanf("%d", &input);
    return hero_arr[input - 1]; //return only the hero who's information is to be seen
}

void queryHero(struct hero *database, struct hero target_hero){
    // search for target hero
    for (int i = 0; i < 731; i++)
    {
        if (strcmp(database[i].name, target_hero.name) == 0)
        {
            target_hero = database[i]; // WATCHOUT for what is a copy and what is database info
            break;
        };
    } printf("DEBUG: taget_hero name: %s\n" , target_hero.name);

    // find position of each attribute
    int durability_pos = 0;
    int power_pos = 0;
    int strength_pos = 0;
    int speed_pos = 0;
    int combat_pos = 0;
    int intelligence_pos = 0;

    
    printf("%s:\n", target_hero.name);
    printf("\tdurability: %d\n", target_hero.durability);
    printf("\tpower: %d\n", target_hero.power);
    printf("\tstrength: %d\n", target_hero.strength);
    printf("\tspeed: %d\n", target_hero.speed);
    printf("\tintelligence: %d\n", target_hero.intelligence);
}

int main(int argc, char **argv)
{

    struct hero* database = buildDB();
    for(int i =0; i<5; i++){
        printf("%d ", database[i].id);
        printf("%s \n", database[i].name);
    }

    char* att = "power";
    char* thero ="Black Cat";
    //printf("%s \n", att);
    struct hero heroq = topHero(database, thero, att);

    free(database);
    return 0;
}
/*
TODO:
- 
NOTES:
- 
*/