#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *stream = fopen("inputday3", "r");
    size_t nread;
    char *line;
    size_t line_size;
    int count = 0;
    int n = 0;
    int *found = malloc(52*4);

    while((nread = getline(&line, &line_size, stream)) != -1){
        for(int j = 0; j < strlen(line)-1; ++j){
            char c = line[j];
            int a = 'a' <= c && c <= 'z' ? c-97 : c-39;
            if(n == 0){
                found[a] = 1;
            }
            else if(n == 1 && found[a] == 1){
                found[a] = 2;
            }
            else if(n == 2 && found[a] == 2){
                found[a] = 3;
            }
        }
        if(n == 2) {
            for(int i = 0; i < 52; ++i){
                if(found[i] == 3) count += i+1;
                found[i] = 0;
            }
        }
        n = (n+1)%3;
    }
    printf("RESULTADO: %d\n", count);
    
    free(found);
    fclose(stream);
    free(line);

    return 0;
}
