class Solution {
public:
    inline const int longestSubsequence(
        vector<int>& __ns
    ) const noexcept {
        if( __ns == vector<int>( __ns.size(), 0 ) ) return 0;

        int __xor{};
        int __res{};

        for( auto& __n : __ns ) __xor ^= __n;

        if( __xor ) return __ns.size();

        return __ns.size() - 1;
        
    }
};

// 001
// 010
// 011