#include <bits/stdc++.h>

using namespace std;

void cambiar(string &a, int tam)
{
    for(int i = 0; i <= tam; i++){
        if(a[i] == "1"){
            a[i] = "0";
        }
        else{
            a[i] = "1";
        }
    }
    for(int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}

int main()
{
    string a, b;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cin >> a;
        cin >> b;
        bool dif = 0;
        int anterior = -1;
        while(!dif){
            if(a[j] != b[j]){

            }
        }
    }
    return 0;
}
/*
///B

int main()
{
    int t,n,a;
    bool jugador,s;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> n;
        jugador = 1;
        s = 1;
        for(int i = 1;i <= n; i++){
            cin >> a;
            if(i != n && a == 1 && s){
                jugador = 1-jugador;
            }
            else{
                s=0;
            }
        }
        if(jugador){
            cout<< "First" << endl;
        }
        else{
            cout<<"Second" << endl;
        }
  }
  return 0;
}*/
/*
int main()
{
    vector<int> pilas;
    int jugador = 0; //0 fiirst, 1 second
    int t; cin >> t;
    int n;
    for(int i = 0; i < t; i++){
        cin >> n;
        pilas.clear();
        for(int j = 0; j < n; j++){
            int temp; cin >> temp;
            pilas.push_back(temp);
        }
        for(int j = 0; j < n;){
            if(pilas[j] > 0 && pilas[0] != 0){
                pilas[j] - 1;
            }
            else if(pilas[j] > 0 && pilas[0] == 0){
                pilas[j] = 0;
                j++;
            }
            else if(pilas[j] == 0 && j < n-1){
                j++;
            }
            else if(pilas[j] == 0 && j == n-1){
                if(jugador == 0){
                    cout << "FIRST";
                }
                else{
                    cout << "SECOND";
                }
            }
        }
    }
    return 0;
}*/

/*
int main(){
    int t, n, m,a,b,index; cin >> t;
    while (t--) {
        vector<int> A;
        vector<int> B;
        vector<int> C;
        vector<int>::iterator it;
        index = 0;
        A.clear();
        B.clear();
        C.clear();
        cin >> n >> m;
        for (int i = 0;i<n ; i++) {
            cin >> a;
            A.push_back(a);
        }
        for (int j = 0; j < m; j++) {
            cin >> b;
            B.push_back(b);
        }
        for (int i = 0; i < n; i++) {
                it = find(B.begin()+index, B.end(), A[i]);
                if (it != B.end()) {
                    index = it - B.begin();
                    C.push_back(*it);
                }

        }if (!C.size()) {
            cout << "NO" << endl;

        }else {
            cout << "YES" << endl;
            cout << 1<<" ";
                cout << C[0];
            cout << endl;
        }
    }
    return 0;
}
*/
