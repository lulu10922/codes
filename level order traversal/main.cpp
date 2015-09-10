#include <iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if(root==NULL)
            return res;
        queue<TreeNode*> data;

        data.push(root);
        while(!data.empty())
        {
            int size=data.size();
            vector<int> onelevel(size,0);
            for(int i=0;i<size;i++)
            {
                TreeNode* tmp=data.front();
                data.pop();

                onelevel[i]=tmp->val;

                if(tmp->left!=NULL)
                    data.push(tmp->left);
                if(tmp->right!=NULL)
                    data.push(tmp->right);
            }
            res.push_back(onelevel);
        }

        return res;
    }
};
//逆序输出
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        stack<vector<int> > res1;
        if(root==NULL)
            return res;
        queue<TreeNode*> data;

        data.push(root);
        while(!data.empty())
        {
            int size=data.size();
            vector<int> onelevel(size,0);
            for(int i=0;i<size;i++)
            {
                TreeNode* tmp=data.front();
                data.pop();

                onelevel[i]=tmp->val;

                if(tmp->left!=NULL)
                    data.push(tmp->left);
                if(tmp->right!=NULL)
                    data.push(tmp->right);
            }
            res1.push(onelevel);
        }

        for(int i=0;i<res1.size();i++)
        {
            res.push_back(res1.top());
            res1.pop();
        }
        return res;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
