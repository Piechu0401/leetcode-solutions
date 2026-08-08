class Solution {
public:
    inline const vector<vector<int>> findWinners(
        vector<vector<int>>& __ms
    ) const noexcept {
        vector<vector<int>> __res(2);
        unordered_map<int, int> __ws;
        unordered_map<int, int> __ls;
        unordered_set<int> __unique;

        for( auto& __m : __ms ) {
            ++__ws[__m.front()];
            ++__ls[__m.back()];

            if( !__unique.count( __m.front() ) ) __unique.insert( __m.front() );
            if( !__unique.count( __m.back() ) ) __unique.insert( __m.back() );

        }

        for( auto& __u : __unique )
            if( __ls[__u] < __res.size() )
                __res[__ls[__u]].emplace_back( __u );

        sort( 
            __res.front().begin(), 
            __res.front().end()
        );
        sort( 
            __res.back().begin(), 
            __res.back().end()
        );

        return __res;

    }
};