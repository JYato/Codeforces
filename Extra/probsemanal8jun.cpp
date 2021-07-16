#include <bits/stdc++.h>

#define ll long long int

using namespace std;

vector<int> visitados(26,0);
vector<int> usados(26,0);
vector<vector<int> > arr(26,vector<int>(26,0));

void dfs(int v){
    visitados[v] = 1;
    for(int i = 0; i < 26; i++){
        if(arr[v][i] == 1 && visitados[i] == 0){
            dfs(i);
        }
    }
}

int main()
{
    int n; cin >> n;
    int cant = 0;
    for(int i = 0; i < n; i++){
        string temp; cin >> temp;
        vector<int> aristas;
        for(int j = 0; j < temp.size(); j++){
            aristas.push_back(temp[j]-'a');
        }
        for(int j = 0; j < aristas.size(); j++){
            int u = aristas[j];
            usados[u] = 1;
            for(int h = j+1; h < aristas.size(); h++){
                int v = aristas[h];
                arr[u][v] = 1;
                arr[v][u] = 1;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(visitados[i] == 0 && usados[i] == 1){
            cant++;
            dfs(i);
        }
    }
    cout << cant << endl;

    return 0;
}


/*int main()
{
    int t;
    cin >> t;
    if(t%2 == 0)
        cout << "white" << endl << "1" << ' ' << 2;
    else
        cout << "black";

    return 0;
}
*/
