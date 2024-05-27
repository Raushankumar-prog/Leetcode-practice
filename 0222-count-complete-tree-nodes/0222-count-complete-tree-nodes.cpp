void county(TreeNode* root, int& count) { 
    if (root == nullptr) return;
    count++;
    county(root->left, count);
    county(root->right, count);
}

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int count = 0; 
        county(root, count); 
        return count; 
    }
};
