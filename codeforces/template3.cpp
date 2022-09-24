/*---------------------------------------------#---ARA_ARA----#-----------------------------------------------*/
/*
    author:  ARA_ARA
*/
#include "bits/stdc++.h"
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>


#define foru(i , a , b)            for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define ford(i , a , b)            for(ll i = (ll)(a) ; i >= (ll)(b) ; i--)
#define REP(i, a, n)               for(int i = (int)(a) ; i < (int)n ; i++)
#define REQ(i, a, n)               for(int i = (int)(a) ; i >= (int)n ; i--)
#define M                          1000000007ll
#define mp                         make_pair
#define mt                         make_tuple
#define cend                       cout << "\n"
#define all(x)                     x.begin() , x.end()
#define ff                         first
#define ss                         second
#define sz(a)                      ((long long)(a).size())
#define mset(a , b)                memset(a , b , sizeof(a))
#define pb                         push_back
#define endn                       '\n'
#ifdef ARA_ARA
#define dbg(a) cerr << #a << ": "; _print(a); cerr << endl;
#else
#define dbg(a) // No more TLEs
#endif

using namespace std;
using namespace std::chrono;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <char> vch;
typedef vector <string> vs;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef pair <ll , ll> pll;
typedef vector <pair <ll , ll>> vpll;
typedef vector <pair <int, int>> vpi;
//typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())


void rotate(vi arr, int n){int x = arr[n - 1], i;for (i = n - 1; i > 0; i--)arr[i] = arr[i - 1];arr[0] = x;}
void showlist(list <int> g){list <int> :: iterator it;for(it = g.begin(); it != g.end(); it++)cout<< *it<<" ";cend;}
bool compare_function( string& s1 , string& s2 ){return ( s1.length() > s2.length() );}
void showvec(vector <int> v){vector<int>::iterator it;for(it = v.begin(); it != v.end(); it++) {cout << *it <<" ";}}
void showset(set <int> s){set<int>::iterator it;for(it = s.begin(); it != s.end(); it++) {cout << *it <<" ";}}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
bool isPrime(int n){for (int i = 2; i <= n/2; i++){if (n % i == 0)return false;}return true;}
int findNextPrime(int n){int nextPrime = n;bool found = false;while (!found){nextPrime++;if (isPrime(nextPrime))found = true;}return nextPrime;}
int largest(int arr[], int n){return *max_element(arr, arr+n);}
bool isPerfectSquare(long double x){if (x >= 0) {long long sr = sqrt(x);return (sr * sr == x);}return false;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}



/*----------------------------- # --- MATH ALGORITHMS --- # -----------------------------*/

template <class T> T gcd(T a , T b){ while(a != 0){T temp = a; a = b % a; b = temp;}return b;}
template <class T> T egcd(T a , T b , T &x , T &y){T gcd , xt , yt;if(a == 0){gcd = b;x = 0 , y = 1;}else {gcd = egcd(b % a , a , xt , yt);x = yt - (b/a)*xt; y = xt;}return gcd;}
template <class T> T expo(T base , T exp , T mod){T res = 1;base = base % mod;while (exp > 0){if (exp & 1)res = (res*base) % mod;exp = exp>>1;base = (base*base) % mod;}return res;}
template <class T> T modinv(T a , T mod){T x , y; egcd<T>(a , mod , x , y);while(x < 0) x += mod; while(x >= mod) x -= mod; return x;}
template <class T> T modinvfermat(T a , T mod){return expo<T>(a , mod - 2 , mod);}
template <class T> bool rev(T a , T b){return a > b;}
template <class T> ll maxpower(T a , T b){ll ans = 0;while(a > 0 && a % b == 0){ans++;a /= b;}return ans;}
template <class T> T mceil(T a, T b){if(a % b == 0) return a/b; else return a/b + 1;}
template <class T> T lcm(T a, T b){return (a*b)/gcd<T>(a, b);}
const ll infl = 1e18; const int inf = 1e9 + 5;
int power(int x, int y) 
{ 
    int res = 1; 
    x = x;  
    while (y > 0) 
    { 
        if (y%2!=0) 
            res = (res * x); 
  
        y=y/2;
        x = (x * x); 
    } 
    return res; 
}

/*---------------------------------------------------------------------------------*/
//01 KnapSack
int subsetsum(vll &v, ll n, ll sum){
       int dp[n + 1][sum + 1];
       dp[0][0] = 1;
       foru(i, 1, n + 1){
              dp[i][0] = 1;
       }
       foru(i, 1, sum + 1){
              dp[0][i] = 0;
       }
       foru(i, 1, n + 1){
              foru(j, 1, sum + 1){
                     if(v[i - 1] > j){
                            dp[i][j] = dp[i - 1][j];
                     }
                     else {
                            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i - 1]];
                     }
              }
       }
       return dp[n][sum];
}
const int N = 1e5+10;
bool vis[N];
vector<int> g[N];

void dfs(int vertex){
       // Take action on vertex after entering the vertex
       vis[vertex] = true;
       for(int child : g[vertex]){
              // Take action on child before entering the child node
              if(vis[child]) continue;
              dfs(child);
              // Take action on child after exiting the child node
       }
       // Take action on vertex before exiting the vertex
}

void bfs(int s, vi adj[], bool vis[], int N){
       queue<int> q;
       q.push(s);
       vis[s] = true;
       while(!q.empty()){
              int curr = q.front();
              q.pop();
              cout << curr << " ";
              REP(i, 0, adj[curr].size()){
                     if(vis[adj[curr][i]] == false){
                            q.push(adj[curr][i]);
                            vis[adj[curr][i]] == true;
                     }
              }
       }
}

int mincoin(vll &v, int n, int sum){
       int dp[n + 1][sum + 1];
       foru(i, 0, n + 1){
              foru(j, 0, sum + 1){
                     if(j == 0){
                            dp[i][j] = 0;
                     }
                     else if(i == 0){
                            dp[i][j] = INT_MAX - 1;
                     }
                     else if(v[i - 1] <= j){
                            dp[i][j] = min(1 + dp[i][j - v[i - 1]], dp[i - 1][j]);
                     }
                     else {
                            dp[i][j] = dp[i - 1][j];
                     }
              }
       }
       return dp[n][sum] > INT_MAX - 1 ? -1 : dp[n][sum];
}
struct node{
       int parent;
       int rank;
};
vector<node> dsuf;

// int find_op(int v){
//        if(dsuf[v].parent == 1)
//               return v;
//        return dsuf[v].parent = find(dsuf[v].parent); //Path Compression
// }

void union_op(int fromP,int toP)
{
       //fromP = find(fromP);
       //toP = find(toP);

       //UNION by RANK
       if(dsuf[fromP].rank > dsuf[toP].rank)     //fromP has higher rank
              dsuf[toP].parent = fromP;
       else if(dsuf[fromP].rank < dsuf[toP].rank)       //toP has higher rank
              dsuf[fromP].parent = toP;
       else
       {
              //Both have same rank and so anyone can be made as parent
              dsuf[fromP].parent = toP;
              dsuf[toP].rank +=1;         //Increase rank of parent
       }
}
/*-----------------------------------------------------------------------------------*/

/*------------------------------------fn---------------------------------------------*/



/*------------------------------ # --- MAIN CODE --- # ------------------------------*/
//Practice->Success

class solver{
       public:
       void solve(){
              int n, k;
              cin >> n >> k;
             
       }

};

/*-------------------------------# ---DRIVER CODE----#-------------------------------*/

int main() {
       ios_base::sync_with_stdio(false); 
       cin.tie(NULL); cout.tie(NULL);
#ifdef ARA_ARA
       FILE* inp = freopen("input.txt", "r", stdin);
       FILE* out = freopen("output.txt", "w", stdout);
#endif
       auto start = high_resolution_clock::now();
       cout << setprecision(15);
       int tc = 1;
       cin >> tc;
       for (int t = 1; t <= tc; t++) {
       // cout << "Case #" << t  << ": ";
       solver o; 
       o.solve();
       }
       auto stop = high_resolution_clock::now();
       auto duration = duration_cast<microseconds>(stop - start);
       cerr << "Time: " << duration.count()/1000.0 << endl;
#ifdef ARA_ARA
       cerr << "Time: " << duration.count()/1000.0 << endl;
#endif
       return 0;
}
