#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    ll n, m; cin >> n >> m;
    vector<vector<ll> > adj(n+1);
    for(ll i = 0; i < m; i++){
        ll x, y; cin >> x >> y;
        ll pos = min(x,y);
        ll temp = max(x,y);
        adj[pos].push_back(temp);
    }
    vector<vector<pair<ll,ll> > > arr(n+2);
    ll temp = 0;
    for(ll i = 1; i <= n; i++){
        temp++;
        arr[i].push_back(make_pair(i,temp));
        for(ll j = 0; j < adj[i].size(); j++){
            temp++;
            ll temp2 = adj[i][j];
            arr[i].push_back(make_pair(i,temp));
            arr[temp2].push_back(make_pair(temp2, temp));
        }
    }
    for(ll i = 1; i <= n; i++){
        cout << arr[i].size() << endl;
        for(ll j = 0; j < arr[i].size(); j++){
            cout << arr[i][j].first << " " << arr[i][j].second << endl;
        }
    }

    return 0;
}
