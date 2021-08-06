#include <bits/stdc++.h>
 
using namespace std;
 
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
