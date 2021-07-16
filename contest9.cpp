///C
/*#include <bits/stdc++.h>

#define MAXI 100010

using namespace std;


int main()
{
    int n; cin >> n;
    vector<int> arr(MAXI);
    vector<int> vec;
    for (int i = 0 ; i < n ; i++)
        cin >> arr[i];
    for (int i = 0 ; i < n ; i++){
        int pos = upper_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
        if (pos == vec.size()){
            vec.push_back(arr[i]);
        }
        else{
            vec[pos] = arr[i];
        }
    }

    cout << vec.size() << endl;
    return 0;
}*/

///D
#include <bits/stdc++.h>

using namespace std;

int N = 200007, MOD = 998244353;

string s1, s2;

int d[N];

int main()
{
    int n, m, ans(0), ras(0);
    cin >> n >> m >> s1 >> s2;
    d[0] = 1;
    for (int i = 1; i < min(n, m); ++i)
        d[i] = (d[i - 1]<<1) % MOD;
    for (int i = min(n, m) - 1; i >= 0; --i) {
        ans += d[i] * (s1[n - i - 1] - '0');
        if (ans >= MOD)
            ans -= MOD;
    }
    for (int i = m - 1; i >= 0; --i) {
        ras += ans * (s2[m - i - 1] - '0');
        if (ras >= MOD)
            ras -= MOD;
        if (i < n) {
            ans -= d[i] * (s1[n - i - 1] - '0');
            if (ans < 0)
                ans += MOD;
        }
    }
    cout << ras;
    return 0;
}
///F
/*#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k; cin >> n >> m >> k;
    int x;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> x;
        }
    }
    cout << (m*(m-1))/2  << endl;
    for (int i = 1; i <= m; i++){
        for (int j = i + 1; j <= m; j++){
            if (k == 0){
                cout << i << " " << j << endl;
            }
            else{
                cout << j << " " << i << endl;
            }
        }
    }

    return 0;
}*/


/*using namespace std;

int main()
{

    return 0;
}
*/
