#include "index.h"

struct index_bucket *index_bucket_add(struct index_bucket *self,const struct directory_data *data){
    assert(self);
    assert(data);
    if(self==NULL){
        struct index_bucket *new_bucket=malloc(sizeof(struct index_bucket));
        index_bucket_create(new_bucket);
        new_bucket->data=data;
        return new_bucket;
    }
    else if(self->data==NULL){
        self->data=data;
        self->next=NULL;
        return self;
    }
    else{
        struct index_bucket *new_bucket=malloc(sizeof(struct index_bucket));
        index_bucket_create(new_bucket);
        new_bucket->data=data;
        if(self->next==NULL){
            new_bucket->next=NULL;
            self->next=new_bucket;
        }
        else{
            new_bucket->next=self->next;
            self->next=new_bucket;
        }
        return new_bucket;
    }
}
void index_bucket_destroy(struct index_bucket *self){
    assert(self);
    if(self!=NULL){
        index_bucket_destroy(self->next);
        free(self);
    }
}
