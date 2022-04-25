#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//#define HEROMEMSIZE (sizeof(short int) + 30*sizeof(char) + )

//should return an array of vals
char* getVal(char* line, int index){
    char* token;
    for (token = strtok(line, ";");
            token && *token;
            token = strtok(NULL, ";\n"))
    {
        if (!--index)
            return token;
    }
    return NULL;
}

char**  getHeroArr(char* line){
    char*token = strtok(line, ";");
    int i = 0;
    static char* array[27];

    while (token != NULL) {
        array[i++]=token;
        token = strtok(NULL, ";");
    }
    return (array);
}


char*** buildHeroArr(){
    static char** hero_pointer_array[731]; //array of 731 pointers, each leading to a hero
    int counter = 0;

    FILE *input_file;
    input_file = fopen("data.txt", "r");

    char* line = (char *)malloc(1024); //line pointer declaration
    char* dupestr = (char *)malloc(1024);
    
    int strSize = 30;
    int memory_size = 7 * sizeof(short int) + 20 * (strSize); //7 small ints and 20 strings
    char** hero_pointer;

    while(fgets(line, 1024, input_file)){
        dupestr = strdup(line);
        
        
        /* Visualize all values of a hero_pointer
        for(int i=0;i<27;i++){
            printf("%s\n",hero_pointer[i]);
        }
        */
        hero_pointer_array[counter] = getHeroArr(line);
        printf("%p\n",hero_pointer_array[0][0]);
        
        free(dupestr);

        counter ++;
    }
    free(line);
    return (hero_pointer_array);
}

    int valueTypeOrder[] = {0,1,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    //create getValuefromMemory function 

int main(int argc , char * argv) {
    
    char*** hero_pointer_array = buildHeroArr();
    printf("%s\n", hero_pointer_array[0][0]);  // [i][j][k] i = hero, j=attribute, k 
    printf("%s\n", hero_pointer_array[0][1]);  // [i][j][k] i = hero, j=attribute, k 
    printf("%s\n", hero_pointer_array[0][3]);  // [i][j][k] i = hero, j=attribute, k 


    free(hero_pointer_array);
    return 0;

}
/*
TODO:
- getHeroArr() always returns the same pointer, data is stored in the same place
NOTES:
- if buildHeroArr() doesnt work, try definiing hero_pointer_array as static int
*/