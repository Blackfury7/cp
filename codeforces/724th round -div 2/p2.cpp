//find the Mix problem
// https://codeforces.com/contest/1536/problem/B


#include<bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//making string array of all cases to check the inputs
	string one[26], two[26*26];
	for(int i =0; i < 26; i++){
		one[i] = char('a'+i);
		for(int j = 0; j< 26; j++){
			two[26*i + j] = one[i] + char('a'+j);

		}
	}
//
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string s;
		cin >> s;
		map<string, int> m;

		for(int i =0; i< n; i++){
			m[s.substr(i, 1)] = 1;

		}
		for(int i=0; i< n-1; i++){
			m[s.substr(i,2)] = 1;
		}
		string ans = "";
		for(int i=0; i < 26; i++){
			if(m[one[i]] == 0){
				ans = one[i];
				break;
			}
		}
		if(ans == ""){
			for(int i =0; i< 26*26; i++){
				if(m[two[i]] == 0){
					ans = two[i];
					break;
				}
			}
		} 
		cout << ans <<"\n"; 

	}
	return 0;

}