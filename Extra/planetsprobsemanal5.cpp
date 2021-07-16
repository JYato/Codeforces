#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <utility>
#include <algorithm>

#define ll long long int
#define N 100001
#define INF 1000000000

using namespace std;

vector<vector<pair<ll,ll> > > adj(N);
vector<vector<ll> > times(N);
vector<ll> distancia(N,INT_MAX);

struct Compare{
    bool operator()(const pair<ll, ll> &t1, const pair<ll, ll> &t2) const{
        return t1.second > t2.second;
    }
};

int main()
{
    ll n, m; cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll u, v, w; cin >> u >> v >> w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    for(ll i = 1; i <= n; i++){//n veces
        ll k; cin >> k;
        while(k--){
            ll t; cin >> t;
            times[i].push_back(t);
        }
    }//check
    priority_queue<pair<ll, ll>, vector<pair<ll,ll> >, Compare> Q;//partida,peso
    distancia[1] = 0;
    ll timef = 0;//tiempo inicial de luke
    while(binary_search(times[1].begin(), times[1].end(), timef)){
        timef++;
    }
    Q.push(make_pair(1,timef));
    while(!Q.empty()){
        ll u = Q.top().first;
        ll tiempo = Q.top().second;
        //cout << "verificacion: " << u << " " << tiempo << endl;
        Q.pop();
        for(ll i = 0; i < adj[u].size(); i++){
            ll v = adj[u][i].first;
            ll nt = adj[u][i].second;
            if(tiempo + nt < distancia[v]){
                distancia[v] = tiempo + nt;
                ll ntime = distancia[v];
                while(binary_search(times[v].begin(), times[v].end(), ntime)){
                    ntime++;
                }
                Q.push(make_pair(v, ntime));
            }
        }
    }
    if(distancia[n] == INT_MAX){
        distancia[n] = -1;
    }
    cout << distancia[n] << endl;

    return 0;
}
