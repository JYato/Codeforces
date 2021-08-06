#include <bits/stdc++.h>
 
using namespace std;
 
///B
 
int main()
{
    int t,n,a;
    bool jugador,s;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> n;
        jugador = 1;
        s = 1;
        for(int i = 1;i <= n; i++){
            cin >> a;
            if(i != n && a == 1 && s){
                jugador = 1-jugador;
            }
            else{
                s=0;
            }
        }
        if(jugador){
            cout<< "First" << endl;
        }
        else{
            cout<<"Second" << endl;
        }
  }
  return 0;
}