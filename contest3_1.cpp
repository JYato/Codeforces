#include <bits/stdc++.h>

using namespace std;

/*int main()
{
    int l,r,a; cin >> l >> r >> a;
    int total;
    if(l > r){
        int temp = l;
        l = r;
        r = temp;
    }
    total = l + a;
    if(total <= r){
        total *= 2;
    }
    else{
        total -= r;
        total /= 2;
        total += r;
        total *= 2;
    }
    cout << total << endl;


    return 0;
}*/

int findLocation(string sample, char findIt)
{
    vector<int> characterLocations;
    for(int i =0; i < sample.size(); i++)
        if(sample[i] == findIt)
            characterLocations.push_back(sample[i]);

    return characterLocations.size();
}


int main()
{
    int n; cin >> n;
    vector<string> cadenas_(n);
    for(int i = 0; i < n; i++){
        cin >> cadenas_[i];
    }
    vector<string> cadenas;
    cadenas = cadenas_;
    char letra = cadenas[0][0];
    for(int i = 0, j = n-1; i <= j; i++, j--){
        if(cadenas_[i][j] == letra && cadenas_[j][i] == letra && cadenas_[i][i] == letra && cadenas_[j][j] == letra){
            cadenas[j].erase(j,1);
            cadenas[j].erase(i,1);
            cadenas[i].erase(j,1);
            cadenas[i].erase(i,1);
        }
    }
    /*string letra_ = letra;*/

    for(int i = 0; i < n; i++){
        if(findLocation(cadenas[i],letra) > 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;


    return 0;
}
