#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ctol(char *str, size_t len)
{
    size_t result = 0;
    for(size_t i = 0; i < len-1; ++i){
        size_t c = (size_t)str[i];
        if(c > 47 && c < 58){
            result += result * 10 + c-48;
        }
    }
    return result;
}

int main()
{
    char *line = NULL;
    size_t len = 0;
    size_t max = 0;
    size_t max2 = 0;
    size_t max3 = 0;
    size_t count = 0;
    ssize_t nread;
    char *endptr;
    FILE *stream = fopen("inputday1", "r");
    size_t buffer[1000];

    if(stream == NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while((nread = getline(&line, &len, stream)) != -1){
        count += strtol(line, &endptr, 10);
        if(line[0] < 48) {
            if(count >= max){
                if(max > max2){
                    if(max2 > max3){
                        max3 = max2;
                    }
                    max2 = max;
                }
                max = count;
            }
            else if(count >= max2){
                if(max2 > max3){
                    max3 = max2;
                }
                max2 = count;
            }
            else if(count >= max3){
                max3 = count;
            }
            printf("%ld %ld %ld\n", max, max2, max3);
            count = 0;
        }
    }
    if(count >= max){
        if(max > max2){
            max2 = max;
            if(max2 > max3){
                max3 = max2;
            }
        }
        max = count;
    }
    else if(count >= max2){
        if(max2 > max3){
            max3 = max2;
        }
        max2 = count;
    }
    else if(count >= max3){
        max3 = count;
    }

    printf("%ld\n", max+max2+max3);
    free(line);
    fclose(stream);

    exit(EXIT_SUCCESS);
}
