class Solution {
public:
    inline const int maxVowels(
        const string& __s, 
        const int& __k
    ) const noexcept {
        int __max{};
        int __c{};
        deque<char> __dq;

        for( int __i{}; __i < __k; ++__i ) {
            if(
                __s[__i] == 'a' ||
                __s[__i] == 'e' ||
                __s[__i] == 'i' ||
                __s[__i] == 'o' ||
                __s[__i] == 'u'
            ) ++__c;
            
            __dq.emplace_back( __s[__i] );

        }

        __max = __c;

        for( int __i = __k; __i < __s.length(); ++__i ) {
            if( 
                __dq.front() == 'a' ||
                __dq.front() == 'e' ||
                __dq.front() == 'i' ||
                __dq.front() == 'o' ||
                __dq.front() == 'u' 
            ) --__c;

            __dq.pop_front();

            if( 
                __s[__i] == 'a' ||
                __s[__i] == 'e' ||
                __s[__i] == 'i' ||
                __s[__i] == 'o' ||
                __s[__i] == 'u' 
            ) ++__c;

            if( __c > __max ) __max = __c;

            __dq.emplace_back( __s[__i] );

        }

        return __max;

    }
};