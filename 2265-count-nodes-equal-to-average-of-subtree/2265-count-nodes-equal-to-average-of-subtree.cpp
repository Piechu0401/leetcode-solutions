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
        const TreeNode* __r,
        int& __sum,
        int& __count
    ) {
        if( !__r ) return;

        ++__count;
        __sum += __r->val;

        doTheTrick(
            __r->left,
            __sum,
            __count
        );

        doTheTrick(
            __r->right,
            __sum,
            __count
        );

    }

    inline void goThroughTree(
        const TreeNode* __r,
        int& __res
    ) {
        if( !__r ) return;

        int __sum{0};
        int __count{0};

        doTheTrick(
            __r,
            __sum,
            __count
        );

        if( __sum / __count == __r->val ) ++__res;

        goThroughTree(
            __r->left,
            __res
        );

        goThroughTree(
            __r->right,
            __res
        );   

    };

    inline const int averageOfSubtree(
        const TreeNode* __r
    ) noexcept {
        int __res{0};

        goThroughTree(
            __r,
            __res
        );

        return __res;

    }
};