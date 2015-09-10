#include <iostream>

using namespace std;

class Solution {
public:
    int maxValue;
    int maxPathSum(TreeNode* root) {
        maxValue = -20;
        maxPathDown(root);
        return maxValue;
    }

     int maxPathDown(TreeNode* node) {
        if (node == NULL) return 0;
        int left = max(0, maxPathDown(node->left));
        int right = max(0, maxPathDown(node->right));
        maxValue = max(maxValue, left + right + node->val);
        return max(left, right) + node->val;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
