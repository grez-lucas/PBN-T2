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

char** terminalDecodeStr(char* line, int queryType){
    //queryType = 0 for heroQuery, 1 for topHeroByName
    int i = 0;
    line[strcspn(line, "\n")] = 0;
    char *p = strtok (line, " ");
    static char** array;
    array = malloc(5*1024);
    char* dupestr;

    while (p != NULL)
    {   
        if( i> 2 && queryType == 1){
            dupestr = strdup(p);
            strcat(array[2], " ");
            strcat(array[2], dupestr);
            p = strtok (NULL, " ");
            if(p == NULL) break;
            dupestr = strdup(p);
            strcat(array[2], " ");
            strcat(array[2], dupestr);
            break;
        }
        else if(i> 1 && queryType == 0){
            dupestr = strdup(p);
            strcat(array[1], " ");
            strcat(array[1], dupestr);
            p = strtok (NULL, " ");
            if(p == NULL) break;
            dupestr = strdup(p);
            strcat(array[1], " ");
            strcat(array[1], dupestr);
            break;
        }else {array[i++] = p;
        p = strtok (NULL, " ");}
    }
    return array;
}

int intCompare(const void * e1, const void * e2) {
return *(int*)e2-*(int*)e1;
}

int durabilityComparator(const void *v1, const void *v2){
    const struct hero *p1 = (struct hero *)v1;
    const struct hero *p2 = (struct hero *)v2;
    return (p2->durability - p1->durability);}
int powerComparator(const void *v1, const void *v2){
    const struct hero *p1 = (struct hero *)v1;
    const struct hero *p2 = (struct hero *)v2;
    return (p2->power - p1->power);}
int strengthComparator(const void *v1, const void *v2){
    const struct hero *p1 = (struct hero *)v1;
    const struct hero *p2 = (struct hero *)v2;
    return (p2->strength - p1->strength);}
int speedComparator(const void *v1, const void *v2){
    const struct hero *p1 = (struct hero *)v1;
    const struct hero *p2 = (struct hero *)v2;
    return (p2->speed - p1->speed);}
int combatComparator(const void *v1, const void *v2){
    const struct hero *p1 = (struct hero *)v1;
    const struct hero *p2 = (struct hero *)v2;
    return (p2->combat - p1->combat);}
int intelligenceComparator(const void *v1, const void *v2){
    const struct hero *p1 = (struct hero *)v1;
    const struct hero *p2 = (struct hero *)v2;
    return (p2->intelligence - p1->intelligence);}


struct hero getHero(char *line)
{
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
        case 0: hero.id = atoi(dupestr);break;
        case 1: hero.name = dupestr;break;
        case 2: hero.intelligence = atoi(dupestr);break;
        case 3: hero.strength = atoi(dupestr);break;
        case 4: hero.speed = atoi(dupestr);break;
        case 5: hero.durability = atoi(dupestr);break;
        case 6: hero.power = atoi(dupestr);break;
        case 7: hero.combat = atoi(dupestr);break;
        case 8: hero.full_name = dupestr;break;
        case 9: hero.alter_egos = dupestr;break;
        case 10: hero.aliases__001 = dupestr;break;
        case 11: hero.place_of_birth = dupestr;break;
        case 12: hero.first_appearance = dupestr;break;
        case 13: hero.publisher = dupestr;break;
        case 14: hero.allignment = dupestr;break;
        case 15: hero.gender = dupestr;break;
        case 16: hero.race = dupestr;break;
        case 17: hero.height__001 = dupestr;break;
        case 18: hero.height__002 = dupestr;break;
        case 19: hero.weight__001 = dupestr;break;
        case 20: hero.weight__002 = dupestr;break;
        case 21: hero.eye_color = dupestr;break;
        case 22: hero.hair_color = dupestr;break;
        case 23: hero.work__occupation = dupestr; break;
        case 24: hero.work__base = dupestr;break;
        case 25: hero.connections__group_affiliation = dupestr;break;
        case 26: hero.connections__relatives = dupestr;break;
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

struct hero searchTargetHero(struct hero *database, char*target_name){
    struct hero target_hero = { 0,NULL,0,0,0,0,0,0,NULL,NULL,NULL,NULL,NULL,
                                NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,
                                NULL,};
    // search for target hero
    for (int i = 0; i < 731; i++)
    {
        if (strcmp(database[i].name, target_name) == 0)
        {
            target_hero = database[i]; // WATCHOUT for what is a copy and what is database info
            break;
        };
    } 
    return target_hero;
}

void queryHero(struct hero *database, struct hero target_hero){
    // find position of each attribute
    int n = 731;
    int (*ff[])(const void*, const void*) = { durabilityComparator, powerComparator,
                        strengthComparator, speedComparator,
                        combatComparator, intelligenceComparator};
    int positions[] = {0,0,0,0,0,0};
    
    for(int i=0;i<6;i++){
        qsort(database, n, sizeof(struct hero), ff[i]);
        for(int j=0;j<731;j++){
            if(database[j].id == target_hero.id){
                break;
            }
            positions[i] ++;
        }
    }


    printf("%s:\n", target_hero.name);
    printf("\tdurability: %d posicion: %d\n", target_hero.durability, positions[0]);
    printf("\tpower: %d posicion: %d\n", target_hero.power, positions[1]);
    printf("\tstrength: %d posicion: %d\n", target_hero.strength, positions[2]);
    printf("\tspeed: %d posicion: %d\n", target_hero.speed, positions[3]);
    printf("\tcombat: %d posicion: %d\n", target_hero.combat, positions[4]);
    printf("\tintelligence: %d posicion: %d\n", target_hero.intelligence, positions[5]);
}

struct hero topHeroByName(struct hero *database, char *target_name, char *attribute)
{
    char* input = (char*)malloc(1);
    int betterBy = 1;
    int selectedAttribute;
    static struct hero *hero_arr;
    struct hero target_hero;

    target_hero = searchTargetHero(database, target_name);

    if(target_hero.name == NULL){
        return target_hero;
    }

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
    // print result
    switch (selectedAttribute)
    {
    case 0:
        printf("%s: %d\n" , target_hero.name, target_hero.id);
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
    fgets(input, 1024, stdin);
    return hero_arr[atoi(input) - 1]; //return only the hero who's information is to be seen
}

struct hero topHeroByValue(struct hero *database, int target_value, char *attribute)
{
    char* input = (char*)malloc(1);
    int betterBy = 1;
    int selectedAttribute;
    static struct hero *hero_arr;

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
    //search for top heroes by selectedAttribute and fill hero_arr
    while (hero_arr[9].name == 0 && target_value >= 0 && selectedAttribute != 7)
    {
        switch (selectedAttribute)
        {
        case 0:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].id - target_value == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 1:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].intelligence - target_value == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 2:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].strength - target_value == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 3:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].speed - target_value == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 4:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].durability - target_value == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 5:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].power - target_value == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;
        case 6:
            for (int i = 0; i < 731; i++)
            {
                if (database[i].combat - target_value == betterBy)
                {
                    hero_arr[counter] = database[i];
                    counter++;
                }
            }
            break;

        }
        betterBy += 1;
    }
    // print result
    printf("Query by ");
    switch (selectedAttribute)
    {
    case 0:
        printf("%s: %d\n" , attribute, target_value);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].id);
        }
        break;
    case 1:
        printf("%s: %d\n" , attribute, target_value);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].intelligence);
        }
        break;
    case 2:
        printf("%s: %d\n" , attribute, target_value);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].strength);
        }
        break;
    case 3:
        printf("%s: %d\n" , attribute, target_value);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].speed);
        }
        break;
    case 4:
        printf("%s: %d\n" , attribute, target_value);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].durability);
        }
        break;
    case 5:
        printf("%s: %d\n" , attribute, target_value);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].power);
        }
        break;
    case 6:
        printf("%s: %d\n" , attribute, target_value);
        for (int i = 0; i < 10; i++)
        {
            printf("\t\t%d) %s: %d\n", i + 1, hero_arr[i].name, hero_arr[i].combat);
        }
        break;
    }
    printf("de que superheroe desea ver su informacion?\n");
    fgets(input, 1024, stdin);
    return hero_arr[atoi(input) - 1]; //return only the hero who's information is to be seen
}

int nullHeroError(struct hero target_hero){
    if(target_hero.name == NULL){
        printf("ERROR: Heroe no encontrado\n");
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{

    struct hero *database = buildDB();
    struct hero heroq;
    char *input = malloc(1024);
    int programMode = 0;
    char **input_arr = (char **)malloc(4 * 1024);
    char* buffer = malloc(1024);

    if(argc == 1){
        printf("Porfavor especifique como desea correr el programa\n");
        return 0;
    }

    if (strcmp(argv[1], "-terminal") == 0 && argc > 0)
        programMode = 1;
    // terminal mode
    while (programMode == 1)
    {
        printf("Ingrese una consulta:\te.g: tophero power Black Cat / power 80 / hero Black Cat / salir\n");
        fgets(input, 1024, stdin);

        buffer = strdup(input);
        input_arr = terminalDecodeStr(buffer, 1);

        if (strcmp(buffer, "salir") == 0)
            return 0;

        if (strcmp(input_arr[0], "tophero") == 0)
        {
            heroq = topHeroByName(database, input_arr[2], input_arr[1]);
            if(nullHeroError(heroq)) continue;
            queryHero(database, heroq);
            continue;
        }
        else if (strcmp(input_arr[0], "hero") == 0)
        {
            input_arr = terminalDecodeStr(input, 0);
            heroq = searchTargetHero(database, input_arr[1]);
            if(nullHeroError(heroq)) continue;
            queryHero(database, heroq);
            continue;
        }
        else if (atoi(input_arr[1]) >= 0 && atoi(input_arr[1]) <= 731)
        {
            if(atoi(input_arr[1]) <= 0 || atoi(input_arr[1]) >= 731){
                printf("ERROR: Valor no valido\n");
                continue;
            }
            heroq = topHeroByValue(database, atoi(input_arr[1]), input_arr[0]);
            queryHero(database, heroq);
            continue;
        }
        else
        {
            printf("Comando Invalido\n");
            continue;
        }
    }
    // command line mode
    while (programMode == 0)
    {
        if (argc == 1)
        {
            printf("EROR: Se esperaba al menos un argumento\n");
            break;
        }
        if (strcmp(argv[1], "-tophero") == 0)
        {
            if(argc < 4){
                printf("ERROR: Se esperaban al menos 3 argumentos\n");
                break;
            } 

            // get hero name block
            char *target_hero_name = malloc(1024);
            int i, v = 0, size = argc - 1;

            for(i = 3; i <= size; i++) {
                target_hero_name = (char *)realloc(target_hero_name, (v + strlen(argv[i])));
                strcat(target_hero_name, argv[i]);
                if(i == size) break;
                strcat(target_hero_name, " ");
            }

            //do query
            struct hero heroq = topHeroByName(database, target_hero_name, argv[2]);
            queryHero(database, heroq);
            break;
        }
        else if (strcmp(argv[1], "-hero") == 0)
        {
            if(argc < 3){
                printf("ERROR: Se esperaban al menos 2 argumentos\n");
                break;
            } 
            // get hero name block
            char *target_hero_name = malloc(1024);
            int i, v = 0, size = argc - 1;

            for(i = 2; i <= size; i++) {
                target_hero_name = (char *)realloc(target_hero_name, (v + strlen(argv[i])));
                strcat(target_hero_name, argv[i]);
                if(i == size) break;
                strcat(target_hero_name, " ");
            }
            //do query
            struct hero heroq = searchTargetHero(database, target_hero_name);
            queryHero(database, heroq);
            break;
        }

        else if (strcmp(argv[1], "-topvalue") == 0){
            if(argc < 4){
                printf("ERROR: Se esperaban al menos 3 argumentos\n");
                break;
            }
            if(atoi(argv[3]) > 731 || atoi(argv[3]) < 0){
                printf("ERROR: valor no valido\n");
                break;
            }
            struct hero heroq = topHeroByValue(database, atoi(argv[3]), argv[2]);
            queryHero(database, heroq);
            break;
        }
        else {printf("Invalid command\n"); break;}
    }


    free(buffer);
    free(input);
    free(input_arr);
    free(database);
    return 0;
}
