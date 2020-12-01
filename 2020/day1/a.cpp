#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	vector<int> entries;
	while(scanf("%d", &n) != EOF){
		entries.push_back(n);
		cout << n << endl;
	}
	for(int i = 0; i < entries.size()-1; ++i){
		for(int j = i+1; j < entries.size(); ++j){
			if(entries[i]+entries[j] == 2020){
				cout << entries[i]*entries[j];
			}
		}
	}
}
