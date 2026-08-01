class Solution {
public:
    inline const string makeSmallestPalindrome(
        string& __s
    ) const noexcept {
        for( short __i{}; __i < ( __s.length() >> 1 ); ++__i )
            if( __s[__i] < __s[__s.length() - 1 - __i] )
                __s[__s.length() - 1 - __i] = __s[__i];
            else __s[__i] = __s[__s.length() - 1 - __i];

        return __s;

    }
};