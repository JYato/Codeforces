#include <iostream>
#include <vector>

#define ll long long int
using namespace std;

const ll mod = 1000000007;


int main()
{

    int n; cin >> n;
    int a[10];
    vector<int> obligatorios;
    for(int i = 0; i < 10; i++){
        cin >> a[i];
        if(a[i] > 0 && a[i] <= n){
            obligatorios.push_back(i);
        }
    }

    int resp;

    resp = ans%mod;
}
