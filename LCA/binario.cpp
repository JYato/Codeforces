#include<bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
/*struct node
{
    int data;
    struct node* left, *right;
};

struct node *lca(struct node* root, int n1, int n2)
{
    while (root != NULL)
    {
        if(root->data > n1 && root->data > n2){
            root = root->left;
        }
        else if(root->data < n1 && root->data < n2){
            root = root->right;
        }
        else{break;}
    }
    return root;
}*/

struct node{
    int val;
    vector<node*> hijos;
    node* padre;
};
struct node *lca(struct node* n1, struct node* n2){
    set<node*> developed;
    while(n1){
        developed.insert(n1);
        n1 = n1->padre;
    }
    while(n2){
        if(developed.find(n2) != developed.end()){
            break;
        }
        n2 = n2->padre;
    }
    return n2;

};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}

int main()
{
    struct node *root     = newNode(20);
    root->left             = newNode(8);
    root->right             = newNode(22);
    root->left->left         = newNode(4);
    root->left->right     = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 4, n2 = 14;
    struct node *t = lca(root, n1, n2);
    printf("LCA de %d y %d es %d \n", n1, n2, t->data);

    /*n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);*/

    return 0;
}
