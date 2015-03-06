#include "directory_name_research.h"

void directory_search(const struct directory *self,const char *last_name){
    assert(self);
    assert(last_name);
    for(int i=0;i<self->size;i++){
        if(strcmp(self->data[i]->last_name,last_name)==0){
            directory_data_print(self->data[i]);
        }
    }
}
