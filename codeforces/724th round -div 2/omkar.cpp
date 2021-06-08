#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

bool f(int x, int y){
	return x>y;


}

void set_demo();

int main(){
	int i,t,n,flag;
vector<int> a[205];

	
	cin >> t;
	while(t--){
		cin << n;
		flag = 0;
		for(i=0;i<n;i++){
			cin << a[i];
			if(a[i] < 0)
				flag = 1;

		}
		if(flag != 1)
	set_demo(a,n);
	else 
		cout << "NO\n";

	}

	






return 0;
}



void set_demo(vector a, int n){

	set<long long> b;
	s.insert(1);
	

	for(i=0;i<n;i++){
		for(j=i+1;j<n;j<n){
			diff = abs(a[j]-a[i])
			auto it = 
		}
	}

	for(int x:s){
		cout << x << " ";
	}
	cout << endl;

	//-10 -1 1 2

	auto it = s.find(-1);
	cout << it<<endl;
	if(it == s.end()){
		cout << "not present\n";

	}
	else
	{
		cout << " present \n" << *it<< endl;
	}

	auto it2 = s.upper_bound(-1);
	auto it3 = s.upper_bound(0);

	cout << *it2 << *its << endl;

	auto it4 = s.upper_bound(23);

	s.erase(2);

	if ( it4 == s.end()){
		cout << "not found anything \n";
	}

}