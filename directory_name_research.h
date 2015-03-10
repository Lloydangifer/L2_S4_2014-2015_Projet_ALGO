#ifndef DIRECTORY_NAME_RESEARCH_H
#define DIRECTORY_NAME_RESEARCH_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <sys/types.h>

#include "directory_generate.h"

void directory_search(const struct directory *self,const char *last_name);
void directory_sort(struct directory *self);
void directory_swap(struct directory *self,size_t start,size_t end);
ssize_t directory_partition(struct directory *self, ssize_t start,ssize_t end);
void directory_sort_part(struct directory *self,ssize_t start,ssize_t end);
void directory_search_opt(const struct directory *self,const char *last_name);
void directory_search_opt_part(const struct directory *self,const char *last_name, size_t start, size_t end);

#endif
