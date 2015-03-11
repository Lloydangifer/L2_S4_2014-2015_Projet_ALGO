#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

struct index_bucket{
    const struct directory_data *data;
    struct index_bucket *next;
};
typedef size_t (*index_hash_func_t)(const struct directory_data *data);

struct index_bucket *index_bucket_add(struct index_bucket *self,const struct directory_data *data);
void index_bucket_destroy(struct index_bucket *self);

#endif
