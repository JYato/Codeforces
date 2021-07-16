#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main()
{
    int n,m; cin >> n >> m;
    set<int> caballeros;
    vector<int> vencidos_por(n+1,0);
    for(int i = 1; i <= n; i++){
        caballeros.insert(i);
    }
    while(m--){
        int l, r, x; cin >> l >> r >> x;
        set<int>::iterator it1 = caballeros.lower_bound(l);
        set<int>::iterator it2 = caballeros.upper_bound(r);
        while(it1 != it2){
            if(*it1 != x){
                vencidos_por[*it1] = x;
                caballeros.erase(it1++);
            }
            else{it1++;}
        }
    }
    for(int i = 1; i <= n; i++){
        cout << vencidos_por[i] << " ";
    }
    return 0;
}
