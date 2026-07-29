class Solution {
public:
    inline const int minAllOneMultiple(
        const int& __k
    ) const noexcept {
        if( !(__k & 1) || !(__k % 5) ) return -1;

        int __i{1};
        int __res{1};

        while( __res ) {
            __res = ( __res * 10 + 1 ) % __k;
            ++__i;
            
        }

        return __i;
        
    }
};