#include <iostream>
#include <vector>
 
using namespace std;
#define ll long long int
 
void reducir(ll &a, ll &b){
    while(a < b){
        b--;
    }
}
 
 
int main()
{
    //////2
    ll n, S; cin >>n >> S;
    int cont = 0;
    while(S > 0 && n > 0){
        if(S < n){
            reducir(S,n);
        }
        S -= n;
        cont++;
    }
    cout << cont;
return 0;
}