#include <stdio.h>

int main(){
	int sum = 0;
	int input;
	while(scanf("%d", &input) != EOF){
		sum += input/3-2;
	}
	printf("%d\n", sum);
	return 0;
}
