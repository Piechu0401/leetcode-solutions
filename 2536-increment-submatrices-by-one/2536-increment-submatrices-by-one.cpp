class Solution {
public:
    inline const vector<vector<int>> rangeAddQueries(
        const int&              __n, 
        vector<vector<int>>&    __qs
    ) const noexcept {
        vector<vector<int>> __res( __n, vector<int>( __n, 0 ) );
        
        for( auto& __q : __qs )
            for( short __i = __q[0]; __i <= __q[2]; ++__i ) {
                ++__res[__i][__q[1]];
                if( __q[3] + 1 < __n )
                    --__res[__i][__q[3] + 1];
                
            }

        for( short __i{}; __i < __n; ++__i )
            for( short __j{1}; __j < __n; ++__j )
                __res[__i][__j] += __res[__i][__j - 1];

        return __res;

    }
};