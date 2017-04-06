#include <stdio.h>
#include <stdlib.h>

typedef struct tree {
  int info;
  struct tree *left;
  struct tree *right;
};

tree *stree(tree *root, tree *r, int info)
{
    if(!r)
    {
        r = (tree *) malloc(sizeof(tree));
        if(!r)
        {
            printf("Не хватает памяти\n");
            exit(0);
        }
        r->left = NULL;
        r->right = NULL;
        r->info = info;
        if(!root) return r; /* первый вход */
        if(info < root->info) root->left = r;
        else root->right = r;
        return r;
    }
    if(info < r->info) stree(r,r->left,info);
    else stree(r,r->right,info);
    return root;
}

void preorder(tree *root) //deeper
{
    if(!root) return;
    if(root->info) printf("%i ", root->info);
    preorder(root->left);
    preorder(root->right);
}

void postorder(tree *root) //more width
{
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    if(root->info) printf("%i ", root->info);
}

tree* search_elem(tree *root, int searched)
{
    if(!root) return root;
    if (root->info == searched) return root;
    else
        if(root->info > searched) search_elem(root->left,searched);
        else search_elem(root->right,searched);
}

int main(void)
{
    int tr_elem,am_elem;
    printf("please enter amount of element ");
    scanf("%i",&am_elem);
    tree* root = NULL;  /* инициализация корня дерева */
    for (int i = 0; i < am_elem; ++i)
    {
        printf("please enter element of tree ");
        scanf("%i",&tr_elem);
        root = stree(root, root, tr_elem);
    }
    preorder(root);
    printf("\n");
    preorder(search_elem(root,17));
    return 0;
}
