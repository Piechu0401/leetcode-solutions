class Solution {
public:
    inline const vector<int> sequentialDigits(
        const int& __l, 
        const int& __h
    ) const noexcept {
        auto __len = [](
            int __n
        ) -> char {
            char __res{};
            while( __n ) { __n /= 10; ++__res; }
            return __res;

        };

        vector<int> __res;

        for( int __i = __len( __l ); __i <= __len(__h); ++__i ) {
            long __n{};
            long __add{};

            for( int __j{}; __j < __i; ++__j ) {
                __n = __n * 10 + (__j + 1);
                __add = __add * 10 + 1;

            }

            while( __n % 10 != 9 ) {
                if( __n >= __l && __n <= __h ) {
                    __res.emplace_back( __n );
                    // cout << __n << " " << __add << "\n";

                }
                __n += __add;

            }

            if( __n >= __l && __n <= __h )
                __res.emplace_back( __n );
            else if( __n > __h ) break;

        }

        return __res;
        
    }
};