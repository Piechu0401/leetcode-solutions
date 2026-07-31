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
class Solution {
public:
    inline ListNode* partition(
        ListNode*   __h, 
        const int&  __x
    ) const noexcept {
        if( !__h ) return __h;
        
        ListNode* __beg = new ListNode(0);
        ListNode* __end = new ListNode(0);
        ListNode* __tempBeg{__beg};
        ListNode* __tempEnd{__end};

        while( __h ) {
            if( __h->val < __x ) {
                __tempBeg->next = new ListNode( __h->val );
                __tempBeg = __tempBeg->next;

            }
            else {
                __tempEnd->next = new ListNode( __h->val );
                __tempEnd = __tempEnd->next;

            }

            __h = __h->next;

        }

        __beg = __beg->next;
        __end = __end->next;

        if( !__beg ) return __end;
        else if( !__end ) return __beg;

        __tempBeg = __beg;

        while( __tempBeg->next ) __tempBeg = __tempBeg->next;

        __tempBeg->next = __end;

        return __beg;

    }

};