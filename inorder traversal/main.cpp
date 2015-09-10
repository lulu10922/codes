#include <iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {     int val;
    TreeNode *left;
    TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//递归方法
//void inordercore(vector<int>& res,TreeNode* root)
//{
//    if(root==NULL)
//        return;
//
//    inordercore(res,root->left);
//    res.push_back(root->val);
//    inordercore(res,root->right);
//
//    return;
//}
//
//vector<int> inorderTraversal(TreeNode* root)
//{
//    vector<int> res;
//    inordercore(res,root);
//    return res;
//}

//非递归方法
vector<int> inorderTraversal(TreeNode* root)
{
    stack<TreeNode*> ptr;
    vector<int> res;
    while(root!=NULL)
        {ptr.push(root);
         root=root->left;}

    while(!ptr.empty())
    {
        TreeNode* tmp=ptr.top();
        res.push_back(tmp->val);
        ptr.pop();

        TreeNode* tmp1=tmp->right;
        while (tmp1!=NULL)
        {
            ptr.push(tmp1);
            tmp1=tmp1->left;
        }
    }
    return res;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
