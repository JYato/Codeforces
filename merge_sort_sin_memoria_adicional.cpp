#include <bits/stdc++.h>
#include <iostream>

#define ll long long int

using namespace std;


/*void mergesort(vector<int> &vec1, vector<int> &vec2)
{
    for(ll i = vec2.size(), j; i >= 0; i--){
        ll temp = vec1[vec1.size()-1];
        for(j = vec1.size()-2; j >= 0 && vec1[j] > vec2[i]; j--){
            vec1[j+1] = vec1[j];
        }
        if(temp > vec2[i] || j != vec1.size()-2){
            vec1[j+1] = vec2[i];
            vec2[i] = temp;
        }
    }
}*/

int main()
{
    /**vector<int> vec1 = {1, 5, 9, 10, 15, 20};
    vector<int> vec2 = {2, 3, 8, 13};

    for(ll i = vec2.size(), j; i >= 0; i--){
        ll temp = vec1[vec1.size()-1];
        for(j = vec1.size()-2; j >= 0 && vec1[j] > vec2[i]; j--){
            vec1[j+1] = vec1[j];
        }
        if(temp > vec2[i] || j != vec1.size()-2){
            vec1[j+1] = vec2[i];
            vec2[i] = temp;
        }
    }
    for (int i=0; i<vec1.size(); i++)
        cout << vec1[i] << " ";
    for (int i=0; i<vec2.size(); i++)
        cout << vec2[i] << " ";
    cout << "gaaaaaaaaaaa" << endl;
    vec1.insert(vec1.end(), vec2.begin(), vec2.end());
    for (int i=0; i<vec1.size(); i++)
        cout << vec1[i] << " ";*/

    ///sin memoria adicional
    vector<int> vec = {1, 5, 9, 10, 15, 20,2, 3, 8, 13};
    //vector<int> vec = {25,14,536,21,52,78,21,32,15,41};
    ll mitad = vec.size()/2; ///cout << "mitad :" << mitad << endl;
    for(ll i = vec.size(), j; i >= mitad; i--){
        ll temp = vec[mitad-1];
        for(j = mitad-2; j >= 0 && vec[j] > vec[i]; j--){
            vec[j+1] = vec[j];
        }
        if(temp > vec[i] || j != mitad-2){
            vec[j+1] = vec[i];
            vec[i] = temp;
        }
    }
   /// cout << endl << "gaaa" << endl;
    for (int i=0; i<vec.size(); i++)
        cout << vec[i] << " ";

    return 0;
}
