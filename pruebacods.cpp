/* A Naive recursive implementation of LCS problem */
#include <bits/stdc++.h>
using namespace std;

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs( char *X, char *Y, int m, int n )
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m-1] == Y[n-1])
        return 1 + lcs(X, Y, m-1, n-1);
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

/* Utility function to get max of 2 integers */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/* Driver code */
int main()
{
    char X[] = "10864";
    char Y[] = "12345";

    int m = strlen(X);
    int n = strlen(Y);

    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;

    return 0;
}

// This code is contributed by rathbhupendra


/*void imprimir(vector<int> arr)
{
    //cout << "hola" << endl;
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i];
    }
    cout << endl;
}
vector<int> comparar(vector<int> a, vector<int> b)
{
    vector<int> res;
    for(int i = 0,j=0; i < a.size() && j < b.size(); i++){
        for(; j < b.size(); j++){
            if(a[i] == b[j]){
                res.push_back(a[i]);
                i++;
            }
        }
    }
    //imprimir(res);
    return res;
}


int main()
{
    int t; cin >> t;
    vector<int> a;
    vector<int> b;
    int n,m;
    for(int i = 0; i < t; i++){

        cin >> n >> m;
        a.clear();
        b.clear();
        for(int j = 0; j < n; j++){
            int temp; cin >> temp;
            a.push_back(temp);
        }
        for(int j = 0; j < m; j++){
            int temp; cin >> temp;
            b.push_back(temp);
        }
        //cout << "ram :" << b.size() << endl;
        //imprimir(b);
        vector<int> c = comparar(a,b);
        if(c.size() > 0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        cout << c.size() << " ";
        for(int j = 0; j < c.size(); j++){
            cout << c[j] << " ";
        }
    }

    return 0;
}
/*
