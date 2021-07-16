#include <bits/stdc++.h>

using namespace std;

int main()
{
    int  n, m; cin >> n >> m;
    vector<int> as;
    vector<int> f(n+1,0);
    vector<int> b(m);
    for(int i = 0; i < n; i++){
        int temp; cin >> temp;
        if(f[temp] == 0){
            f[temp] = i+1;
        }
        else{
            f[temp] = -1;//repetido
        }
    }
    for(int i = 0; i < m; i++){
        int temp; cin >> temp;
        b[i] = temp;
        if(f[temp] == 0){
            cout << "Impossible";
            return 0;
        }
    }
    for(int i = 0; i < m; i++){
        int temp = b[i];
        if(f[temp] == -1){
            cout << "Ambiguity";
            return 0;
        }
        as.push_back(f[temp]);
    }
    cout << "Possible" << endl;
    for(int i = 0; i < m; i++){
        cout << as[i] << " ";
    }

    return 0;
}
