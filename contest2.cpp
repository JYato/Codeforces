#include <bits/stdc++.h>

#define ll long long int

using namespace std;

//lunch
/*int main()
{
    ll n,k;
    cin >> n >> k;
    vector<ll> res(n);
    ll maximo = 0;
    for(ll i = 0; i < n; i++){
        ll f,t;
        cin >> f >> t;
        if(t > k){
            res[i] = f - (t-k);
        }
        else{
            res[i] = f;
        }
    }
    cout << *max_element(res.begin(), res.end()) << endl;

    return 0;
}*/


// ways
int main()
{
    ll n; cin >> n;
    ll suma = 0, res = 0;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++){
        ll temp; cin >> temp;
        suma += temp;
        arr[i] = suma;
    }
    if(suma%3 != 0){
        cout << "0" << endl;
    }
    suma /= 3;//total
    ll cant = 0;
    for(ll i = 0; i < n-1; i++){
        if(arr[i] == suma){
            cant++;
        }
    }
    suma *= 2;
    for(ll i = 0; i < n-1; i++){
        if(arr[i] == suma){
            cant++;
        }
    }
    res += cant;
    cout << res << endl;
    return 0;
}
