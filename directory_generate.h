#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

void directory_data_print(const struct directory_data *data);
void directory_data_random(struct directory_data *data);