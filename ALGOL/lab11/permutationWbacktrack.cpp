#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vb vector<bool>
#define vpii vector<pii>
#define vpll vector<pll>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define sc set<char>
#define usi unordered_set<int>

#define f(i, s, e) for (ll i = s; i < e; ++i)
#define rf(i, e, s) for (ll i = e - 1; i >= s; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define MOD 1000000007
#define PI 3.1415926535897932384626433832795

// Compute GCD of a and b using the Euclidean algorithm
inline ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
// Compute LCM of a and b using GCD
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
// Check if n is a prime number
inline bool prime(ll n) {
    if (n < 2) return false;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}
// Modular addition, handles negative results
inline ll mod_add(ll a, ll b, ll m = MOD) { return (a % m + b % m) % m; }
// Modular subtraction, ensures non-negative results
inline ll mod_sub(ll a, ll b, ll m = MOD) { return (a % m - b % m + m) % m; }
// Modular multiplication, avoids overflow
inline ll mod_mul(ll a, ll b, ll m = MOD) { return (a % m * b % m) % m; }
// Modular exponentiation using binary exponentiation
inline ll mod_pow(ll base, ll exp, ll m = MOD) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2) res = mod_mul(res, base, m);
        base = mod_mul(base, base, m);
        exp /= 2;
    }
    return res;
}

void fast_io() { ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); }

#ifdef DEBUG
#define debug(x) cerr << #x << " = " << x << endl;
template<typename T>
void debug_vector(const vector<T>& v) {
    cerr << "[ "; for (const T& i : v) cerr << i << " "; cerr << "]\n";
}
template<typename T, typename U>
void debug_pair(const pair<T, U>& p) {
    cerr << "(" << p.first << ", " << p.second << ")\n";
}
template<typename T>
void debug_set(const set<T>& s) {
    cerr << "{ "; for (const T& i : s) cerr << i << " "; cerr << "}\n";
}
template<typename T, typename U>
void debug_map(const map<T, U>& m) {
    cerr << "{ "; for (const auto& p : m) cerr << "(" << p.first << ": " << p.second << ") "; cerr << "}\n";
}
#else
#define debug(x)
#define debug_vector(v)
#define debug_pair(p)
#define debug_set(s)
#define debug_map(m)
#endif


set<string> st;
void permute(string& a, int l, int r) 
{ 
	// Base case 
	if (l == r){
        st.insert(a);
    }
		 
	else { 
		// Permutations made 
		for (int i = l; i <= r; i++) { 

			// Swapping done 
			swap(a[l], a[i]); 

			// Recursion called 
            permute(a, l + 1, r); 

			// backtrack 
			swap(a[l], a[i]); 
		} 
	} 
} 
void solve() {
    string str = ""; 
    cin >> str;
	int n = str.size(); 

	// Function call 
	permute(str, 0, n - 1); 
    for(auto x: st){
        cout << x << endl;
    }
}

int main() {
    fast_io();
    solve();
    return 0;
}
