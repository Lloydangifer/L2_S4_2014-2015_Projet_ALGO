#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH_MIN 3
#define NAME_LENGTH_MAX 10
#define TELEPHONE_LENGTH 8

struct directory_data {
    char last_name[NAME_LENGTH_MAX + 1];
    char first_name[NAME_LENGTH_MAX + 1];
    char telephone[TELEPHONE_LENGTH + 1];
};

void directory_data_print(const struct directory_data *data){
    for(i=0;i<=NAME_LENGTH_MAX;++i){
        printf("%c",last_name[i]);
    }
    printf(" ");
    for(i=0;i<=NAME_LENGTH_MAX;++i){
        printf("%c",first_name[i]);
    }
    printf(": ");
    for(i=0;i<=TELEPHONE_LENGTH;++i){
        printf("%c",telephone[i]);
    }
}
