#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	vector<int> entries;
	while(scanf("%d", &n) != EOF){
		entries.push_back(n);
	}
	sort(entries.begin(), entries.end());
	for(int i = 0; i < entries.size()-2; ++i){
		for(int j = i+1; j < entries.size()-1; ++j){
			for(int k = j+1; k < entries.size(); ++k){
				if(entries[i]+entries[j]+entries[k] == 2020){
					cout << entries[i]*entries[j]*entries[k];
				}
			}
		}
	}
}
