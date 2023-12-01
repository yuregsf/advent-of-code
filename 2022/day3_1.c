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
    char found[52] = {0};

    while((nread = getline(&line, &line_size, stream)) != -1){
        int half = (strlen(line))/2;
        for(int i = 0; i < half; ++i){
            for(int j = half; j < strlen(line); ++j){
                if(line[i] == line[j]){
                    int a = 'a' <= line[j] && line[j] <= 'z' ? line[j]-97 : line[j]-39;
                    found[a] = 1;
                } 
            }
        }
        for(int i = 0; i < 52; ++i){
            if(found[i] == 1) count += i+1;
            found[i] = 0;
        }
    }
    printf("RESULTADO: %d\n", count);
    fclose(stream);
    free(line);

    return 0;
}
