#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <ctime>
#include <cassert>
#include <functional>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))
#define fst first
#define snd second

const int INF = (int)1e9;
const ll INFLL = 1e18;
const int mod = 1000000007;
#define MAXN 101


int D[MAXN][MAXN], W[MAXN][MAXN];
bool visited[MAXN][MAXN];
int n, m, k;
ll ans = INFLL;
void completeSearch(int i, int j, ll d, int w) {
    if (visited[i][j] || w > k) return;
    if (i == n - 1 && j == m - 1) {
        ans = min(ans, d); 
        return;
    }
    visited[i][j] = true;
    if (i < n - 1) completeSearch(i+1, j, d+D[i+1][j], w+W[i+1][j]);
    if (j < m - 1) completeSearch(i, j+1, d+D[i][j+1], w+W[i][j+1]);
    if (i > 0) completeSearch(i-1, j, d+D[i-1][j], w+W[i-1][j]);
    if (j > 0) completeSearch(i, j-1, d+D[i][j-1], w+W[i][j-1]);
    visited[i][j] = false;
}

int main() {
    cin >> n >> m >> k;
    REP(i, 0, n) {
        REP(j, 0, m) {
            cin >> D[i][j];
        }
    }
    REP(i, 0, n) {
        REP(j, 0, m) {
            cin >> W[i][j];
        }
    }
    completeSearch(0, 0, (ll) D[0][0], 0);
    if (ans == INFLL) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}