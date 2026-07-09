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
    inline const int maxIdx(
        const vector<int>& __ns,
        const int& __b,
        const int& __e
    ) const noexcept {
        int __max{ INT_MIN };
        int __res{};

        for( int __i{__b}; __i < __e; ++__i )
            if( __ns[__i] >  __max ) {
                __max = __ns[__i];
                __res = __i;

            }

        return __res;

    }

    inline void doTheTrick(
        TreeNode* __r,
        const vector<int>& __ns,
        const int& __b,
        const int& __e
    ) const noexcept {
        if( __b >= __e || !__r ) return;

        const int __max{ 
            maxIdx(
                __ns,
                __b,
                __e
            ) 
        };

        //cout << __b << " " << __e << " " << __max << "\n";

        __r->val = __ns[__max];

        if( __b < __max ) {
            __r->left = new TreeNode(0);
            
            doTheTrick(
                __r->left,
                __ns,
                __b,
                __max
            );          

        }

        //cout << "LEFT: " << __b << " " << __e << "\n";

        if( __max + 1 < __e ) {
            __r->right = new TreeNode(0);
            
            doTheTrick(
                __r->right,
                __ns,
                __max + 1,
                __e
            );

        }

        //cout << "RIGHT: " << __b << " " << __e << "\n";

    }

    inline TreeNode* constructMaximumBinaryTree(
        const vector<int>& __ns
    ) const noexcept {
        TreeNode* __res = new TreeNode(0);
        
        doTheTrick(
            __res,
            __ns,
            0,
            __ns.size()
        );

        return __res;

    }
};