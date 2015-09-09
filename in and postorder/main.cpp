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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if(inorder.size()==0)
           return NULL;
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }

    TreeNode* build(vector<int>& inorder,int left1,int right1,vector<int>& postorder,int left2,int right2)
    {
        TreeNode* root;
        root=new TreeNode(postorder[right2]);
        if(left1==right1)
          return root;

        int mid1,mid2;
        for(mid1=left1;mid1<=right1;mid1++)
            if(inorder[mid1]==postorder[right2])
              break;
        mid2=mid1-left1+left2-1;

        if(mid1>left1)
           root->left=build(inorder,left1,mid1-1,postorder,left2,mid2);
        if(mid1<right1)
           root->right=build(inorder,mid1+1,right1,postorder,mid2+1,right2-1);
        return root;

    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
