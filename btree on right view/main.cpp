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
    vector<int> rightSideView(TreeNode* root) {
             vector<int> res;
             core(res,root,0);
             return res;
    }

    void core(vector<int>& res,TreeNode* root,int level)
    {
        if(root==NULL)
            return;
        if(level==res.size())
        {
            res.push_back(root->val);
        }

        core(res,root->right,level+1);
        core(res,root->left,level+1);
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
