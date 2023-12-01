#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *stream = fopen("inputday4", "r");
    char *buffer;
    size_t buffersize;
    int nread;
    int count = 0;

    while((nread = getline(&buffer, &buffersize, stream)) != -1){
        int a1,a2;
        int b1,b2;

        sscanf(buffer, "%d-%d,%d-%d", &a1,&a2,&b1,&b2);
        printf("%d-%d,%d-%d", a1,a2,b1,b2);
        if((a1 >= b1 && a1 <= b2) || (a2 >= b1 && a2 <= b2) || (b1 >= a1 && b1 <= a2) || (b2 >= a1 && b2 <= a2)) {
            count++;
            printf(" OVERLAP!");
        }
        printf("\n");
    }

    printf("%d", count);


    return 0;
}
