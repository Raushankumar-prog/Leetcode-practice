

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
       if (!root) return 0;

        std::queue<std::pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long leftMostPos = q.front().second;
            unsigned long long rightMostPos = q.back().second;
            maxWidth = std::max(maxWidth, static_cast<int>(rightMostPos - leftMostPos + 1));

            for (int i = 0; i < levelSize; ++i) {
                auto node = q.front().first;
                unsigned long long pos = q.front().second;
                q.pop();

                if (node->left) {
                    q.push({node->left, 2 * pos});
                }
                if (node->right) {
                    q.push({node->right, 2 * pos + 1});
                }
            }
        }
        return maxWidth;

    }
};