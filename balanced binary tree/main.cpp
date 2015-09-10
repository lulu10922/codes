#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int height(TreeNode* root)
{
    if(root==NULL)
        return 0;

    int leftheight=height(root->left);
    int rightheight=height(root->right);

    return rightheight>leftheight?(rightheight+1):(leftheight+1);
}

bool isBalanced(TreeNode* root)
{
    if(root==NULL)
        return 1;
    int leftheight=height(root->left);
    int rightheight=height(root->right);

    if(!(leftheight==rightheight||leftheight-rightheight==1||rightheight-leftheight==1))
        return 0;

    return isBalanced(root->left)&&isBalanced(root->right);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
