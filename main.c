#include "directory_generate.h"
#include "directory_name_research.h"

int main(int argc, char *argv[]){
    struct directory *dir=malloc(sizeof(struct directory));
    directory_create(dir);
    directory_random(dir,100);
    directory_sort(dir);
    for(int i=0;i<dir->size;i++){
        directory_data_print(dir->data[i]);
    }
    printf("Présence de PAPACEB:\n");
    directory_search(dir,"PAPACEB");
    printf("Présence de PAPACEB(tri optimisé):\n");
    directory_search_opt(dir,"PAPACEB");
    directory_destroy(dir);
    return 0;
}
