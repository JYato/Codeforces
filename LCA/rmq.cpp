//Fuente geekforgeeks
#include<bits/stdc++.h>

#define V 5

using namespace std;

int euler[2*V - 1];
int nivel[2*V - 1];
int primeraOcurrencia[V+1];
int ind;

struct Node
{
    int key;
    struct Node *left, *right;
};

Node * newNode(int k)
{
    Node *temp = new Node;
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

// log base 2 of x
int Log2(int x)
{
    int ans = 0 ;
    while (x>>=1) ans++;
    return ans ;
}

int RMQUtil(int index, int low, int high, int qlow, int qhigh, int *st)
{
    if (qlow <= low && qhigh >= high)///total overlap
        return st[index];
    else if (high < qlow || low > qhigh)///no overlap
        return -1;
    ///partial overlap
    int mid = (low + high)/2;
    int q1 = RMQUtil(2*index+1, low, mid, qlow, qhigh, st);///hijo izquierdo
    int q2 = RMQUtil(2*index+2, mid+1, high, qlow, qhigh, st);///hijo derecho
    if (q1==-1) return q2;
    else if (q2==-1) return q1;
    return (nivel[q1] < nivel[q2]) ? q1 : q2;
}


int RMQ(int *st, int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Entrada invalida");
        return -1;
    }
    return RMQUtil(0, 0, n-1, qs, qe, st);
}

///0,0,16,nivel,st
void constructSTUtil(int si, int ss, int se, int nivel_[], int *st)
{
    if (ss == se)st[si] = ss;

    else
    {
        int mid = (ss + se)/2;
        constructSTUtil(si*2+1, ss, mid, nivel_, st);
        constructSTUtil(si*2+2, mid+1, se, nivel_, st);

        if (nivel_[st[2*si+1]] < nivel_[st[2*si+2]]){
            st[si] = st[2*si+1];
        }
        else{
            st[si] = st[2*si+2];
        }
    }
}


int *constructST(int nivel_[], int n)
{
    int x = Log2(n)+1;
    int max_size = 2*(1<<x) - 1;  //  2*pow(2,x) -1 = 31


    int *st = new int[max_size];
    constructSTUtil(0, 0, n-1, nivel_, st);
    return st;
}

void eulerTour(Node *actual, int l)
{
    if (actual)//nodo actual
    {
        euler[ind] = actual->key; // insertar en euler array
        nivel[ind] = l;         // insertar l en nivel array
        ind++;                  // incrementar index

        if (primeraOcurrencia[actual->key] == -1){
            primeraOcurrencia[actual->key] = ind-1;
        }
        if (actual->left)
        {
            eulerTour(actual->left, l+1);
            euler[ind] = actual->key;
            nivel[ind] = l;
            ind++;
        }

        if (actual->right)
        {
            eulerTour(actual->right, l+1);
            euler[ind]=actual->key;
            nivel[ind] = l;
            ind++;
        }
    }
}

int LCA(Node *root, int u, int v)
{
    memset(primeraOcurrencia, -1, sizeof(int)*(V+1));
    ind = 0;//ayuda
    eulerTour(root, 0);
    int *st = constructST(nivel, 2*V-1);

    if (primeraOcurrencia[u] > primeraOcurrencia[v])
       swap(u, v);

    int qs = primeraOcurrencia[u];
    int qe = primeraOcurrencia[v];

    int index = RMQ(st, 2*V-1, qs, qe);
    return euler[index];
}

int main()
{
    Node * root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    /*root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->right->left = newNode(8);
    root->left->right->right = newNode(9);*/

    int u = 4, v = 3;
    printf("El LCA del nodo %d y el nodo %d es el nodo %d.\n", u, v, LCA(root, u, v));
    return 0;
}
