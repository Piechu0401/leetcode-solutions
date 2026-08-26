class Solution {
public:
    inline const long long countExcellentPairs(
        vector<int>&    __ns, 
        const int&      __k
    ) const noexcept {
        long long __res{};
        vector<int> __uq;
        unordered_map<int, int> __um;

        for( auto& __n : __ns ) {
            if( __um.count( __n ) ) continue;

            __uq.emplace_back( __n );

            long __p{1};

            while( __p <= __n ) {
                __um[__n] += ( ( __n & __p ) == __p );
                
                __p <<= 1;

            }

        }

        sort( 
            __uq.begin(), 
            __uq.end(),
            [&](
                const int& __a,
                const int& __b
            ) -> const bool { return __um[__a] < __um[__b]; }
        );

        for( int __i{}; __i < __uq.size(); ++__i ) {
            int __min{ __k - __um[__uq[__i]] };

            int __b{};
            int __e{ (int)__uq.size() - 1 };
            int __idx{-1};

            while( __b <= __e ) {
                int __mid{ __b + ( ( __e - __b ) >> 1 ) };

                if( __um[__uq[__mid]] >= __min ) { __idx = __mid; __e = --__mid; }
                else __b = ++__mid;

            }

            if( __idx != -1 ) {
                __res += abs( (int)( __uq.size() - __idx ) );
                // cout 
                //     << __uq[__i] << " " 
                //     << __uq[__idx] << " "
                //     << abs( (int)( __uq.size() - __idx ) ) << "\n";

            }

        }

        return __res;
        
    }
};

// 01010101011110000101010101010
// 10101010101000101111000101111
// 11111111111110101111010101111 or
// 00000000001000000101000101000 and