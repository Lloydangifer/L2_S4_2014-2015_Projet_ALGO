#include "directory_generate.h"

void directory_data_print(const struct directory_data *data){
    assert(data);
    printf("%s %s: %s\n",data->last_name,data->first_name,data->telephone);
}
void directory_data_random(struct directory_data *data){
    assert(data);
    int last_name_length=(int)((rand()%(NAME_LENGTH_MAX-NAME_LENGTH_MIN)+1)+NAME_LENGTH_MIN);
    int first_name_length=(int)((rand()%(NAME_LENGTH_MAX-NAME_LENGTH_MIN)+1)+NAME_LENGTH_MIN);
    char *last_name=calloc(last_name_length+1,sizeof(char));
    char *first_name=calloc(first_name_length+1,sizeof(char));
    char *telephone=calloc(TELEPHONE_LENGTH+1,sizeof(char));
    bool consonne=true;
    for(int i=0;i<last_name_length;i++){
        if(consonne==true){
                int lettre=(int)(rand()%15);
                switch(lettre){
                    case 0:
                        last_name[i]='B';
                    break;
                    case 1:
                        last_name[i]='C';
                    break;
                    case 2:
                        last_name[i]='D';
                    break;
                    case 3:
                        last_name[i]='F';
                    break;
                    case 4:
                        last_name[i]='G';
                    break;
                    case 5:
                        last_name[i]='H';
                    break;
                    case 6:
                        last_name[i]='J';
                    break;
                    case 7:
                        last_name[i]='L';
                    break;
                    case 8:
                        last_name[i]='M';
                    break;
                    case 9:
                        last_name[i]='N';
                    break;
                    case 10:
                        last_name[i]+='P';
                    break;
                    case 11:
                        last_name[i]='R';
                    break;
                    case 12:
                        last_name[i]='S';
                    break;
                    case 13:
                        last_name[i]='T';
                    break;
                    case 14:
                        last_name[i]='V';
                    break;
                }
                consonne=false;
        }
        else{
            int lettre=(int)(rand()%5);
            switch(lettre){
                case 0:
                    last_name[i]='A';
                break;
                case 1:
                    last_name[i]='E';
                break;
                case 2:
                    last_name[i]='I';
                break;
                case 3:
                    last_name[i]='O';
                break;
                case 4:
                    last_name[i]='U';
                break;
            }
            consonne=true;
        }
    }
    last_name[last_name_length-1]='\0';
    consonne=true;
        for(int i=0;i<first_name_length;i++){
        if(consonne==true){
                int lettre=(int)(rand()%15);
                switch(lettre){
                    case 0:
                        first_name[i]='B';
                    break;
                    case 1:
                        first_name[i]='C';
                    break;
                    case 2:
                        first_name[i]='D';
                    break;
                    case 3:
                        first_name[i]='F';
                    break;
                    case 4:
                        first_name[i]='G';
                    break;
                    case 5:
                        first_name[i]='H';
                    break;
                    case 6:
                        first_name[i]='J';
                    break;
                    case 7:
                        first_name[i]='L';
                    break;
                    case 8:
                        first_name[i]='M';
                    break;
                    case 9:
                        first_name[i]='N';
                    break;
                    case 10:
                        first_name[i]='P';
                    break;
                    case 11:
                        first_name[i]='R';
                    break;
                    case 12:
                        first_name[i]='S';
                    break;
                    case 13:
                        first_name[i]='T';
                    break;
                    case 14:
                        first_name[i]='V';
                    break;
                }
                consonne=false;
        }
        else{
            int lettre=(int)(rand()%5);
            switch(lettre){
                case 0:
                    first_name[i]='A';
                break;
                case 1:
                    first_name[i]='E';
                break;
                case 2:
                    first_name[i]='I';
                break;
                case 3:
                    first_name[i]='O';
                break;
                case 4:
                    first_name[i]='U';
                break;
            }
            consonne=true;
        }
    }
    first_name[first_name_length]='\0';
    for(int i=0;i<TELEPHONE_LENGTH;i++){
        telephone[i]=(char)('0'+rand()%10);
    }
    telephone[TELEPHONE_LENGTH]='\0';

    strcpy(data->last_name,last_name);
    strcpy(data->first_name,first_name);
    strcpy(data->telephone,telephone);

    free(last_name);
    free(first_name);
    free(telephone);
}
void directory_create(struct directory *self){
    self->data=NULL;
    self->size=0;
    self->capacity=0;
}
void directory_destroy(struct directory *self){
    assert(self);
    for(int i=0 ;i<self->capacity;i++){
      free(self->data[i]);
    }
    free(self->data);
    free(self);
}
void directory_add (struct directory *self, struct directory_data *data){
    assert(self);
    assert(data);
    if(self->capacity==0){
        self->capacity+=10;
        self->data=calloc(self->capacity,sizeof(struct directory_data *));
    }
    if(self->capacity==self->size){
       self->capacity*=2;
       struct directory_data **temp=calloc(self->capacity,sizeof(struct directory_data *));
       memcpy(temp,self->data,sizeof(struct directory_data*)*self->size);
       free(self->data);
       self->data=temp;
    }
    self->data[self->size]=data;
    self->size++;
 }
 void directory_random(struct directory *self, size_t n){
    assert(self);
    for(int i=0;i<n;i++){
        struct directory_data *data=malloc(sizeof(struct directory_data));
        directory_data_random(data);
        directory_add(self,data);
    }
 }
