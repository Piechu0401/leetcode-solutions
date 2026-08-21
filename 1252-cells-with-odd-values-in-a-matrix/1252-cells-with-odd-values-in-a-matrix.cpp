class Solution {
public:
    inline const int oddCells(
        const int& __m, 
        const int& __n, 
        const vector<vector<int>>& __is
    ) const noexcept {
        int __res{};
        vector<int> __rs( __m, 0 );
        vector<int> __cs( __n, 0 );

        for( auto& __i : __is ) {
            ++__rs[__i[0]];
            ++__cs[__i[1]];

        }

        for( char __i{}; __i < __m; ++__i )
            for( char __j{}; __j < __n; ++__j )
                __res += ( __rs[__i] + __cs[__j] ) & 1;
            
        return __res;

    }
};