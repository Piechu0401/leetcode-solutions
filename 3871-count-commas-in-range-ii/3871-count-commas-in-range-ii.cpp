class Solution {
public:
    inline const long long countCommas(
        long long& __n
    ) const noexcept {
        return
            ( __n - 999LL > 0 ? __n - 999LL : 0LL ) +
            ( __n - 999999LL > 0 ? __n - 999999LL : 0LL ) +
            ( __n - 999999999LL > 0 ? __n - 999999999LL : 0LL ) +
            ( __n - 999999999999LL > 0 ? __n - 999999999999LL : 0LL ) +
            ( __n - 999999999999999LL > 0 ? __n - 999999999999999LL : 0LL );
        
    }
};