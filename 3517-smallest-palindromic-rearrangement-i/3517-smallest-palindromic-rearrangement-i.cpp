class Solution {
public:
    inline const string smallestPalindrome(
        string& __s
    ) const noexcept {
        sort( __s.begin(), __s.begin() + ( __s.length() >> 1 ) );

        for( int __i{}; __i < ( __s.length() >> 1 ); ++__i )
            __s[__s.length() - 1 - __i] = __s[__i];

        return __s;

    }
};