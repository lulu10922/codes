#include <iostream>
#include<vector>
#include<stack>
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
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> res;
//        if(root==NULL)
//            return res;
//
//        postCore(res,root);
//        return res;
//    }
//
//    void postCore(vector<int>& res,TreeNode* root)
//    {
//        if(root==NULL)
//            return;
//
//        postCore(res,root->left);
//        postCore(res,root->right);
//        res.push_back(root->val);
//    }
//};


//·ÇµÝ¹é
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root==NULL)
            return res;
        stack<TreeNode*> data;
        while(root!=NULL)
        {
            data.push(root);
            root=root->left;
        }

        while(!data.empty())
        {
            TreeNode*tmp;
            tmp=data.top();
            if(tmp->right==NULL)
            {
                res.push_back(tmp->val);
                data.pop();
            }
            else
            {
                TreeNode*tmp1=tmp->right;
                while(tmp1!=NULL)
                {
                    data.push(tmp1);
                    tmp1=tmp1->left;
                }

                tmp->right==NLL;
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
