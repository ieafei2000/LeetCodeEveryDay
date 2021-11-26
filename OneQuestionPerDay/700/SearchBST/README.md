# 解题思路
题目比较简单，由于是二叉搜索树，因此可以采用递归/队列去搜索，若val<node->val，则向左搜索，否则向右即可

# 通过率
执行用时（50%） 内存消耗（60%）


# 代码一（队列）

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        std::queue<TreeNode*> queue;
        queue.push(root);

       while (!queue.empty())
        {
            TreeNode* node = queue.front();
            queue.pop();
            
            if (node == nullptr)
                continue;
            else
            {
                std::cout << node->val << std::endl;
                if (val == node->val)
                    return node;
                else if (val < node->val)
                    queue.push(node->left);
                else
                    queue.push(node->right);
            }

        }
        return nullptr;
    }
};
```

# 代码二（递归）
```
TreeNode* searchBST(TreeNode* root, int val) 
    {
        if (root == nullptr)
            return nullptr;
        if (val == root->val)
            return root;
        else if (val < root->val)
            return searchBST(root->left, val);
        else
            return searchBST(root->right, val);
    }
```
