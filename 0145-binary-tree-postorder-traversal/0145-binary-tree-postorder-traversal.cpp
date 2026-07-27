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
    inline void doTheTrick(
        TreeNode* __r,
        vector<int>& __res
    ) const noexcept {
        if( !__r ) return;

        doTheTrick(
            __r->left,
            __res
        );

        doTheTrick(
            __r->right,
            __res
        );

        __res.emplace_back( __r->val );

    }

    inline const vector<int> postorderTraversal(
        TreeNode* __r
    ) const noexcept {
        vector<int> __res;

        doTheTrick(
            __r,
            __res
        );

        return __res;

    }
};