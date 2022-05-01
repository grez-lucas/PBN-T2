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

struct hero *topHero(struct hero * database, char* target_name, char* attribute){
    int input;
    int betterBy = 1;
    int selectedAttribute;
    static struct hero * hero_arr;
    struct hero target_hero;

    struct heroQuery{
        char* name;
        int attribute;
    };
    //search for target hero
    for(int i=0;i<731;i++){
        if( strcmp( database[i].name , target_name) == 0 ) {
            target_hero = database[i]; // WATCHOUT for what is a copy and what is database info
            break;
        };      
    }
    hero_arr = calloc(10, sizeof(struct hero) );
    //search for topHeroes
    int counter = 0;
    if (strcmp(attribute, "id") == 0) selectedAttribute = 0;
    else if (strcmp(attribute, "intelligence") == 0) selectedAttribute = 1;
    else if (strcmp(attribute, "strength") == 0) selectedAttribute = 2;
    else if (strcmp(attribute, "speed") == 0) selectedAttribute = 3;
    else if (strcmp(attribute, "durability") == 0) selectedAttribute = 4;
    else if (strcmp(attribute, "power") == 0) selectedAttribute = 5;
    else if (strcmp(attribute, "combat") == 0) selectedAttribute = 6;
    else selectedAttribute = 7;
    while ( hero_arr[9].id == 0 && selectedAttribute != 7 )
    {
        switch(selectedAttribute){
            case 0:
            for(int i =0;i<731;i++){
                if( database[i].id - target_hero.id == betterBy){
                    hero_arr[counter] = database[i];
                } 
            }
            break;
            case 1:
            for(int i =0;i<731;i++){
                if( database[i].intelligence - target_hero.intelligence == betterBy){
                    hero_arr[counter] = database[i];
                } 
            }
            break;
            case 2:
            for(int i =0;i<731;i++){
                if( database[i].strength - target_hero.strength == betterBy){
                    hero_arr[counter] = database[i];
                } 
            }
            break;
            case 3:
            for(int i =0;i<731;i++){
                if( database[i].speed - target_hero.speed == betterBy){
                    hero_arr[counter] = database[i];
                } 
            }
            break;
            case 4:
            for(int i =0;i<731;i++){
                if( database[i].durability - target_hero.durability == betterBy){
                    hero_arr[counter] = database[i];
                } 
            }
            break;
            case 5:
            for(int i =0;i<731;i++){
                if( database[i].power - target_hero.power == betterBy){
                    hero_arr[counter] = database[i];
                } 
            }
            break;
            case 6:
            for(int i =0;i<731;i++){
                if( database[i].combat - target_hero.combat == betterBy){
                    hero_arr[counter] = database[i];
                } 
            }
            break;
            
        counter ++; //syntax may be wrong..
        }
        betterBy +=1;
        
    }

    printf("de que superheroe desea ver su informacion?\n");
    scanf( "%d", &input);
    return hero_arr;
}

int main(int argc, char *argv)
{

    struct hero* database = buildDB();
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