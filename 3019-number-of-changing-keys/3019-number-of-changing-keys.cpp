class Solution {
public:
    inline const int countKeyChanges(
        const string& __s
    ) const noexcept {
        int __res{};

        for( char __i{}; __i < __s.length() - 1; ++__i )
            if( 
                ( __s[__i] > 90 ? __s[__i] - 32 : __s[__i] ) !=
                ( __s[__i + 1] > 90 ? __s[__i + 1] - 32 : __s[__i + 1] )
            ) ++__res;

        return __res;
        
    }
};