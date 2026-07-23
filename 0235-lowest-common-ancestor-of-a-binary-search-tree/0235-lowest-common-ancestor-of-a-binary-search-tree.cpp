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
    inline void doTheTrick(
        TreeNode* __r,
        TreeNode** __res,
        const int& __L, 
        const int& __R
    ) const noexcept {
        if( !__r ) return;

        if(
            __r->val >= __L &&
            __r->val <= __R
        ) {
            *__res = __r;
            return;
            
        }

        if( __r->val > __R )
            doTheTrick(
                __r->left,
                __res,
                __L, 
                __R
            );
        else if( __r->val < __L )
            doTheTrick(
                __r->right,
                __res,
                __L, 
                __R
            );

    }

    inline TreeNode* lowestCommonAncestor(
        TreeNode* __r, 
        TreeNode* __p, 
        TreeNode* __q
    ) const noexcept {
        TreeNode* __res(0);

        doTheTrick(
            __r,
            &__res,
            __p->val < __q->val ? __p->val : __q->val, 
            __p->val > __q->val ? __p->val : __q->val
        );

        return __res;

    }
};