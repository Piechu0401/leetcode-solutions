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
    inline const bool isPalindrome(
        ListNode* __h
    ) const noexcept { // fuck your O(1)
        if( !__h || !__h->next ) return 1; 
        
        deque<int> __dq;

        while( __h ) {
            __dq.emplace_back( __h->val );
            __h = __h->next;

        }

        while( __dq.size() > 1 && __dq.front() == __dq.back() ) {
            __dq.pop_front();
            __dq.pop_back();

        }

        if( __dq.size() ) __dq.pop_back();

        return !__dq.size();

    }
};