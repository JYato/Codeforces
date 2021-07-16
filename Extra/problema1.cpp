#include <iostream>
#include <vector>

#define ll long long int
#define N 100001

using namespace std;

ll n, m, cont;
vector<int> gatos(N);
vector<vector<int> > adj(N);

void recorrer(int dedonde, int previo, int secuencia){
    if(secuencia > m){
        return;
    }
    int llega = 1;
    for(int i = 0; i < adj[dedonde].size(); i++){
        if(adj[dedonde][i] != previo){
            llega = 0;
            int sec;
            if(gatos[adj[dedonde][i]] == 1){
                sec = secuencia + 1;
            }
            else{
                sec = 0;
            }
            recorrer(adj[dedonde][i], dedonde, sec);
        }
    }
    cont += llega;
}

int main()
{
    cin >> n >> m;
    //vector<int> gatos(n+1);
    //vector<vector<int> > adj(n+1);
    for(int i = 1; i <= n; i++){
        cin >> gatos[i];
    }
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cont = 0;
    recorrer(1, -1, gatos[1]);
    cout << cont << endl;

    return 0;
}
