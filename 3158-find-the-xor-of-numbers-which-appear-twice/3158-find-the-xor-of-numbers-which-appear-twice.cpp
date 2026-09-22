class Solution {
public:
    inline const int duplicateNumbersXOR(
        vector<int>& __ns
    ) const noexcept {
        int     __res{};
        char    __vals[50]{};

        for( auto& __n : __ns ) if( ++__vals[__n - 1] == 2 ) __res ^= __n;

        return __res;
        
    }
};