// author: bhupati_12

#pragma GCC optimize "trapv"
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
// #include "debug_error.hpp"
#else
#define print(...)
#define debug(...)
#endif

#define int long long int
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define pob pop_back
#define mk make_pair
#define sz(x) (int)x.size()
#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define set_bits __builtin_popcountll
#define INF (int)1e18
#define mod 1000000007
#define set_pre(x, y) fixed << setprecision(y) << x
#define w(t)  \
    int t;    \
    cin >> t; \
    while (t--)

// less----less_equal---greater---greater_equal
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key(k)--->returns count of elements strictly smaller than k;
// find_by_order(k)--->returns iterator to kth element starting from 0;
// to use a set as a multiset, use pii instead of int or update the 3rd parameter to use it as multiset, reverse_set etc

template <typename T>
T gcd(T a, T b)
{
    if (b > a)
    {
        return gcd(b, a);
    }
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

template <typename T>
T ceil(T a, T b) { return (a + b - 1) / b; }

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

void solve()
{
    int n = 0, m = 0, k = 0, l = 0, r = 0, h = 0, ans = 0, cnt = 1, sum = 0, mn = INF, mx = -INF;
    cin >> n >> m >> k;

    vector<pair<int, string>> p(m);

    for(int i = 0; i < m; i++) {
        cin >> p[i].ff >> p[i].ss;
    }

    vector<int> visited(n+1, -1);
    vector<int> curr;

    visited[k] = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= n; j++) {
            if(visited[j] == (cnt-1)) {
                int node;
                if(p[i].ss == "0") {
                    node = (j + p[i].ff) % n;
                    node = node == 0 ? n : node;
                    curr.pb(node);
                } else if(p[i].ss == "1") {
                    node = (j + (n -  p[i].ff)) % n;
                    node = node == 0 ? n : node;
                    curr.pb(node);
                } else {
                    node = (j + p[i].ff) % n;
                    node = node == 0 ? n : node;
                    curr.pb(node);

                    node = (j + (n -  p[i].ff)) % n;
                    node = node == 0 ? n : node;
                    curr.pb(node);
                }
            }
        }

        for(auto x: curr) {
            visited[x] = cnt;
        }
        curr.resize(0);
        cnt++;
    } 

    for(int i = 1; i <= n; i++) {
        if(visited[i] == (cnt - 1)) {
            ans++;
        }
    }

    cout << ans << endl;
    for(int i = 1; i <= n; i++) {
        if(visited[i] == (cnt - 1)) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int32_t main()
{
    clock_t begin = clock();
    init();
    // Write your code here....
    w(t)
        solve();

    // code end.....

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}