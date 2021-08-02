#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, m, i, l, r, x;
    set<int>::iterator it;
    set<int> s;

    scanf("%d%d", &n, &m);
    int ans[n + 1] = {0};
    for(i = 1; i <= n; i++)
    	s.insert(i);
    for(i = 0; i < m; i++){
    	scanf("%d%d%d", &l, &r, &x);
    	it = s.lower_bound(l);
    	while(it != s.end()){
    		if(*it > r)
    			break;
    		if(*it != x){
	    		ans[*it] = x;
	    		s.erase(it++);
	    	}
	    	else
	    		it++;
    	}
    }
    for(i = 1; i <= n; i++)
    	printf("%d ",ans[i]);

    return 0;
}
