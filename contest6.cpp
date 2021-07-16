#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ll n,l; cin >> n >> l;
    vector<double> linternas(n);
    for(ll i = 0; i < n; i++){
        cin >> linternas[i];
    }
    sort(linternas.begin(), linternas.end());
    double distancia = linternas[0]-0;
    for(ll i = 1; i < n; i++){
        if((linternas[i] - linternas[i-1])/2 > distancia){
            distancia = (linternas[i] - linternas[i-1])/2;
        }
    }
    distancia = max(distancia,l-linternas[n-1]);
    cout << fixed << setprecision(10) << distancia;
    return 0;
}
