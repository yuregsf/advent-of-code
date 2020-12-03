#include <bits/stdc++.h>
using namespace std;

int main(){
	int min, max, count=0, i=0, flag=0;
	char x,a;

	while(scanf("%d-%d %c: ", &min,&max,&x) != EOF){
		i = 1;
		flag = 0;
		while(scanf("%c", &a) && a != '\n'){
			if(a == x && (i == min || (i == max && flag == 0))) flag++;
			else if(a == x && i == max && flag == 1) flag = 0;
			++i;
		}
		if(flag == 1) count++;
	}
	cout << count;

}
