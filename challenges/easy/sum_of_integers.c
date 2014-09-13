#include "stdio.h"

int main(int argc, char **argv){
  if(argc < 2){
    fprintf(stderr, "Not enough arguments!\n");
    return 1;
  }

  FILE *f;
  char line[1024];
  int sum = 0;
  f = fopen(argv[1], "r");
  while (fgets(line, 1024, f)) {

    // Skip empty lines
    if (line[0] == '\n') {
      continue;
    }

    // Do something with the line
    sum += atoi(line);    
  }
  printf("%d\n", sum);
  fclose(f);
  return 0;
}
