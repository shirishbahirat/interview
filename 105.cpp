#include <iostream>
#include <vector>

//Title: Construct Binary Tree from Preorder and Inorder Traversal

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return nullptr;
    }
};

int main(int argc, char const *argv[])
{
    Solution *obj = new Solution();

    return 0;
}
