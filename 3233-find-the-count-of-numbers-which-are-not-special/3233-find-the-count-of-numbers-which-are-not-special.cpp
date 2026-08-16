class Solution {
public:
    inline const int nonSpecialCount(
        const int& __l, 
        const int& __r
    ) const noexcept {
        int __primes{};
        int __sqrt = sqrt( __l );
        vector<char> __ns( sqrt( __r ), 0 );

        __ns.front() = 1;

        for( int __i{}; __i < __ns.size(); ++__i ) {
            if( __ns[__i] ) continue; 

            for( int __j = __i + __i + 1; __j < __ns.size(); __j += __i + 1 ) { 
                __ns[__j] = 1;
                // cout << __j << " ";

            }

            // cout << "\n";

            if( __l <= ( __i + 1 ) * ( __i + 1 ) && __r >= ( __i + 1 ) * ( __i + 1 ) )
                ++__primes;

        }

        return __r - __l + 1 - __primes;

    }
};