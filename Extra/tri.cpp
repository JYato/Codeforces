#include <bits/stdc++.h>

using namespace std;

int main()
{
    for(int j = 2; j <= 24; j+= 2){
        int n = j;
        vector<int> Dn(n+1);
        vector<int> An(n+1);
        Dn[0] = 1;
        Dn[1] = 0;
        An[0] = 0;
        An[1] = 1;
        for(int i = 2; i <= n; i++){
            Dn[i] = Dn[i-2] + An[i-1] + An[i-1];
            An[i] = Dn[i-1] + An[i-2];
        }
        cout << "n: " << n << endl;
        cout << "Cantidad: " << Dn[n] << endl;
    }
    /*int n; cout << "n : "; cin >> n;
    vector<int> Dn(n+1);
    vector<int> An(n+1);
    Dn[0] = 1;
    Dn[1] = 0;
    An[0] = 0;
    An[1] = 1;
    for(int i = 2; i <= n; i++){
        Dn[i] = Dn[i-2] + An[i-1] + An[i-1];
        An[i] = Dn[i-1] + An[i-2];
    }
    cout << Dn[n];
*/
    return 0;
}

