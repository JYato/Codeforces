#include <iostream>

#define ll long long int
using namespace std;

int main()
{
    int q; cin >> q;
    while(q--){
        ll c, m, x; cin >> c >> m >> x;
        ll temp = c + m + x;
        temp /=3;
        ll equipos;
        if(c < m)equipos = c;
        else equipos = m;
        if(equipos < temp)cout << equipos << endl;
        else cout << temp << endl;
    }
    return 0;
}
