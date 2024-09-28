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
    std::cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

bool cmp(pii a, pii b) {
    if(a.ss == b.ss) return a.ff < b.ff;
    return a.ss < b.ss;    
}

void solve()
{
    int n = 0, b = 0, k = 0, l = 0, r = 0, h = 0, cnt = 0, ans = 0, sum = 0, mn = INF, mx = -INF;
    cin >> n >> k;

    map<int, int> mp1, mp2;
    vector<int> ans1, ans2;

    for(int i = 0; i < 2*n; i++) {
        int x;
        cin >> x;
        if(i < n) {
            mp1[x]++;
        } else {
            mp2[x]++;
        }
    }

    int m = 2*k;
    for(auto [x, y] : mp1) {
        if(m == 0) {
            break;
        }
        if(y == 1) {
            ans1.pb(x);
            ans2.pb(x);
            m--;
        }
    }

    int i = 0;

    if(m > 0) {
        if(sz(ans1) & 1) {
            i = 1;
            m++;
        }
        int j = m;

        for(auto [x, y] : mp1) {
            if(m == 0) {
                break;
            }
            if(y == 2) {
                ans1.pb(x);
                ans1.pb(x);
                m -= 2;
            }
        }

        for(auto [x, y] : mp2) {
            if(j == 0) {
                break;
            }
            if(y == 2) {
                ans2.pb(x);
                ans2.pb(x);
                j -= 2;
            }
        }
    }

    for(int x = i; x < sz(ans1); x++) {
        cout << ans1[x] << " ";
    }
    cout << endl;

    for(int x = i; x < sz(ans2); x++) {
        cout << ans2[x] << " ";
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