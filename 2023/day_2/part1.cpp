#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <stdio.h>

int main(int argc, char **argv){
  if (argc < 2) {
    fprintf(stderr,"No input file given. Usage: %s input\n", argv[0]);
    exit(1);
  }

  std::ifstream file(argv[1]);
  if(!file.good()) {
    fprintf(stderr, "File not found\n");
    exit(1);
  }

  std::string line;
  int id;
  int acc = 0;
  while(std::getline(file, line)) {
    id = 0;
    sscanf(line.c_str(), "Game %d", &id);
    int idx_column = line.find(':');
    std::string game = line.substr(idx_column+2, line.length() - 1);
    size_t game_len = game.length();
    
     int num_aux = 0;
     int k = 0;
     for(size_t i = 0; i < game_len; ++i){
       k = 0;
       while(game[i] >= '0' && game[i] <= '9'){
         num_aux = k == 0 ? 0 : num_aux;
         num_aux = num_aux * (k > 0 ? 10 : 1) + game[i] - '0';
         ++i;
         ++k;
       }
    
       if(game[i] == 'r'){
         if(num_aux > 12){
           id = 0;
           break;
         }
         i += 4;
         continue;
       }
    
       if(game[i] == 'g'){
         if(num_aux > 13){
           id = 0;
           break;
         }
         i += 6;
         continue;
       }
    
       if(game[i] == 'b'){
         if(num_aux > 14){
           id = 0;
           break;
         }
         i += 5;
         continue;
       }
     }
    printf("id: %d\n", id);
    acc += id;
  }

  printf("Result: %d\n", acc);

  exit(0);
}
