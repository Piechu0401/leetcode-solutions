class Solution {
public:
    inline const vector<string> createGrid(
        const int& __m, 
        const int& __n
    ) const noexcept {
        vector<string> __res(
            __m,
            string( __n, '#' )
        );

        __res.front() = string( __n, '.' );

        for( char __i{1}; __i < __m; ++__i )
            __res[__i].back() = '.';

        return __res;
        
    }
};