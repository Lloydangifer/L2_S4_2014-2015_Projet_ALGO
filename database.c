#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NAME_LENGTH_MIN 3
#define NAME_LENGTH_MAX 10
#define TELEPHONE_LENGTH 8

struct directory_data {
    char last_name[NAME_LENGTH_MAX + 1];
    char first_name[NAME_LENGTH_MAX + 1];
    char telephone[TELEPHONE_LENGTH + 1];
};
struct directory {
    struct directory_data **data;
    size_t size;
    size_t capacity;
};

void directory_data_print(const struct directory_data *data){
    for(int i=0;i<=NAME_LENGTH_MAX;++i){
        printf("%c",data->last_name[i]);
    }
    printf(" ");
    for(int i=0;i<=NAME_LENGTH_MAX;++i){
        printf("%c",data->first_name[i]);
    }
    printf(": ");
    for(int i=0;i<=TELEPHONE_LENGTH;++i){
        printf("%c",data->telephone[i]);
    }
}
void directory_data_random(struct directory_data *data){
    int last_name_length=(int)((rand()%(NAME_LENGTH_MAX-NAME_LENGTH_MIN))+NAME_LENGTH_MIN);
    int first_name_length=(int)((rand()%(NAME_LENGTH_MAX-NAME_LENGTH_MIN))+NAME_LENGTH_MIN);
    bool consonne=true;
    for(int i=0;i<last_name_length;++i){
        if(consonne==true){
                int lettre=(int)(rand()%15);
                switch(lettre){
                    case 0:
                        data->last_name[i]+='B';
                    break;
                    case 1:
                        data->last_name[i]+='C';
                    break;
                    case 2:
                        data->last_name[i]+='D';
                    break;
                    case 3:
                        data->last_name[i]+='F';
                    break;
                    case 4:
                        data->last_name[i]+='G';
                    break;
                    case 5:
                        data->last_name[i]+='H';
                    break;
                    case 6:
                        data->last_name[i]+='J';
                    break;
                    case 7:
                        data->last_name[i]+='L';
                    break;
                    case 8:
                        data->last_name[i]+='M';
                    break;
                    case 9:
                        data->last_name[i]+='N';
                    break;
                    case 10:
                        data->last_name[i]+='P';
                    break;
                    case 11:
                        data->last_name[i]+='R';
                    break;
                    case 12:
                        data->last_name[i]+='S';
                    break;
                    case 13:
                        data->last_name[i]+='T';
                    break;
                    case 14:
                        data->last_name[i]+='V';
                    break;
                }
                consonne=false;
        }
        else{
            int lettre=(int)(rand()%5);
            switch(lettre){
                case 0:
                    data->last_name[i]+='A';
                break;
                case 1:
                    data->last_name[i]+='E';
                break;
                case 2:
                    data->last_name[i]+='I';
                break;
                case 3:
                    data->last_name[i]+='O';
                break;
                case 4:
                    data->last_name[i]+='U';
                break;
            }
        }
    }
    data->last_name[last_name_length]+='\0';
    consonne=true;
        for(int i=0;i<first_name_length;++i){
        if(consonne==true){
                int lettre=(int)(rand()%15);
                switch(lettre){
                    case 0:
                        data->first_name[i]+='B';
                    break;
                    case 1:
                        data->first_name[i]+='C';
                    break;
                    case 2:
                        data->first_name[i]+='D';
                    break;
                    case 3:
                        data->first_name[i]+='F';
                    break;
                    case 4:
                        data->first_name[i]+='G';
                    break;
                    case 5:
                        data->first_name[i]+='H';
                    break;
                    case 6:
                        data->first_name[i]+='J';
                    break;
                    case 7:
                        data->first_name[i]+='L';
                    break;
                    case 8:
                        data->first_name[i]+='M';
                    break;
                    case 9:
                        data->first_name[i]+='N';
                    break;
                    case 10:
                        data->first_name[i]+='P';
                    break;
                    case 11:
                        data->first_name[i]+='R';
                    break;
                    case 12:
                        data->first_name[i]+='S';
                    break;
                    case 13:
                        data->first_name[i]+='T';
                    break;
                    case 14:
                        data->first_name[i]+='V';
                    break;
                }
                consonne=false;
        }
        else{
            int lettre=(int)(rand()%5);
            switch(lettre){
                case 0:
                    data->first_name[i]+='A';
                break;
                case 1:
                    data->first_name[i]+='E';
                break;
                case 2:
                    data->first_name[i]+='I';
                break;
                case 3:
                    data->first_name[i]+='O';
                break;
                case 4:
                    data->first_name[i]+='U';
                break;
            }
        }
    }
    data->first_name[first_name_length]+='\0';
    for(int i=0;i<TELEPHONE_LENGTH;++i){
        data->telephone[i]+=((int)(rand()%10));
    }
    data->telephone[TELEPHONE_LENGTH+1]+='\0';
}
void directory_create(struct directory *self){
    self->data=(struct directory_data **)malloc(sizeof(struct directory_data));
    self->size=(size_t)malloc(sizeof(size_t));
    self->capacity=(size_t)malloc(sizeof(size_t));
}
void directory_destroy(struct directory *self){
    free(self);
}

int main(int argc, char *argv[]){
}
