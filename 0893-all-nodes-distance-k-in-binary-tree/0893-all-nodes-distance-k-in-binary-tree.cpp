/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        findNodesAtDistanceK(root, target, k, result);
        return result;
    }

private:
    
    int findNodesAtDistanceK(TreeNode* root, TreeNode* target, int k, vector<int>& result) {
        if (root == nullptr) return -1;
        
        if (root == target) {
           
            collectSubtreeNodesAtDistanceK(root, k, result);
            return 0;
        }

        int leftDistance = findNodesAtDistanceK(root->left, target, k, result);
        if (leftDistance != -1) {
           
            if (leftDistance + 1 == k) {
                result.push_back(root->val);
            } else {
                collectSubtreeNodesAtDistanceK(root->right, k - leftDistance - 2, result);
            }
            return leftDistance + 1;
        }

        int rightDistance = findNodesAtDistanceK(root->right, target, k, result);
        if (rightDistance != -1) {
           
            if (rightDistance + 1 == k) {
                result.push_back(root->val);
            } else {
                collectSubtreeNodesAtDistanceK(root->left, k - rightDistance - 2, result);
            }
            return rightDistance + 1;
        }

        return -1;
    }

   
    void collectSubtreeNodesAtDistanceK(TreeNode* node, int k, vector<int>& result) {
        if (node == nullptr || k < 0) return;
        if (k == 0) {
            result.push_back(node->val);
            return;
        }
        collectSubtreeNodesAtDistanceK(node->left, k - 1, result);
        collectSubtreeNodesAtDistanceK(node->right, k - 1, result);
    }
};
