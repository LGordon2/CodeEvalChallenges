#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>

#define BUF_SIZE 128

void chomp(char *str)
{
    if (*str && str[strlen(str)-1]=='\n')
        str[strlen(str)-1]=0;
    return;
}

char **insert(char * str, char **astr, int asize){
    int i, astr_pos=0;
    char **nastr;
    nastr = malloc(sizeof(char *) * asize);

    /* Copy while the string inserted is less than the string in the array*/
    for(astr_pos=0, i=0; astr_pos<asize-1; astr_pos++, i++){
        if(strlen(str) < strlen(astr[astr_pos])){
            break;
        }
        nastr[i] = malloc(sizeof(char) * strlen(astr[astr_pos]) + 1);
        strcpy(nastr[i], astr[astr_pos]);
        free(astr[astr_pos]);
    }

    /* Insert the string. */
    nastr[i] = malloc(sizeof(char) * strlen(str) + 1);
    strcpy(nastr[i], str);

    /* Insert the rest. */
    for(i+=1, astr_pos; astr_pos<asize-1; astr_pos++, i++){
        nastr[i] = malloc(sizeof(char) * strlen(astr[astr_pos]) + 1);
        strcpy(nastr[i], astr[astr_pos]);
        free(astr[astr_pos]);
    }
    free(astr);
    return nastr;
}

int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stderr, "Not enough arguments!\n");
        return 1;
    }

    FILE *f;
    char buf[BUF_SIZE];
    int num_lines, i, size = 0;

    f = fopen(argv[1], "r");

    fgets(buf, BUF_SIZE, f);
    num_lines = atoi(buf);
    char **lines;

    while(fgets(buf, BUF_SIZE, f) != NULL){
        chomp(buf);
        size++;
        lines = insert(buf, lines, size);
    }

    if(num_lines > size){
        fprintf(stderr, "Too many lines requested!!\n");
        exit(1);
    }

    for(i=size-1; i>size-1-num_lines; --i){
        printf("%s\n", lines[i]);
    }
    return 0;
}