#include <iostream>
#include <vector>

using namespace std;

class Punto{
    double x, y;
public:
    Punto(double x, double y):x(x),y(y){}
};
int main()
{
    int n; cin >> n;
    Punto A(0,0), B(1000,0) ,C(0,1000);
    vector<Punto> puntos;
    double prom_x = 0, prom_y = 0;
    for(int i = 0; i < n; i++){
        double t1, t2;
        cin >> t1 >> t2;
        prom_x += t1;
        prom_y += t2;
        //cout << endl;
    }
    prom_x /= n;
    prom_y /= n;

    cout << "x : " << prom_x << endl;
    cout << "y : " << prom_y << endl;

    return 0;
}
