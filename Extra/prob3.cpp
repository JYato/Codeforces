#include <bits/stdc++.h>

#define ll long long int
#define N 1001

using namespace std;

ll n,m,k;
vector<ll> movx = {0,0,-1,1};
vector<ll> movy = {-1,1,0,0};
vector<string> cadenas(N);///de * y .
vector<vector<bool> > visitados(N,vector<bool>(N));///matriz
vector<vector<ll> > cantidades(N,vector<ll>(N));///matriz
vector<pair<ll,ll> > vecinos;///temporal

ll contador = 0;

void recorrer(ll x, ll y)
{
    visitados[x][y] = true;
    vecinos.push_back(make_pair(x,y));
    for(int i = 0; i < 4; i++){
        int x1 = x + movx[i];
        int y1 = y + movy[i];
        if(cadenas[x1][y1-1] == '*'){
            contador++;
        }
        else if(!visitados[x1][y1]){
            recorrer(x1,y1);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++){
        cin >> cadenas[i];
    }
    for(ll x = 1; x <= n; x++){
        for(ll y = 1; y <= m; y++){
            if(cadenas[x][y-1] == '.' && !visitados[x][y]){
                vecinos.clear();
                contador = 0;
                recorrer(x,y);
                for(ll h = 0; h < vecinos.size(); h++){
                    cantidades[vecinos[h].first][vecinos[h].second] = contador;
                }
            }
        }
    }
    for(ll i = 0; i < k; i++){
        ll x,y; cin >> x >> y;
        cout << cantidades[x][y] << endl;
    }

    return 0;
}
