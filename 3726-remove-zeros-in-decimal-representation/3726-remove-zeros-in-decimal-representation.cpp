class Solution {
public:
    inline const long long removeZeros(
        long long& __n
    ) const noexcept {
        long long __res{};
        long long __p{1LL};

        while( __n ) {
            if( __n % 10LL ) { 
                // cout << ( __n % 10LL ) << "\n";

                __res += __p * ( __n % 10LL );
                __p *= 10LL;

            }
            
            __n /= 10LL;

        }

        return __res;
        
    }
};