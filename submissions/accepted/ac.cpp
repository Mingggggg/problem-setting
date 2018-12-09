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

const ll INF = (int)1e18;
const int mod = 1000000007;
#define MAXN 101
#define MAXS 1001


ll D[MAXN][MAXN], W[MAXN][MAXN];
ll dp[MAXN][MAXN][MAXS];
int n, m, K;
ll ans = INF;
int directions[2][4] = {
    {-1, 1, 0, 0},
    {0, 0, -1, 1}
};

ll minDist(int r, int c, int k) {
    if (k < 0) return INF;
    if (r == 0 && c == 0) return 0;
    if (r < 0 || c < 0 || r >= n || c >= m) return INF;
    if (dp[r][c][k] != -1) return dp[r][c][k];
    dp[r][c][k] = INF;
    for (int i=0; i < 4; i++) {
        dp[r][c][k] = min(dp[r][c][k], D[r][c] + 
            minDist(r+directions[0][i], c+directions[1][i], k-W[r][c]));
    }
    return dp[r][c][k];
}

int main() {
    cin >> n >> m >> K;
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
    REP(i, 0, n) {
        REP(j, 0, m) {
            REP(k, 0, K+1) {
                dp[i][j][k] = -1;
            }
        }
    }
    ll ans = minDist(n-1, m-1, K);
    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}