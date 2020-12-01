#include <stdio.h>
#include <stdlib.h>

void copyArray(int *original, int *copy, int size){
	for (int i = 0; i < size; i++){
		copy[i] = original[i];
	}
}

int main(){
	int *aux = (int *) malloc(300 * sizeof aux);
	int value, i=0, noun, verb;
	while(scanf("%d", &value) != EOF){
		aux[i++] = value;
	}
	int *v = (int *) malloc(i * sizeof v);
	aux = (int *) realloc(aux, i * sizeof aux);
	for(noun = 0; noun<100 && v[0] != 19690720; noun++){
		for (verb = 0; verb < 100 && v[0] != 19690720; verb++){
			copyArray(aux, v, i);
			v[1] = noun;
			v[2] = verb;
			for(int j = 0; j < i; j+=4){
				if(v[j] == 1)
					v[v[j+3]] = v[v[j+1]]+v[v[j+2]];
				else if(v[j] == 2)
					v[v[j+3]] = v[v[j+1]]*v[v[j+2]];
				else if(v[j] == 99) break;
			}			
		}		
	}
	printf("%d\n", 100*(noun-1)+(verb-1));
	printf("%d\n", v[0]);
	free(v);
	free(aux);
	return 0;
}
