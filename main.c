#include "directory_generate.h"
#include "directory_name_research.h"
#include "index.h"

#define BUFSIZE 100

void clean_newline(char *buf, size_t size){
    assert(buf);
    assert(size >= 0);
    size_t i = 0;
    while(i<size){
        if(buf[i]=='\n'){
            buf[i]='\0';
            i=size;
        }
        i++;
    }
}
int main(int argc, char *argv[]){
    struct directory *dir=malloc(sizeof(struct directory));
    directory_create(dir);
    directory_random(dir,1000000);
    directory_sort(dir);
    bool restart=true;
    char buf[BUFSIZE];
    while(restart==true){
        printf("What do we do now?\n1: Search by last name (not optimised)\n2: Search by last name (optimised)\n3: Search by first name\n4: Search by telephone\n5: Show full directory\nq: Quit\nYour choice:\n");
        printf("> ");
        fgets(buf,BUFSIZE,stdin);
        clean_newline(buf,BUFSIZE);
        switch(buf[0]){
            case '1':
                printf("Enter the last name you want to search:\n");
                printf("> ");
                fgets(buf,BUFSIZE,stdin);
                clean_newline(buf,BUFSIZE);
                directory_search(dir,buf);
            break;
            case '2':
                printf("Enter the last name you want to search: ");
                printf("> ");
                fgets(buf,BUFSIZE,stdin);
                clean_newline(buf,BUFSIZE);
                directory_search_opt(dir,buf);
            break;
            case '3':
                printf("Sorry but choice not implemented yet, please try another choice\n");
            break;
            case '4':
                printf("Sorry but choice not implemented yet, please try another choice\n");
            break;
            case '5':
                directory_print(dir);
            break;
            case 'q':
                printf("Good bye !\n");
                restart=false;
            break;
            default:
                printf("Bad choice, please try again\n");
            break;
        }
    }
    directory_destroy(dir);
    return 0;
}
