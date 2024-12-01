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

int C[15][15];

void pre_build() {
    for (int n = 0; n < 15; n++) { // loop over n from 0 to N-1 (inclusive)
        C[n][0] = 1;
        C[n][n] = 1;
        for (int k = 1; k < n; k++) // loop over k from 1 to n-1 (inclusive)
            C[n][k] = ((C[n][k - 1] % mod) + (C[n - 1][k - 1] % mod)) % mod; 
    }
}

int power(long long x, unsigned int y, int p) 
{ 
    int res = 1;     // Initialize result 
 
    x = x % p; // Update x if it is more than or 
                // equal to p
  
    if (x == 0) return 0; // In case x is divisible by p;
 
    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 
 
        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 

void solve()
{
    int t = 0, q = 0, m = 0, l = 0, r = 0, h = 0, cnt = 0, sum = 0, mn = INF, mx = -INF, ans = 0;

    cin >> t;
    vector<int> n(t), k(t);

    for(int i = 0; i < t; i++) {
        cin >> n[i];
    }

    for(int i = 0; i < t; i++) {
        cin >> k[i];
    }

    for(int i = 0; i < t; i++) {
        if(k[i] > n[i]) {
            cout << 0 << endl;
        } 
        else if(k[i] == n[i]) {
            cout << 1 << endl;
        }else {
            cout << power(2LL, k[i], mod) << endl;
        }
    }

}

int32_t main()
{
    clock_t begin = clock();
    init();
    // Write your code here....
    solve();

    // code end.....

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    std::cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}