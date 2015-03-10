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
void directory_sort(struct directory *self){
    assert(self);
    directory_sort_part(self,0,self->size-1);
}
void directory_swap(struct directory *self,size_t i,size_t l){
    assert(self);
    struct directory_data *temp=self->data[i];
    self->data[i]=self->data[l];
    self->data[l]=temp;
}
ssize_t directory_partition(struct directory *self, ssize_t start,ssize_t end){
    assert(self);
    ssize_t pivot_index=start;
    const char* pivot=self->data[pivot_index]->last_name;
    directory_swap(self,pivot_index,end);
    ssize_t l=start;
    for(ssize_t i=start;i<end;++i){
        if(strcmp(self->data[i]->last_name,pivot)<0){
            directory_swap(self,i,l);
            l++;
        }
    }
    directory_swap(self,l,end);
    return l;
}
void directory_sort_part(struct directory *self,ssize_t start,ssize_t end){
    assert(self);
    if(start<end){
        ssize_t p=directory_partition(self,start,end);
        directory_sort_part(self,start,p-1);
        directory_sort_part(self,p+1,end);
    }
}
void directory_search_opt(const struct directory *self,const char *last_name){
    assert(self);
    assert(last_name);
    directory_search_opt_part(self,last_name,0,self->size);
}
void directory_search_opt_part(const struct directory *self,const char *last_name, size_t start, size_t end){
    assert(self);
    assert(last_name);
    if(start==end){
        if(strcmp(self->data[start]->last_name,last_name)==0){
            directory_data_print(self->data[start]);
        }
    }
    size_t middle=(start+end)/2;
    if(strcmp(self->data[middle]->last_name,last_name)>0){
        directory_search_opt_part(self,last_name,start,middle);
    }
    else if(strcmp(self->data[middle]->last_name,last_name)<0){
        directory_search_opt_part(self,last_name,middle+1,end);
    }
}
