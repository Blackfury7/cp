#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pr;

ll mridul = LLONG_MAX;
ll mod = 1e9 + 7;

vector<ll> adj[200001];
vector<ll> prime;
vector<ll> vis(200001, 0);
// vector<ll> rnk(200001);
// vector<ll> parent(200001);
// vector<ll> score(100001, 1);
// vector<ll> ind(200001);
// vector<ll> dp(4 * 1e4 + 1, 0);
// vector<ll> sd(5000001, 1);
// vector<ll> pf(5000001, 0);
// vector<ll> temp(5000001, 0);

bool comp2(const pr &v1, const pr &v2)
{
    // if (v1.second != v2.second)
    //     return v1.second > v2.second;
    if (v1.first != v2.first)
        return v1.first < v2.first;
    return v1.second < v2.second;
}

bool comp1(const pair<string, ll> &v1, const pair<string, ll> &v2)
{
    if (v1.first != v2.first)
        return v1.first < v2.first;
    return v1.second < v2.second;
}

struct comp3
{
    bool operator()(pair<ll, ll> &a, pair<ll, ll> &b)
    {

        return (a.second > b.second);
        // return a.first < b.first;
    }
};

ll abs(ll a, ll b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

bool _prime(ll n)
{
    bool tell2 = false;
    for (ll j = 2; j * j <= n; j++)
    {
        if (n % j == 0)
        {
            return false;
        }
    }
    return true;
}

// void sieve()
// {

//     bool vis[5000001];

//     memset(vis, true, sizeof(vis));

//     for (ll p = 2; p * p <= 5000000; p++)
//     {
//         if (vis[p] == true)
//         {
//             sd[p] = p;
//             for (ll i = p * p; i <= 5000000; i += p)
//             {
//                 vis[i] = false;
//                 sd[i] = p;
//             }
//         }
//     }

//     // for (ll p = 2; p <= 200000; p++)
//     //     if (vis[p])
//     //         prime.push_back(p);
// }

// void build(vector<ll> &b, vector<ll> &a, ll curr, ll low, ll high)
// {
//     if (low == high)
//     {
//         b[curr] = a[low];
//         return;
//     }
//     ll mid = (low + high) / 2;
//     build(b, a, curr * 2, low, mid);
//     build(b, a, curr * 2 + 1, mid + 1, high);
//     b[curr] = min(b[curr * 2], b[curr * 2 + 1]);
// }

// ll min_query(vector<ll> &b, ll curr, ll l, ll h, ll low, ll high)
// {
//     if (l > h)
//     {
//         return INT_MAX;
//     }
//     if (l == low && h == high)
//     {
//         return b[curr];
//     }
//     ll mid = (low + high) / 2;
//     return min(min_query(b, curr * 2, l, min(h, mid), low, mid), min_query(b, curr * 2 + 1, max(mid + 1, l), h, mid + 1, high));
// }

// void update(vector<ll> &b, ll curr, ll pos, ll val, ll low, ll high)
// {
//     if (low == high)
//     {
//         b[curr] = val;
//         return;
//     }
//     ll mid = (low + high) / 2;
//     if (pos > mid)
//         update(b, curr * 2 + 1, pos, val, mid + 1, high);
//     else
//         update(b, curr * 2, pos, val, low, mid);
//     b[curr] = min(b[curr * 2], b[curr * 2 + 1]);
// }

void bfs(vector<vector<ll>> &adj, vector<ll> &vis, vector<ll> &lvl, vector<ll> &dis, ll curr)
{
    queue<ll> nod;
    nod.push(curr);
    vis[curr] = 1;
    lvl[curr]++;
    dis[curr] = 1;
    while (!nod.empty())
    {
        ll cur = nod.front();
        nod.pop();
        for (auto x : adj[cur])
        {
            if (!vis[x])
            {
                nod.push(x);
                vis[x] = 1;
                dis[x] = dis[cur] + 1;
                lvl[dis[x]]++;
            }
        }
    }
}

void dfs1(vector<vector<ll>> &adj, vector<ll> &vis, vector<ll> &dp, ll curr, ll par)
{
    vis[curr] = 1;
    for (auto x : adj[curr])
    {
        if (!vis[x])
        {
            dfs1(adj, vis, dp, x, curr);
        }
        ll m = dp[x];
        if (curr < x)
            m++;
        dp[curr] = max(dp[curr], m);
    }
}

void dfs2(vector<vector<ll>> &adj, vector<ll> &col, vector<ll> &vis, vector<ll> &dp, vector<ll> &par, ll curr, ll p)
{
    //  cout<<"\n"<<n<<"\n";
    vis[curr] = 1;
    par[curr] = p;
    if (col[curr] == 1)
        dp[curr] = 1;
    else
        dp[curr] = -1;
    for (auto x : adj[curr])
    {
        if (!vis[x])
        {
            dfs2(adj, col, vis, dp, par, x, curr);
            if (dp[x] > 0)
                dp[curr] += dp[x];
        }
    }
}

ll cr7(ll x)
{
    ll r = 0;
    while (x)
    {
        x = x / 10;
        r++;
    }
    return r;
}

bool using_dfs(vector<vector<ll>> &adj, vector<ll> &color, vector<ll> &parent, ll current, ll par)
{
    color[current] = 1; // node in current dfs call
    for (int x : adj[current])
    {
        if (color[x] == 1) // cycle found
        {
            return true;
        }
        else if (color[x] == 0) // unvisited node
        {
            parent[x] = current;
            if (using_dfs(adj, color, parent, x, parent[x]))
                return true;
        }
        // no need to check 3rd condition, since node is already visited and there is no cyle through vit
    }
    color[current] = 2; // all neighours visited, no cycle through it
    return false;
}

bool sortcol(const vector<ll> &v1, const vector<ll> &v2)
{
    if (v1[2] != v2[2])
        return v1[2] > v2[2];
    return v1[1] < v2[1];
}

void solve(int cas)
{
    ll n = 0, mod = 1e9 + 7, x = 0, u, v, y = 0, z = 0, d1 = 0, d2 = 0, d3 = 0, d4, l, h, r = 0, ans = 0, m = 0, k = 0, j = 0, q = 0, i = 0, sum = 0, p = 0;

}

int main()
{
    //  #ifndef ONLINE_JUDGE
    // fropen("input.txt","r",stdin);
    // fropen("output.txt","w",stdout);
    // #endif
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll t = 1;
    // sieve();
    // pf[1] = 0;
    // for (int i = 2; i <= 5000000; i++)
    // {
    //     pf[i] = pf[i / sd[i]] + 1;
    //     temp[i] = temp[i - 1] + pf[i];
    // }
    cin >> t;
    int m = 1;
    while (t--)
    {
        solve(m);
        m++;
    }
}
