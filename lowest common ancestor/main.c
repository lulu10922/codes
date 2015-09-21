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
 //�������������������
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

//��ͨ��������������ȡ���������������ڵ��е�һ�������ظ������������������зֱ��ҽڵ�p��q�����������ҵ���˵��root��Ϊlca��
//���ֻ����ĳ���������ҵ�����ô�ҵ����Ǹ��ڵ�Ϊlca����������
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
