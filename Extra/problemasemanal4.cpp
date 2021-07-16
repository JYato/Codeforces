#include<bits/stdc++.h>

#define N 300001
#define ll long long int

#define INF 1000000000

using namespace std;

vector<ll> trenes(N);
vector<bool> visitados(N,0);
vector<bool> istren(N);
vector<ll> dis(N);
ll n,m,k;
ll cant = 0;

struct Nodo {
    ll v, peso;
    Nodo(ll v = 0, ll peso_ = 0): v(v), peso(peso_){};
    bool operator<(const Nodo &a) const {
        return peso > a.peso;
    }
};

vector<vector<Nodo> > grafo(N);


void dijkstra(ll partida)
{
    priority_queue<Nodo> Q;
    for(ll i = 1; i <= n; i++){
        dis[i] = INF;
        if(trenes[i]){
            dis[i] = trenes[i];
            Q.push(Nodo(i,trenes[i]));
        }
    }
    dis[partida] = 0;
    Q.push(Nodo(partida,0));
    while(!Q.empty()){
        Nodo temp = Q.top();
        cout << "probe: " << temp.v << " " << temp.peso << endl;
        Q.pop();
        ll v = temp.v;
        if(visitados[v]){
            continue;
        }
        visitados[v] = true;
        for(ll i = 0; i < grafo[v].size(); i++){
            ll vecino = grafo[v][i].v;
            ll peso_vecino = grafo[v][i].peso;
            if(!visitados[vecino] && dis[v] + peso_vecino <= dis[vecino]){
                if(istren[vecino] == true) {
                    istren[vecino] = false;
                    cant++;
                }
                dis[vecino] = dis[v] + peso_vecino;
                Q.push(Nodo(vecino,dis[vecino]));
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for(ll i = 1; i <= m; i++){
        ll u,v, x; cin >> u >> v >> x;
        grafo[u].push_back(Nodo(v,x));
        grafo[v].push_back(Nodo(u,x));
    }
    for(ll i = 1; i <= k; i++){
        ll s,y; cin >> s >> y;
        if(trenes[s]){
            trenes[s] = min(trenes[s],y);
            cant++;
        }
        else{
            istren[s] = true;
            trenes[s] = y;
        }
    }
    dijkstra(1);
    cout << cant << endl;

    return 0;
}
