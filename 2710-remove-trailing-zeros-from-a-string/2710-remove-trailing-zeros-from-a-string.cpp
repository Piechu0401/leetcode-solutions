class Solution {
public:
    inline const string removeTrailingZeros(
        const string& __n
    ) const noexcept {
        short __i = __n.length() - 1;

        while(
            __i > -1 &&
            !( __n[__i] - 48 )
        ) --__i;

        return ( __i == -1 ? "" : __n.substr( 0, __i + 1 ) );
        
    }
};