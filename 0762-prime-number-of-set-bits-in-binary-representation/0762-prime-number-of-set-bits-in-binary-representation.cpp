class Solution {
public:
    inline const int countPrimeSetBits(
        int& __l, 
        const int& __r
    ) const noexcept {
        int __res{};

        auto isPrime = [](
            const int& __n
        ) -> const bool {
            if( 
                __n == 2 ||
                __n == 3 ||
                __n == 5 ||
                __n == 7
            ) return 1;
            else if( !( __n & 1 ) || !__n || __n == 1 ) return 0;

            for( short __i{3}; __i <= ( __n >> 1 ); __i += 2 )
                if( !( __n % __i ) ) return 0;

            return 1;

        };

        while( __l <= __r ) {
            int __p{1};
            int __c{};

            while( __p <= __l ) {
                if( __l & __p ) ++__c;
                __p <<= 1;

            }

            // cout << __l << " " << __c << "\n";

            if( isPrime( __c ) ) ++__res;
            
            ++__l;

        }

        return __res;
        
    }
};