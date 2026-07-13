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
    inline void mergeFuckers(
        vector<int>& __ns,
        const int& __l,
        const int& __r,
        const int& __m        
    ) const noexcept {
        const int __n1{ __m - __l + 1 };
        const int __n2{ __r - __m };

        vector<int> __left( __n1, 0 );
        vector<int> __right( __n2, 0 );

        int __i{};
        int __j{};
        int __k{ __l };

        for( __i = __i; __i < __n1; ++__i )
            __left[__i] = __ns[__l + __i];
        
        for( __j = __j; __j < __n2; ++__j )
            __right[__j] = __ns[__m + __j + 1];

        __i = 0;
        __j = 0;

        while(
            __i < __n1 &&
            __j < __n2
        ) {
            if( __left[__i] <= __right[__j] ) {
                __ns[__k] = __left[__i];
                ++__i;

            }
            else {
                __ns[__k] = __right[__j];
                ++__j;

            }

            ++__k;

        }

        while( __i < __n1 ) {
            __ns[__k] = __left[__i];
            ++__i;
            ++__k;

        }

        while( __j < __n2 ) {
            __ns[__k] = __right[__j];
            ++__j;
            ++__k;

        }

    }

    inline void doTheTrick(
        vector<int>& __ns,
        const int& __l,
        const int& __r
    ) const noexcept {
        if( __l >= __r ) return;

        doTheTrick(
            __ns,
            __l,
            __l + ( ( __r - __l ) >> 1 )
        );

        doTheTrick(
            __ns,
            __l + ( ( __r - __l ) >> 1 ) + 1,
            __r
        );

        mergeFuckers(
            __ns,
            __l,
            __r,
            __l + ( ( __r - __l ) >> 1 )        
        );

    }

    inline ListNode* sortList(
        ListNode* __h
    ) const noexcept {
        if( !__h ) return __h;

        int __s{};
        vector<int> __v;

        while( __h ) {
            __v.emplace_back( __h->val );
            __h = __h->next;

        }      

        doTheTrick(
            __v,
            0,
            __v.size() - 1lu
        );

        ListNode* __res = new ListNode( __v.front() );
        ListNode* __temp{ __res };

        for( int __i{1}; __i < __v.size(); ++__i ) {
            __temp->next = new ListNode( __v[__i] );
            __temp = __temp->next;

        }

        return __res;

    }
};