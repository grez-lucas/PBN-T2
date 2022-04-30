#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

struct hero getHero(char *line)
{
    int valueTypeOrder[] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    line +=1;
    char *token = strtok(line, ";");
    int i = 0;
    static struct hero hero;

    while (token != NULL)
    {
        //printf("%s\n",token);
        switch(i) {
        case 0: hero.id = atoi(token);
        case 1: hero.name = token;
        case 2: hero.intelligence = atoi(token);
        case 3: hero.strength = atoi(token);
        case 4: hero.speed = atoi(token);
        case 5: hero.durability = atoi(token);
        case 6: hero.power = atoi(token);
        case 7: hero.combat = atoi(token);
        case 8: hero.full_name = token;
        case 9: hero.alter_egos = token;
        case 10: hero.aliases__001 = token;
        case 11: hero.place_of_birth = token;
        case 12: hero.first_appearance = token;
        case 13: hero.publisher = token;
        case 14: hero.allignment = token;
        case 15: hero.gender = token;
        case 16: hero.race = token;
        case 17: hero.height__001 = token;
        case 18: hero.height__002 = token;
        case 19: hero.weight__001 = token;
        case 20: hero.weight__002 = token;
        case 21: hero.eye_color = token;
        case 22: hero.hair_color = token;
        case 23: hero.work__occupation = token;
        case 24: hero.work__base = token;
        case 25: hero.connections__group_affiliation = token;
        case 26: hero.connections__relatives = token;

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

    char *line = (char *)malloc(1024); // line pointer declaration
    char *dupestr = (char *)malloc(1024);

    struct hero hero;

    while (fgets(line, 1024, input_file))
    {
        dupestr = strdup(line);
        //printf("%s\n", line);
        
        hero = getHero(dupestr);
        hero_arr[i] = hero;


        i++;
    } 

    free(dupestr);
    free(line);
    return hero_arr;
}




// create getValuefromMemory function

int main(int argc, char *argv)
{
    //char line[] ="1;A-Bomb;38;100;17;80;24;64;Richard Milhouse Jones;No alter egos found.;Rick Jones;Scarsdale; Arizona;Hulk Vol 2 #2 (April; 2008) (as A-Bomb);Marvel Comics;good;Male;Human;6'8;203 cm;980 lb;441 kg;Yellow;No Hair;Musician; adventurer;";
    //struct hero hero1 = getHero(line);
    struct hero* database = buildDB();
    //printf("%s \n", hero1.name);
    for(int i =0; i<5; i++){
        printf("%d ", database[i].id);
        printf("%s \n", database[i].name);
    }


    free(database);
    return 0;
}
/*
TODO:
- 
NOTES:
- 
*/