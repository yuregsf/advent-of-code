#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    unsigned long long size;
    unsigned long long childrenlen;
    struct node *parent;
    struct node *children;
} Node;

Node *find_node(Node *head, char *name){
    for(unsigned long long i = 0; i < head->childrenlen; ++i){
        if(strcmp(head->children[i].name, name) == 0){
            return &head->children[i];
        }
    }
    return NULL;
}

Node *readcom(Node *head, char *command, char *argument){
    if(strcmp("ls", command) == 0) return head;

    if(strcmp("cd", command) == 0){
        if(strcmp(argument, head->name) == 0) return head;

        if(strcmp("..", argument) == 0){
            head = head->parent;
            return head;
        }

        Node *find = find_node(head, argument);
        if(find != NULL) head = find;
        // printf("%s -> %s\n", head->parent->name, head->name);
        return head;
    }

    return head;
}

Node *new_node(char *name, Node *parent){
    Node *new = malloc(sizeof(Node));

    new->name = malloc(256);
    strcpy(new->name, name);

    if(parent == NULL)
        new->parent = new;
    else
        new->parent = parent;
    new->size = 0;
    new->children = NULL;
    new->childrenlen = 0;

    return new;
}

void insert_node(Node *head, char *name){
    head->childrenlen++;
    head->children = realloc(head->children, head->childrenlen*sizeof(Node));
    head->children[head->childrenlen-1] = *new_node(name, head);
}

void sum_files(Node *head, unsigned long long size){
    head->size += size;
    Node *aux = head;
    while(aux->parent != aux){
        aux->parent->size += size;
        aux = aux->parent;
    }
}

unsigned long long printresult(Node *head, unsigned long long threshold){
    unsigned long long current_size = head->size <= threshold ? head->size : 0;
    if(head->childrenlen == 0) return current_size;

    for(unsigned long long i = 0; i < head->childrenlen; ++i){
        printf("%llu\n", i);
        return current_size + printresult(&head->children[i], threshold);
    }
    return 0;
}

unsigned long long count = 0;
void printtable(Node *head, int depth){
    for(int i = 0; i < depth; ++i){
        printf("|\t");
    }
    if(head->size <= 100000) count += head->size;
    printf("%s: %llu\n", head->name, head->size);
    for(int i = 0; i < head->childrenlen; ++i){
        printtable(&head->children[i], depth+1);
    }
}

int main()
{
    FILE *stream = fopen("inputday7", "r");
    char *buffer;
    size_t bufferlen;
    char *c1 = malloc(256);
    char *c2 = malloc(256);
    char *c3 = malloc(256);

    char *endptr;

    Node *fstable = new_node("/", NULL);
    Node *needle = fstable;

    while(getline(&buffer, &bufferlen, stream) != -1){
        sscanf(buffer, "%s %s %s", c1, c2, c3);

        if(*c1 == '$'){
            needle = readcom(needle,c2, c3);
        }
        else if(strcmp(c1, "dir") == 0) {
            insert_node(needle, c2);
        }
        else {
            sum_files(needle, strtoull(c1, &endptr, 10));
        }

        *c1 = 0;
        *c2 = 0;
        *c3 = 0;
    }

    printtable(fstable, 0);
    // printf("\n\nRESULTADO: %llu\n", printresult(fstable, 100000));
    printf("\n\nRESULTADO: %llu\n", count);
    return 0;
}
