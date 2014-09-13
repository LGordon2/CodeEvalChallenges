#include "stdio.h"

int main(int argc, char **argv){
  int i, j;

  for(i=1; i<13; i++){
    for(j=1; j<13; j++){
      printf("%4d", i*j);
    }
    printf("\n");
  }

  return 0;
}
