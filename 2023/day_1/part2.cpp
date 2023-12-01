#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>

int main(int argc, char **argv){
  if (argc < 2) {
    fprintf(stderr,"No input file given. Usage: %s input\n", argv[0]);
    exit(1);
  }

  std::string wordlist[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  std::ifstream file(argv[1]);
  if(!file.good()) {
    printf("File not found\n");
    return 1;
  }

  std::string line;
  int acc = 0;
  while(std::getline(file, line)){
    int left_idx = line.length()-1;
    int left_value = 0;
    int right_idx = 0;
    int right_value = 0;
    int found = -1;

    for(int i = 0; i < 9; ++i){
      found = line.find(wordlist[i]);
      if(found != -1) {
        left_value = found < left_idx ? i+1 : left_value;
        left_idx = found < left_idx ? found : left_idx;
      }

      found = line.rfind(wordlist[i]);
      if(found != -1) {
        right_value = found > right_idx ? i+1 : right_value;
        right_idx = found > right_idx ? found : right_idx;
      }
    }

    for(int i = 0; i <= left_idx; ++i){
      if(line[i] >= '0' && line[i] <= '9') {
        left_value = line[i] - '0';
        break;
      }
    }

    for(int i = line.length()-1; i >= right_idx; --i){
      if(line[i] >= '0' && line[i] <= '9') {
        right_value = line[i] - '0';
        break;
      }
    }
    acc += left_value*10 + right_value;
  }

  printf("Result: %d\n", acc);

  exit(0);
}
