//Fuente geeksforgeeks
#include "iostream"
#include "vector"
#include "math.h"

using namespace std;

#define MAXN 1001

int block_sz;
int depth[MAXN];
int parent[MAXN];

int jump_parent[MAXN];

vector < int > adj[MAXN];

void addEdge(int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int LCANaive(int u,int v)
{
    if (u == v)  return u;
    if (depth[u] > depth[v])
        swap(u,v);
    v = parent[v];
    return LCANaive(u,v);
}

void dfs(int cur, int prev)
{
    depth[cur] = depth[prev] + 1;
    parent[cur] = prev;
    if (depth[cur]%block_sz == 0){
        jump_parent[cur] = parent[cur];
    }
    else{
        jump_parent[cur] = jump_parent[prev];
    }
    for (int i = 0; i<adj[cur].size(); ++i){
        if (adj[cur][i] != prev)
            dfs(adj[cur][i], cur);
    }
}


int LCASQRT(int u, int v)
{
    while (jump_parent[u] != jump_parent[v])
    {
        if (depth[u] > depth[v])
            swap(u,v);

        v = jump_parent[v];
    }
    return LCANaive(u,v);
}

void preprocess(int height)
{
    block_sz = sqrt(height);
    depth[0] = -1;
    dfs(1, 0);
}

int main(int argc, char const *argv[])
{
    addEdge(1,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,7);
    addEdge(4,8);
    addEdge(4,9);
    addEdge(9,10);
    addEdge(9,11);
    addEdge(7,12);
    addEdge(7,13);

    int height = 4;
    preprocess(height);

    cout << "LCA(11,8) : " << LCASQRT(11,8) << endl;
    cout << "LCA(5,10) : " << LCASQRT(5,10) << endl;

    return 0;
}
