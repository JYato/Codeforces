#include <iostream>
#include <vector>
#include <stdio.h>

#define ll long long int

using namespace std;

int main()
{
    int L; cin >> L;
    //ll A, temp; cin >> A;
    string A; cin >> A;
    string base = "";
    for(int i = 0; i < L; i++){
        base += A[i];
    }
    for(int i = L; )
   /* string cadena; cin >> cadena;
    for(int i = 0; i < cadena.size(); i++){
        cout << cadena[i];
    }*/

    /*char cadena[6]; scanf("6s",cadena);
    for(int i = 0; i < 6; i++){
        cout << cadena[i];
    }*/
    /*int L; cin >> L;
    ll A, temp; cin >> A;
    temp = A;
    int cant_dig = 0, i = L-1;
    vector<int> A_vec(L);
    while(temp){
        A_vec[i] = temp%10;
        temp /= 10;
        cant_dig++;
        i--;
    }
    //int tam;
    if(cant_dig%L == 0){temp = L;}
    else{ temp = cant_dig + L -(cant_dig + L)%L;}
    vector<int> X(temp));*/

    return 0;
}
