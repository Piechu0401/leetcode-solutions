/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    inline bool doTheTrick(
        ListNode*   __h, 
        TreeNode*   __r
    ) const noexcept {
        if( !__h ) return 1;
        else if( !__r || __r->val != __h->val ) return 0;

        return
            doTheTrick(
                __h->next,
                __r->left
            ) ||
            doTheTrick(
                __h->next,
                __r->right
            );       

    }

    inline void search(
        ListNode*   __h, 
        TreeNode*   __r,
        bool&       __res        
    ) const noexcept {
        if( __res || !__r ) return;

        if( __r->val == __h->val )
            __res = 
                __res || 
                doTheTrick(
                    __h,
                    __r
                );

        search(
            __h,
            __r->left,
            __res
        );

        search(
            __h,
            __r->right,
            __res
        );

    }

    inline const bool isSubPath(
        ListNode* __h, 
        TreeNode* __r
    ) const noexcept {
        bool __res{};

        search(
            __h,
            __r,
            __res
        );

        return __res;
        
    }
};