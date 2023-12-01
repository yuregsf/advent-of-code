#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{

    if(argc < 3){
        printf("USAGE: day6 message size\n");
        return EXIT_FAILURE;
    }

    char buffer[10240];
    strcpy(buffer, argv[1]);
    char *end_ptr;
    size_t bufferlen = strlen(buffer);
    size_t result;
    size_t n = strtoull(argv[2], &end_ptr, 10);
    int found = 0;

    for(size_t i = 0; i < bufferlen - n && found == 0; ++i){
        found = 1;
        for(size_t j = i; j < i+n-1; ++j){
            for(size_t k = j+1; k < i+n; ++k){
                if(buffer[k] == buffer[j]){
                    found = 0;
                    break;
                } 
            }
            if(found == 0) break;
        }
        if(found == 1){
            result = i+n;
        }
    }

    printf("%ld\n", result);
    return 0;
}
