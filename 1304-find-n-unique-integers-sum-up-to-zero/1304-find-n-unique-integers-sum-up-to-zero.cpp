class Solution {
public:
    inline const vector<int> sumZero(
        const int& __n
    ) const noexcept {
        vector<int> __res;

        if( __n & 1 ) __res.emplace_back(0);

        for( short __i{1}; __i <= ( __n >> 1 ); ++__i ) {
            __res.emplace_back( __i );
            __res.emplace_back( -__i );

        }

        return __res;

    }
};