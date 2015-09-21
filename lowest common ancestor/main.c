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
 //二叉搜索树的最低祖先
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root->val==p->val)
      return p;
    if(root->val==q->val)
      return q;
    if((root->val>p->val&&root->val<q->val)||(root->val<p->val&&root->val>q->val))
      return root;

    if(root->val>p->val&&root->val>q->val)
      return lowestCommonAncestor(root->left,p,q);
    if(root->val<p->val&&root->val<q->val)
      return lowestCommonAncestor(root->right,p,q);
}

//普通二叉树的最低祖先。如果根等于两个节点中的一个，返回根：否则，在左右子树中分别找节点p，q，若若都能找到，说明root即为lca：
//如果只能在某个子树中找到，那么找到的那个节点为lca！！！！！
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root==p||root==q||root==NULL)
      return root;

    struct TreeNode* left=lowestCommonAncestor(root->left,p,q);
    struct TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(left&&right)
      return root;

    return left?left:right;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
