class Solution {
public:
    inline const int duplicateNumbersXOR(
        vector<int>& __ns
    ) const noexcept {
        int __res{};
        unordered_map<int, int> __um;

        for( auto& __n : __ns ) if( ++__um[__n] == 2 ) __res ^= __n;

        return __res;
        
    }
};