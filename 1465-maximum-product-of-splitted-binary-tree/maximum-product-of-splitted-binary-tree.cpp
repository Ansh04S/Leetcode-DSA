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
class Solution {
public:
    int maxProduct(TreeNode* root) {
        const int MOD = 1e9 + 7;
        long long totalSum = 0;
        long long maxProduct = 0;
        
        function<void(TreeNode*)> computeTotalSum = [&](TreeNode* node) {
            if (!node) return;
            totalSum += node->val;
            computeTotalSum(node->left);
            computeTotalSum(node->right);
        };
        
        computeTotalSum(root);
        
        function<long long(TreeNode*)> dfs = [&](TreeNode* node) -> long long {
            if (!node) return 0;
            
            long long leftSum = dfs(node->left);
            long long rightSum = dfs(node->right);
            long long subtreeSum = leftSum + rightSum + node->val;
            
            long long product = subtreeSum * (totalSum - subtreeSum);
            maxProduct = max(maxProduct, product);
            
            return subtreeSum;
        };
        
        dfs(root);
        
        return maxProduct % MOD;
    }
};