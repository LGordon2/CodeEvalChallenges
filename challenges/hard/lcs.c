#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 128

int subsequence_in(char *test_string, char *subsequence){
    int i, str_pos = 0;
    for(i=0; i<strlen(test_string); i++){
        if(test_string[i] == subsequence[str_pos]){
            if(++str_pos && strlen(subsequence) == str_pos){
                return 1;
            }
        }
    }
    return 0;
}

char * print_subsequences(char *prefix, char *string1, char *string2, int size, int add){
    int i, subsequence_size = strlen(prefix) + 2;
    char *subsequence, *rt_subsequence = NULL;

    for(i=add; i<strlen(string1); i++){
        subsequence = malloc(sizeof(char) * subsequence_size);
        strcpy(subsequence, prefix);
        subsequence[subsequence_size-2] = string1[i];
        subsequence[subsequence_size-1] = '\0';
        if(size == 1 && subsequence_in(string2, subsequence)){
            return subsequence;
        }else{
            rt_subsequence = print_subsequences(subsequence, string1, string2, size - 1, i + 1);
            if(rt_subsequence){
                return rt_subsequence;
            }
            free(rt_subsequence);
        }
        free(subsequence);
    }
    return NULL;
}

void print_lcs(char *test_case){
    char *pch;
    pch = strtok(test_case, ";");
    char *string1 = pch, *string2 = strtok(NULL, ";"), *subsequence, *longest_subsequence = "";
    int i;
    //Get all subsequences of length N.
    for(i=strlen(string1)/3;i<=strlen(string1);i++){
        subsequence = print_subsequences("", string1, string2, i, 0);
        if(subsequence && strlen(subsequence) > strlen(longest_subsequence)){
            longest_subsequence = malloc(sizeof(char) * (strlen(subsequence) + 1));
            strcpy(longest_subsequence, subsequence);
            free(subsequence);
        }
    }
    printf("%s\n", longest_subsequence);
}

int main(int argc, char **argv){
    if(argc < 2){
        fprintf(stderr, "File not found!\n");
        return 1;
    }
    FILE *ifp;
    ifp = fopen(argv[1], "rb");
    char buf[BUF_SIZE];

    while(fgets(buf, BUF_SIZE, ifp)){
        print_lcs(buf);
    }

    fclose(ifp);
}