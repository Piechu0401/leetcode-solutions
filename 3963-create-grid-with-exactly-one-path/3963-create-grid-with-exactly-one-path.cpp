class Solution {
public:
    inline const vector<string> createGrid(
        const int& __m, 
        const int& __n
    ) const noexcept {
        vector<string> __res;
        string __load( __n - 1, '#' );
        __load += '.';

        __res.push_back( string( __n, '.' ) );

        for( char __i{}; __i < __m - 1; ++__i ) __res.emplace_back( __load );

        return __res;
        
    }
};