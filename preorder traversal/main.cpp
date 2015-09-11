#include <iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//µÝ¹é
//class Solution {
//public:
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> res;
//        if(root==NULL)
//            return res;
//        preCore(res,root);
//        return res;
//    }
//
//    void preCore(vector<int>& res,TreeNode* root)
//    {
//        if(root==NULL)
//            return;
//
//        res.push_back(root->val);
//        preCore(res,root->left);
//        preCore(res,root->right);
//    }
//};

//·ÇµÝ¹é
class Solution {
public:
vector<int> preorderTraversal(TreeNode* root)
{
    stack<TreeNode*> ptr;
    vector<int> res;
    while(root!=NULL)
        {
         res.push_back(root->val);
         ptr.push(root);
         root=root->left;}

    while(!ptr.empty())
    {
        TreeNode* tmp=ptr.top();
        ptr.pop();

        TreeNode* tmp1=tmp->right;
        while (tmp1!=NULL)
        {
            res.push_back(tmp1->val);
            ptr.push(tmp1);
            tmp1=tmp1->left;
        }
    }
    return res;
}
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
