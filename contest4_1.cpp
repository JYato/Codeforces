#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
    int r1,r2, c1, c2, d1, d2;
    cin >> r1 >> r2;
    cin >> c1 >> c2;
    cin >> d1 >> d2;
    int a,b,c,d;

    if(r1 == 1 || r2 == 1 || c1 == 1 || c2 == 1 || d1 == 1 || d2 == 1 || r1 == 2 || r2 == 2 || c1 == 2 || c2 == 2 || d1 == 2 || d2 == 2){
        cout << "-1" << endl;
        return 0;
    }
    else{
        for(a = 1; a <= 9; a++){
            b = r1 - a;
            c = c1 - a;
            d = d1 - a;
            if(r1 == a+b && r2 == c+d && c1 == a+c && c2 == b+d && d1 == a+d && d2 == c+b && a != b && a != c && a != d && b != c && b != d && c != d && a >= 1 && a <= 9 && b >= 1 && b <= 9 && c >= 1 && c <= 9 && d >= 1 && d <= 9){
                cout << a << " " << b << endl;
                cout << c << " " << d << endl;
                return 0;
            }
        }
    }
    cout << "-1" << endl;

    return 0;
}
