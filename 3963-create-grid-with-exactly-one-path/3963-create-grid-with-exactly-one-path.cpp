class Solution {
public:
    inline const vector<string> createGrid(
        const int& __m, 
        const int& __n
    ) const noexcept {
        vector<string> __res(
            __m,
            string( __n - 1, '#' ) + "."
        );

        __res.front() = string( __n, '.' );

        return __res;
        
    }
};