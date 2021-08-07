#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
	long long int n,ans,p=0,o=0,q,t=1,i;
	cin >> n;
	q = (n*(n+1))/2;
	long long int a[n];
	for(i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > 0)
			t = t*1;
		else
			t = t*-1;
		if(t == 1)
			p++;
		else
			o++;			
		ans = (p*o)+o	;
			
	}
	cout << ans << " " << q-ans;
}
 