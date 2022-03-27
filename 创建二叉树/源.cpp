#include <iostream>
#include <cstring>
using namespace std;

bool flag;
typedef struct tree
{
    char data;
    struct tree* left;
    struct tree* right;
}tree;
int get_tree_height(tree* root)
{
    if (root == NULL)
        return -1;
    int l = get_tree_height(root->left);
    int r = get_tree_height(root->right);
    return max(l, r) + 1;
}
void first_order(tree* root)
{
    if (root == NULL)
        return;
    printf("%c", root->data);
    first_order(root->left);
    first_order(root->right);
}
tree* rebuild_tree(char mid[], char last[], int n)
{
    if (n == 0)
        return NULL;
    tree* root = (tree*)malloc(sizeof(tree));
    root->data = last[n - 1];
    int i;
    for (i = 0; i < n; i++)
        if (mid[i] == last[n - 1])
            break;
    if (i == n)
    {
        flag = false;
        return NULL;
    }
    else
    {
        root->left = rebuild_tree(mid, last, i);
        root->right = rebuild_tree(mid + i + 1, last + i, n - i - 1);
    }
    return root;
}
int main()
{
    char mid[30], last[30];
    int len1, len2;
    while (scanf("%s", last) != EOF)
    {
        scanf("%s", mid);
        len1 = strlen(mid);
        len2 = strlen(last);
        flag = true;
        if (len1 != len2)
            cout << "INVALID" << endl;
        else
        {
            tree* root = rebuild_tree(mid, last, len1);
            if (flag)
            {
                cout << get_tree_height(root) << endl;
                first_order(root);
                cout << endl;
            }
            else
                cout << "INVALID" << endl;
        }
    }
}