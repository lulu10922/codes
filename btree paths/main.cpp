#include <iostream>
#include<vector>
#include<string>
using namespace std;


 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL)
          return res;
        string tmp;
        TreePaths(res,to_string(root->val),root);
        return res;
    }
    void TreePaths(vector<string>& res,string tmp,TreeNode* root)
    {

        if(root->left==NULL&&root->right==NULL)
        {
            res.push_back(tmp);
            return;
        }

        if(root->left)
        {
            TreePaths(res,tmp+"->"+to_string(root->left->val),root->left);
        }
        if(root->right)
        {
            TreePaths(res,tmp+"->"+to_string(root->right->val),root->right);
        }

        return;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
