#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
  if (argc < 2) {
    fprintf(stderr,"No input file given. Usage: %s input\n", argv[0]);
    exit(1);
  }

  FILE *fd = fopen(argv[1], "r");
  if(fd == NULL) {
    printf("File not found\n");
    return 1;
  }

  char *line = NULL;
  size_t len;
  int acc = 0;
  while(getline(&line, &len, fd) != -1){
    int i = 0;
    int sign = 1;

    while(line[i] && i >= 0) {
      if(line[i] >= '0' && line[i] <= '9') {
        acc += (line[i] - '0')*(sign == 1 ? 10 : 1);
        if(sign == -1) break;
        sign = -1;
        i = strlen(line)-1;
      }
      i += 1*sign;
    }
  }

  printf("Result: %d\n", acc);

  free(fd);
  free(line);
  exit(0);
}
