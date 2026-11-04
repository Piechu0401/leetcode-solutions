class Solution {
public:
    inline const int minChanges(
        string& __s
    ) const noexcept {
        int __res{};

        for( int __i{}; __i < __s.length(); __i += 2 )
            __res += ( __s[__i] != __s[__i + 1] );

        return __res;
        
    }
};