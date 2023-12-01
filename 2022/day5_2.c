#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    char *stack;
    int top;
};

void push(struct stack *stack, char value)
{
    stack->stack[stack->top] = value;
    stack->top++;
}

char pop(struct stack *stack)
{
    --stack->top;
    return stack->stack[stack->top];
}

char peek(struct stack *stack)
{
    return stack->stack[stack->top-1];
}

struct stack *initialize(struct stack *stack, char *initial)
{
    stack->stack = malloc(1024);
    int len = strlen(initial);
    for(int i = 0; i < len; ++i){
        stack->stack[i] = initial[i];
    }
    stack->top = len;

    return stack;
}

int main()
{
    FILE *stream = fopen("inputday5", "r");
    char *buffer = malloc(100);
    size_t buffersize;
    int nread;
    int qty, from, to;
    int n = 9;
    char a[1024] = {0};
    struct stack *crates = malloc(n*sizeof (struct stack));


    initialize(&crates[0],"GTRW");
    initialize(&crates[1],"GCHPMSVW");
    initialize(&crates[2],"CLTSGM");
    initialize(&crates[3],"JHDMWRF");
    initialize(&crates[4],"PQLHSWFJ");
    initialize(&crates[5],"PJDNFMS");
    initialize(&crates[6],"ZBDFGCSJ");
    initialize(&crates[7],"RTB");
    initialize(&crates[8],"HNWLC");

    while((nread = getline(&buffer, &buffersize, stream)) != -1){
        sscanf(buffer, "move %d from %d to %d", &qty, &from, &to);

        for(int i = qty-1; i >= 0; --i){
            a[i] = pop(&crates[from-1]);
        }

        for(int i = 0; i < qty; ++i){
            push(&crates[to-1], a[i]);
        }
    }

    for(int i = 0; i < n; ++i){
        printf("%c", peek(&crates[i]));
    }

    fclose(stream);
    free(buffer);
    for(int i = 0; i < n; ++i){
        free(crates[i].stack);
    }

    return 0;
}
