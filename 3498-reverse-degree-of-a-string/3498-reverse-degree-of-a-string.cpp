class Solution {
public:
    inline const int reverseDegree(
        string& __s
    ) const noexcept {
        int __res{};

        for( short __i{}; __i < __s.length(); ++__i ) 
            __res += ( __i + 1 ) * ( 123 - __s[__i] );

        return __res;
        
    }
};