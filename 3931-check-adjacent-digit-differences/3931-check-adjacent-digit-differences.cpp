class Solution {
public:
    inline const bool isAdjacentDiffAtMostTwo(
        const string& __s
    ) const noexcept {
        char __res{};
        
        for( char __i{}; __i < __s.length() - 1; ++__i )
            if( abs( __s[__i] - __s[__i + 1] ) > 2 ) return 0;

        return 1;

    }
};