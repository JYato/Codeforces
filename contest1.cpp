#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*int main()
{
    int test; cin >> test;
    int res;
    while(test){
        int a, b; cin >> a >> b;
        res = a%b;
        if(res == 0){
            cout << 0 << endl;
        }
        else{
            int moves = b - res;
            cout << moves << endl;
        }
        test--;
    }
    return 0;
}
*/

int main()
{
    int test; cin >> test;
    while(test){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        for(int i = 0,j; i < j; i++){
            for(j = n-1; j >= i; j--){
                if(arr[i] == arr[j]){
                    cout << "YES" << endl;
                    break;
                }
            }
        }
        cout << "NO" << endl;
        test--;
    }

    return 0;
}


#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n; cin>>n; int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)for(int j=i+2;j<n;j++)if(a[i]==a[j]){cout<<"YES"<<endl; return;}
    cout<<"NO"<<endl;
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
