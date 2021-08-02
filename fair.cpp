#include <iostream>
#include <math.h>

#define ll long long int

using namespace std;

int main()
{
    int n, m, k , s; cin >> n, m, k, s;
    /*k = min(100, n);
    if(s > k) s = k;*/

    //vector<int> ciudades(n+1);
    vector<int>loq_produce(n+1);
    vector<vector<int> > adyacentes(n+1);
    for(int i = 1; i <= n; i++){
        ciudades[i] = i;
        cin >> loq_produce[i];
    }
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adyacentes[u].push_back(v);
        adyacentes[v].push_back(u);
    }

    for(int i = 1; i <= n; i++){
        vector<int> yasta;
        int costo = 0, nec = k;
        for(int j = 1; j < adyacentes[i].size(); j++){
            ///if(find(ancestros_cu[b].begin(), ancestros_cu[b].end(), ancestros_cu[a][i]) != ancestros_cu[b].end()){
            if(find(yasta.begin(), yasta.end(), loq_produce[adyacentes[i][j]) != yasta.end()){}
            else{costo++; nec--;}
        }
    }
    return 0;
}
