class Solution {
public:
    inline const int maxNumberOfFamilies(
        const int& __n, 
        const vector<vector<int>>& __rss
    ) const noexcept {
        int __res{};
        unordered_map<int, short> __um;

        for( auto& __rs : __rss ) __um[__rs[0]] += ( 1 << ( __rs[1] - 1 ) );

        // 2 + 4 + 8 + 16 = 30
        // 8 + 16 + 32 + 64 = 120
        // 32 + 64 + 128 + 256 = 480

        for( auto& __e : __um )
            if( !( __e.second & 30 ) && !( __e.second & 480 ) ) __res += 2;
            else if( !( __e.second & 30 ) || !( __e.second & 120 ) || !( __e.second & 480 ) ) ++__res;

        return __res + ( ( __n - __um.size() ) << 1 );
        
    }
};

// 1    _ # # _ # # # # _ #
// 2    _ # # # # _ _ _ _ #