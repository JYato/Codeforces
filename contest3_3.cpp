#include <bits/stdc++.h>

using namespace std;

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
    /*char letra_;
    for(int i = 0; i < cadenas[0].size(); i++){
        letra_ = cadenas[0][0];
        if(letra_ != letra){

        }
    }*/

    /*for(int i = 0; i < cadenas.size(); i++){
            cout << cadenas[i] << endl;
    }*/
    for(int i = 0; i < cadenas.size(); i++){
        for(int j = 0; j < cadenas[i].size() - 1; j++){
            if(cadenas[i][j] != cadenas[i][j+1]){
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    /*for(int i = 0; i < n; i++){
        if(findLocation(cadenas[i],letra) > 0){
            cout << "NO" << endl;
            return 0;
        }
    }*/
    cout << "YES" << endl;


    return 0;
}
