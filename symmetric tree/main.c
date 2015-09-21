#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool help(struct TreeNode* p,struct TreeNode* q)
{
    if(p==NULL&&q==NULL)
      return true;
    if(p==NULL||q==NULL)
      return false;

    if(p->val!=q->val)
      return false;
    return help(p->right,q->left)&&help(q->right,p->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)
      return true;

    return help(root->left,root->right);
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
