#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <map>
#include <array>
#include <set>
#include <unordered_set>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

using namespace std;

#define EPS 1e-14
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INFLL 1e18
#define INF 1e9

typedef long long ll;
typedef long double ld;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

typedef unordered_map<int, int> umi;
typedef unordered_set<int> usi;
typedef unordered_map<int, umi> graph;

#define RANGE(i,a,b,d) for (int i=min((int)a,(int)b); i<max((int)a,(int)b); i+=d)
#define RRANGE(i,a,b,d) for (int i=max((int)a,(int)b); i>min((int)a,(int)b); i+=d)
#define FOR(i,a,b) RANGE(i,a,b,1)
#define RFOR(i,a,b) RRANGE(i,a,b,-1)
#define REP(i,s) FOR(i,0,s)
#define RREP(i,s) RFOR(i,s-1,-1)
#define FORIT(it,l) for (auto it = l.begin(); it != l.end(); it++)
#define EACH(x,v) for (auto &x : v)

#define sz(x) (int)(x).size()
#define len(x) (int)sizeof(x)/sizeof(*x)
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define contains(m,x) m.find(x) != m.end()

#define pv(v) for(auto &x:v) cout << x << " "; cout << endl;
#define pm(m) for(auto &x:m) cout << x.F << ":" << x.S << " "; cout << endl;
#define pa(a) REP(i, len(a)) cout << a[i] << " "; cout << endl;
#define paa(aa) REP(i, len(aa)) {REP(j, len(aa[0])) cout << aa[i][j] << " "; cout << endl;}

template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
void print(T t){
    cout << t << endl;
}

template<typename T, typename... Args>
void print(T t, Args... args){
    cout << t << " ";
    print(args...);
}

int main(){
    int n,m,k,d,p;
    cin >> n >> m >> k;
    vector<vi> distance(n, vi(m, 0));
    vector<vi> pedestrian(n, vi(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // populate two grids
    FOR(i, 0, n){
        FOR(j, 0, m){
            cin >> d;
            distance[i][j] = d;
        }
    }

    FOR(i, 0, n){
        FOR(j, 0, m){
            cin >> p;
            pedestrian[i][j] = p;
        }
    }

    // greedily search for next cell with shortest distance
    // prioritize down and right
    // if two cells have the same distance, choose the one with less p
    vpi neighbours = vpi({{0, 1}, {1, 0}, {-1, 0}, {0, -1}});
    int x = 0, y = 0; // current pos
    int knocked = 0;
    ll total_d = 0;
    while( x != n-1 || y != m-1 ){
        visited[x][y] = true;

        int next_d = INF, next_x = 0, next_y = 0, next_p = 0;
        EACH(nei, neighbours){
            if( x + nei.F >= 0 && x + nei.F < n && y + nei.S >= 0 && y + nei.S < m){
                if( !visited[x + nei.F][y + nei.S] ){
                    if( distance[x + nei.F][y + nei.S] < next_d || ( distance[x + nei.F][y + nei.S] == next_d && pedestrian[x + nei.F][y + nei.S] < next_p) ){
                        next_x = x + nei.F;
                        next_y = y + nei.S;
                        next_d = distance[x + nei.F][y + nei.S];
                    }
                }

            }
        }

        total_d += next_d;
        knocked += pedestrian[next_x][next_y];

        if( knocked > k ){
            printf("-1\n" );
            return 0;
        }
        x = next_x;
        y = next_y;
    }

    printf("%lld\n", total_d);

    return 0;

}
