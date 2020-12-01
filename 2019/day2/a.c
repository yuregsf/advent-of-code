#include <stdio.h>
#include <stdlib.h>

int main(){
	int *v = (int *) malloc(300 * sizeof v);
	int value, i=0;
	while(scanf("%d", &value) != EOF)
		v[i++] = value;
	v = (int *) realloc(v, i * sizeof v);
	for(int j = 0; j < i; j+=4){
		if(v[j] == 1)
			v[v[j+3]] = v[v[j+1]]+v[v[j+2]];
		else if(v[j] == 2)
			v[v[j+3]] = v[v[j+1]]*v[v[j+2]];
		else if(v[j] == 99) break;
	}
	printf("%d\n", v[0]);
	free(v);
	return 0;
}
