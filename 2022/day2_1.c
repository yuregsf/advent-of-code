#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *stream = fopen("inputday2", "r");
    size_t nread;
    char *line;
    size_t line_size;
    size_t count = 0;

    int results[3][3] = {{3,6,0}, {0,3,6}, {6,0,3}};

    while((nread = getline(&line, &line_size, stream)) != -1){
        int oponente = line[0]-64;
        int eu = line[2]-87;
        int resultado = results[oponente-1][eu-1];

        count += eu + resultado;
    }

    printf("%ld\n", count);

    free(line);
    fclose(stream);

    return 0;
}
