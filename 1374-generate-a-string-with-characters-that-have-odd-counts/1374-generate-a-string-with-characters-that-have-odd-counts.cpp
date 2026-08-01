class Solution {
public:
    inline const string generateTheString(
        const int& __n
    ) const noexcept {
        return ( !(__n & 1) ? string( __n - 1, 'a' ) + "b" : string( __n, 'a' ) );
        
    }
};