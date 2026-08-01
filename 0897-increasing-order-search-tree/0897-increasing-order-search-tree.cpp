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
        vector<int>& __ns
    ) const noexcept {
        if( !__r ) return;

        doTheTrick(
            __r->left,
            __ns
        );

        __ns.emplace_back( __r->val );

        doTheTrick(
            __r->right,
            __ns
        );

    }

    inline TreeNode* increasingBST(
        TreeNode* __r
    ) const noexcept {
        if( !__r ) return nullptr;

        vector<int> __ns;

        doTheTrick(
            __r,
            __ns
        );

        // for( auto& __n : __ns ) cout << __n << " ";

        TreeNode* __res = new TreeNode( __ns.front() );
        TreeNode* __temp{__res};

        for( char __i{1}; __i < __ns.size(); ++__i ) {
            __temp->right = new TreeNode( __ns[__i] );
            __temp = __temp->right;

        }

        return __res;

    }
};