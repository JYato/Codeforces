#include <iostream>
#include <string>

#define ll long long int
using namespace std;

int main()
{
    int L; cin >> L;
    string A; cin >> A;
    int tam_a = A.size();
    if(tam_a%L != 0){
        string res1 = "1";
        for(int i = 1; i < L; i++){
            res1 += "0";
        }
        /*for(int i = 0; i < (tam + L - 1)/L; i++){
            X += res1;
        }*/
        ll tam = (tam_a + L -1)/L;
        string res2 = "";
        while(tam--){
            res2 += res1;
        }
        cout << res2;
        return 0;
    }
    string base = "";
    for(int i = 0; i < L; i++)
        base += A[i];
    string cadena = "";
    for(int i = 0; i < tam_a/L; i++)
        cadena += base;
    if(cadena > A){
        cout << cadena << endl;
        return 0;
    }
    string temp = base;
    bool div = 1;
    for(int i = temp.size()-1; i >= 0; i--){
        int dig = temp[i] - '0';
        dig += div;
        temp[i] = (char) ('0' + dig%10);
        div = dig/10;
    }
    if(div == false)base = temp;
    else base = "";
    if(base == ""){
        string X = "";
        string sub = "1";
        for(int i = 1; i < L; i++){
            sub += "0";
        }
        for(int i = 0; i <= tam_a/L; i++){
          X += sub;
        }
        cout << X << endl;
        return 0;
    }
    cadena = "";
    for (int i = 0; i < tam_a/ L; i++) {
        cadena += base;
    }
    cout << cadena << endl;
    return 0;
    /** if (p1 == "") {
        string ans = "";
        string p = "1" + string(L - 1, '0');
        for (int i = 0; i <= n / L; i++) {
            ans += p;
        }
        cout << ans << "\n";
        return 0;
    }

    cand1 = "";
    for (int i = 0; i < n / L; i++) {
        cand1 += p1;
    }
    cout << cand1 << "\n";
    return 0;*/
    /*int L; cin >> L;
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
    cout << A;*/
}
