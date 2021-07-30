#include <iostream>
#include <string>
#include <sstream>

#define ll long long int

using namespace std;

int main()
{
    int L; cin >> L;
    string A; cin >> A;
    if(A.size() == L){
        stringstream aiuda(A);
        ll aiuda2 = 0; aiuda >> aiuda2;
        aiuda2++;
        stringstream aiuda3;
        aiuda3 << aiuda2;
        A = aiuda3.str();
        cout << A;
        return 0;
    }
    if(A.size()%L != 0){
        string res1 = "1";
        for(int i = 1; i < L; i++){
            res1 += "0";
        }
        ll tam = A.size()/L + 1;
        string res2 = "";
        while(tam--){
            res2 += res1;
        }
        cout << res2;
        return 0;
    }
    //------------------------------------else
    string base = "";
    for(int i = 0; i < L; i++){
        base += A[i];
    }
    stringstream aiudin(base);
    ll baseint = 0; aiudin >> baseint;
    ll index = L;
    while(index < A.size()){
        string temp = "";
        for(int i = 0; i < L; i++){
            temp += A[index];
            index++;
        }
        stringstream aiuda(temp);
        ll aiuda2 = 0;
        aiuda >> aiuda2;
        if(aiuda2 >= baseint){
            baseint++;
            break;
        }
    }
    stringstream aiuda3;
    aiuda3 << baseint;
    base = aiuda3.str();
    if(base.size() > L){
        base = "1";
        for(int i = 1; i < L; i++){
            base += "0";
        }
        L--;
    }
    ll tam = A.size()/L;
    A = "";
    for(ll i = 0; i < tam; i++){
        A += base;
    }
    cout << A;
    return 0;
}
