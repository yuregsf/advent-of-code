#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *stream = fopen("inputday2", "r");
    size_t nread;
    char *line;
    size_t line_size;
    size_t count = 0;

    int plays[3][3] = {{3,1,2}, {1,2,3}, {2,3,1}};

    while((nread = getline(&line, &line_size, stream)) != -1){
        //ASCII transformation
        int oponente = line[0]-64;
        int eu = line[2]-87; //1,2,3

        //Get result from lookup table
        int play = plays[oponente-1][eu-1];

        int ldw = (eu-1)*3;
        count +=  ldw + play;
    }

    printf("%ld\n", count);

    free(line);
    fclose(stream);

    return 0;
}
