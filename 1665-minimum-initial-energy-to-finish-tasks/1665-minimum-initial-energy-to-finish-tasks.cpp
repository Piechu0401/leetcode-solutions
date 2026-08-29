class Solution {
public:
    inline const int minimumEffort(
        vector<vector<int>>& __ts
    ) const noexcept {
        int __res{};

        sort(
            __ts.begin(),
            __ts.end(),
            [](
                const vector<int>& __a,
                const vector<int>& __b
            ) -> const bool {
                return 
                    abs( __a[0] - __a[1] ) > abs( __b[0] - __b[1] );

            }
        );

        int __b{1};
        int __e{10000};

        while( __b <= __e ) {
            int __mid{ __b + ( ( __e - __b ) >> 1 ) };
            int __temp{__mid};
            char __valid{1};

            for( auto& __t : __ts )
                if( __temp >= __t[1] ) __temp -= __t[0];
                else { __valid = 0; break; }

            if( __valid ) { __res = __mid; __e = --__mid; }
            else __b = ++__mid;

        }

        // for( auto& __t : __ts )
        //     printf( "[%i, %i] ", __t[0], __t[1] );

        return __res;
        
    }
};

//   4      2       1       -
// [4,8], [2, 4], [1, 2]
//   12     6        3      +
//   8      4        2      sub of + -

//   2      2       1        2       1          -
// [1, 3], [2, 4], [10, 11], [10, 12], [8, 9]
//   4       6        21        22        18    +
//   2      4        20       20          19

//   6        6       6       6        6        6   -
// [5, 11], [2, 8], [3, 9], [1, 7], [4, 10], [6, 12]
//    16      10      12       8       14       18  +
//    10       4      6        2        8       12