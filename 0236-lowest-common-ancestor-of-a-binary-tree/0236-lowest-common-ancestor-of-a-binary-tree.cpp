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
    inline const bool isHere(
        TreeNode* __r,
        const int& __v
    ) const noexcept {
        if( !__r ) return 0;
        else if( __r->val == __v ) return 1;

        return
            isHere(
                __r->left,
                __v
            ) ||
            isHere(
                __r->right,
                __v
            );

    }

    inline void doTheTrick(
        TreeNode** __res,
        TreeNode* __r, 
        const int& __v1, 
        const int& __v2
    ) const noexcept {
        if( !__r ) return;

        bool __b1{};
        bool __b2{};

        if( __r->left && __r->right ) {
            __b1 = isHere(
                __r->left,
                __v1
            );

            __b2 = isHere(
                __r->right,
                __v2
            );

            if( 
                (
                    ( !__b1 && !__b2 ) ||
                    ( __b1 && __b2 ) ||
                    ( !__b1 && __r->val == __v1 ) ||
                    ( !__b2 && __r->val == __v2 )
                )
            ) {
                *__res = __r;
                // cout << __r->val << "\n";
                return;

            }
            else if( __b1 ) 
                doTheTrick(
                    __res,
                    __r->left, 
                    __v1, 
                    __v2
                );
            else
                doTheTrick(
                    __res,
                    __r->right, 
                    __v1, 
                    __v2
                );

        }
        else {
            if( 
                __r->val == __v1 ||
                __r->val == __v2
            ) {
                *__res = __r;
                return;

            }

            if( __r->left )
                doTheTrick(
                    __res,
                    __r->left, 
                    __v1, 
                    __v2
                );
            else
                doTheTrick(
                    __res,
                    __r->right, 
                    __v1, 
                    __v2
                );

        }

    }

    inline TreeNode* lowestCommonAncestor(
        TreeNode* __r, 
        TreeNode* __p, 
        TreeNode* __q
    ) const noexcept {
        TreeNode* __res(0);

        doTheTrick(
            &__res,
            __r, 
            __p->val, 
            __q->val
        );

        return __res;

    }
};