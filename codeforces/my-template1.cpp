/*

Author       : Divyanshu Sharma

Handles      :
Leetcode     : Blackfury7
Codechef     : Blackfury
Github       : Blackfury7
Codeforces   : DivyanshuSharma19




Anime Quotes : 

Motivation   : "Yume o akiramete shinde kure" 
                - Cp. Levi

Vision       : "Sono sharingan, omae wo doko made meiteru" 
                - Itachi Uchiha

Expectations : “Wake up to reality! 
                Nothing ever goes as planned in this accursed world.” 
                - Madara Uchiha


*/



/******************************************************************************/
#include <bits/stdc++.h>
using namespace std;

#define ll        long long
#define pb        push_back
#define ull       unsigned long long
#define lld       long double
#define LETSGOBRRRR ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ff        first
#define ss        second
#define sz(v)     (ll)(v).size()
#define file      freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);freopen("Error.txt", "w", stderr);
#define MOD       1000000007      // 
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define pow2(x)              ((ll)1<<(x))
#define fix(X) fixed << setprecision(X)
#define all(x) (x).begin(), (x).end()

// typedef long long ll;
// typedef unsigned long long ull;
// typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
/******************************************************************************/


template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

/*************************************** Debug ***************************************/

#define dbg(x) cerr << #x <<" = "; _print(x); cerr << "\n";

// #ifndef ONLINE_JUDGE
// #define dbg(x) cerr << #x <<" "; _print(x); cerr << "\n";
// #else
// #define dbg(x)
// #endif


void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*************************************** Debug ***************************************/


/***********************************MAIN***************************************/
// Are you ready to face the wrath of test cases? Good luck noob fury!
// Kindly don't copy my template as it may lead to plagiarism


void solve()
{
   ll n; cin>>n;
//   vector<ll>v(n);
//   for(auto &i : v) cin>>i;
   
}

int main()
{
    LETSGOBRRRR
    #ifndef ONLINE_JUDGE
    	file
    #endif
    
    int t = 1;
    cin >> t;
   for(int i = 1; i <= t; i++)
    {   
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}