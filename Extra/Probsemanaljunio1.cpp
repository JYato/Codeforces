///Timofey and a tree
#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100010];
bool ok;
int color[100001];
int cur,n;
bool dfs(int v,int par)
{
	ok=ok&&(color[v]==cur);
	for(int i=0;i<adj[v].size();i++)
	{
		if(adj[v][i]!=par)
		  dfs(adj[v][i],v);
	}
}
bool solve(int v)
{
	bool ans=true;
	for(int i=0;i<adj[v].size();i++)
	{
		ok=true;
		cur=color[adj[v][i]];
		dfs(adj[v][i],v);
		ans=ans&&ok;
	}
	return ans;
}
int main()
{
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y; cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1;i<=n;i++) cin>>color[i];

	int root1=-1,root2=-1;

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<adj[i].size();j++)
		{
			if(color[adj[i][j]]!=color[i])
			{
				root1=adj[i][j];
				root2=i;
			}
		}
	}
	if(root1==-1)
	{
	    cout<<"YES\n1"<<endl;
	    return 0;
    }
	bool res1=solve(root1);
	bool res2=solve(root2);
	if(res1)
	{
		cout<<"YES"<<endl;
		cout<<root1<<endl;
	}
	else if(res2)
	{
		cout<<"YES\n";
		cout<<root2;
	}
	else cout<<"NO"<<endl;

	return 0;
}
