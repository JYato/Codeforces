///B
/*#include <bits/stdc++.h>

#define ll long long
#define pi 3.141592654

using namespace std;

int main()
{
    ll n, a, b;
	cin >> n >> a >> b;
	vector <ll> vim(n);
	vector <ll> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vim[i];
		vec[i] = ((a*vim[i])%b)/a;
	}
	for (int i = 0; i < n; i++)
		cout << vec[i] << " ";

	return 0;
}*/

///C
/*#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    vector<pair<int,int>> vec;
    for(int i= 0; i< n; i++){
        int a,b; cin >> a >> b;
        vec.push_back(make_pair(a,b));
    }
    sort(vec.begin(), vec.end());
    int ult = vec[0].second;
    for(int i= 1; i< n; i++){
        if(vec[i].second >= ult){
            ult = vec[i].second;
        }
        else if(vec[i].second< ult){
            ult = vec[i].first;
        }
    }
    cout << ult;

    return 0;
}
*/
///D
#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,p; cin >> n >> p;
	string cad; cin >> cad;
	int temp; temp = n-1; cad[temp]++;
	for(;(temp >= 0) && (temp < n);){
		if((cad[temp]-'a') >= p){
			cad[temp]='a'; temp--;
			if(temp >= 0){
				cad[temp]++;
			}
		}
		else if(temp >= 1 && cad[temp-1]==cad[temp]){
			cad[temp]++;
		}
		else if(temp >= 2 && cad[temp-2]==cad[temp]){
			cad[temp]++;
		}
		else{
			temp++;
		}
	}
	if(temp < 0){
		cout<<"NO" << endl;
	}
	else{
		cout << cad << endl;
	}
	return 0;
}


///E
/*#include <bits/stdc++.h>

#define ll long long int

using namespace std;

bool primo(int num){
    for(int i=2; i < num ; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin >> n >> m;
    if(primo(m) == 0){
        cout<< "NO" <<endl;
        return 0;
    }
    for(int i = n+1; i < m; i++){
        if(primo(i) == 1){
            cout<< "NO" <<endl;
            return 0;
        }
    }
    cout<< "YES" <<endl;
    return 0;
}
*/
