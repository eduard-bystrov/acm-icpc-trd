#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:268435456")
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <sstream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <random>
#include <chrono>

using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define sqr(cd) ((cd) * (cd))

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd
#define have adsgagshdshfhds
#define ends asdgahhfdsfshdshfd

template <typename T> void alert(const T& t) { cout << t << endl; exit(0); }
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using max_heap = priority_queue<T, vector<T>, less<T>>;

typedef long long int64;
typedef unsigned long long uint64;
typedef long double ld;
typedef array<uint64, 2> hv;

// region rnd
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rnd(a, b) (uniform_int_distribution<int>((a), (b))(rng))
// endregion rnd

// region time
#include <time.h>
clock_t __clock__;
void startTime() {__clock__ = clock();}
void timeit(string msg) {cerr << "> " << msg << ": " << precise(6) << ld(clock()-__clock__)/CLOCKS_PER_SEC << endl;}
// endregion time
const double PI = acos(-1);

signed main()
{
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif // _DEBUG
 
	//srand(NULL);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// cout.precision(15);
	// cin >> hex >> n;

	return 0;
}