// https://codeforces.com/contest/1536/problem/A
#include<bits/stdc++.h>
using namespace std;
//logic A array will be -100<=A<=100 . negative numbers will not produce the result.
//and difference will be covered under 100. 


int main(){
	//for fast input
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	//
	
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		 int flag =0;
		 int x;
		 for(int i=0; i<n;i++){
		 	cin >>x;
		 	if(x<0){
		 		flag = 1;
		 	}
		 }
		 if(flag){
		 	cout << "NO\n";
		 }
		 else{
		 	cout << "YES\n";
		 	cout << 101 << "\n"; //printing k
		 	for(int i =0; i<=100; i++)
		 	cout << i << " ";

		 }
		 cout << "\n";
	}
}




