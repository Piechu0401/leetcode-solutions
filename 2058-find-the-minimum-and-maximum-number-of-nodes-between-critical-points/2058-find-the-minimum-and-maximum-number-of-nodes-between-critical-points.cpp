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
    inline const vector<int> nodesBetweenCriticalPoints(
        ListNode* __h
    ) const noexcept {
        ListNode* __temp = __h->next;
        int __prev{__h->val};
        int __prevI{-1};
        int __first{-1};
        int __i{1};
        int __min{INT_MAX};

        while( __temp->next ) {
            if( 
                (__prev < __temp->val &&
                __temp->next->val < __temp->val) ||
                (__prev > __temp->val &&
                __temp->next->val > __temp->val)
            ) {
                if( __prevI != -1 ) {
                    if( __i - __prevI < __min )
                        __min = __i - __prevI;
                    
                } else __first = __i;

                __prevI = __i;

            }
            ++__i;
            __prev = __temp->val;
            __temp = __temp->next;

        }

        if( 
            __min == INT_MAX && 
            !(__prevI - __first) 
        ) return {-1, -1};

        return { __min, __prevI - __first };

    }
};