class Solution {
public:
    inline const int countValidPrefixes(
        const string __s
    ) const noexcept {
        int __res{};
        char __zeros{};

        for( char __i{}; __i < __s.length(); ++__i ) {
            __zeros += !(__s[__i] - 48);
            __res += ( abs( ( __zeros << 1 ) - __i - 1 ) < 2 ? 1 : 0 );

        }

        return __res;
        
    }
};