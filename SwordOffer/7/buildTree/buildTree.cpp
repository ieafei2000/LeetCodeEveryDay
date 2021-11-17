#include <iostream>
#include <vector>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    if (preorder.empty() || inorder.empty())
    {
        return nullptr;
    }

    TreeNode* node = new TreeNode(preorder[0]);
    
    //计算preorder[0]在inorder中的位置
    auto it = find(inorder.begin(), inorder.end(), preorder[0]);

    //cout << node.val << endl;

    //根据it去计算左右子树的中序，前序数组大小
    vector<int> iLeft(inorder.begin(), it);
    vector<int> iRight(it + 1, inorder.end());
    vector<int> pLeft(preorder.begin() + 1, preorder.begin() + 1 + iLeft.size());
    vector<int> pRight(preorder.begin() + 1 + iLeft.size(), preorder.end());

    node->left = buildTree(pLeft, iLeft);
    node->right = buildTree(pRight, iRight);

    return node;
}

int main()
{
    vector<int> preorder = { 3,9,20,15,7 };
    vector<int> inorder = { 9,3,15,20,7 };

    TreeNode* root =  buildTree(preorder, inorder);
} 

