#include <iostream>
#include<vector>

using namespace std;



struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        if(preorder.size()==0)
           return NULL;
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder,int left1,int right1,vector<int>& inorder,int left2,int right2)
    {
        TreeNode* root;
        root=new TreeNode(preorder[left1]);
        if(left1==right1)
          return root;

        int mid1,mid2;
        for(mid2=0;mid2<=right2;mid2++)
            if(inorder[mid2]==preorder[left1])
              break;
        mid1=mid2-left2+left1;

        if(mid2>left2)
           root->left=build(preorder,left1+1,mid1,inorder,left2,mid2-1);
        if(mid2<right2)
           root->right=build(preorder,mid1+1,right1,inorder,mid2+1,right2);
        return root;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
