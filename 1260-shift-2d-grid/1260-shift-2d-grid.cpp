class Solution {
public:
    inline const vector<vector<int>> shiftGrid(
        vector<vector<int>>& __g, 
        int& __k
    ) {
        deque<short> __cpy;

        for( auto& __v : __g )
            for( auto& __n : __v ) __cpy.emplace_back( __n );

        __k %= ( __g.size() * __g.front().size() );

        while( __k ) {
            __cpy.emplace_front( __cpy.back() );
            __cpy.pop_back();
            --__k;

        }

        for( auto& __v : __g )
            for( auto& __n : __v ) {
                __n = __cpy[__k];
                ++__k;

            }

        return __g;

    }
};