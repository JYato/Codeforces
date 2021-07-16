#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
    if (a == 0){
       return b;
    }
    if (b == 0){
       return a;
    }
    if (a == b){
        return a;
    }
    if (a > b){
        return gcd(a-b, b);
    }
    return gcd(a, b-a);
}


int main()
{
    ll a,b,c,d; cin >> a >> b >> c >> d;
    ll temp1, temp2;
    if(a*d >= b*c){
        temp1 = a*d;
        temp1 -= b*c;
        temp2 = a*d;
    }
    else{
        temp1 = b*c - a*d;
        temp2 = b*c;
    }
    ll euclides = gcd(temp1, temp2);
    temp1 /= euclides;
    temp2 /= euclides;

    cout << temp1 << "/" << temp2 << endl;
    //cout << gcd(6,20);

    return 0;
}
