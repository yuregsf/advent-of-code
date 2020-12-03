#include <bits/stdc++.h>
using namespace std;

int main(){
	int min, max, count=0, actual=0;
	char x,a;

	while(scanf("%d-%d %c: ", &min,&max,&x) != EOF){
		cout << min << " " <<  max << " " << x << endl;
		actual = 0;
		while(scanf("%c", &a) && a != '\n'){
			cout << a << " ";
			if(a == x) actual++;
		}
		cout << endl;
		if(actual >= min && actual <= max) count++;
	}
	cout << count;

}
