#include <bits/stdc++.h>

// #include<assert.h>
// #include<unordered_map>
// #pragma GCC optimize ("-03")

using namespace std;

// #define watch(x) cout << (#x) << " = " << (x)
// #define PI double(2 * acos(0.0))
// #define LL long long
// #define MOD 1000000007
// #define all(x) (x).begin(), (x).end()
// #define INF 1e15

int main()
{
	//for fast input/output
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int array[n];
		for(int i = 0; i < n; i++){
			cin >> array[i];
		}
		int flag = 0;
		set <int> s;
		s.insert(array[0]);
		for(int i =1; i < n; i++){
			s.insert(array[i]);
			auto it1 = s.find(min(array[i],array[i-1]));
			auto it2 = s.find(max(array[i],array[i-1]));
			if(it1 == it2){
				continue;
			}
			it1++;
			if(it1 == it2){
				continue;
			}
			flag =1;
			break;
		}
		if(flag){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";

		}
		

	}



    return 0;

}
