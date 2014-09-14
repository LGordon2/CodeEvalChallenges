#include <stdio.h>

#define BUF_SIZE 128

int main(int argc, char **argv){

    if(argc < 2){
        fprintf(stderr, "File not found!\n");
        return 1;
    }
    FILE *ifp;
    ifp = fopen(argv[1], "rb");
    char buf[BUF_SIZE];
    int bytes_read, total_bytes_read = 0;

    while((bytes_read = fread(buf, 1, BUF_SIZE, ifp)) > 0){
        total_bytes_read += bytes_read;
    }
    printf("%d\n", total_bytes_read);
    return 0;
}