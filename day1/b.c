#include <stdio.h>

long long int fuel(long long int mass){
	long long int mFuel = mass/3-2;
	if(mFuel <= 0) return 0;
	return (mFuel) + fuel(mFuel);
}

int main(){
	long long int mass, sum = 0;

	while(scanf("%lld", &mass) != EOF){
		sum += fuel(mass);
	}
	printf("%lld\n", sum);
	return 0;
}
