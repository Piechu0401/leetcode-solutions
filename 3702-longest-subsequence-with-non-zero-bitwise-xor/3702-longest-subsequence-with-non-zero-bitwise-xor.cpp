class Solution {
public:
    inline const int longestSubsequence(
        vector<int>& __ns
    ) const noexcept {
        int __xor{};
        int __res{};
        int __zero{};

        for( auto& __n : __ns ) {
            __xor ^= __n;
            __zero += ( !__n ? 1 : 0 );

        }

        if( __xor ) return __ns.size();
        else if( __zero == __ns.size() ) return 0;

        return __ns.size() - 1;
        
    }
};

// 001
// 010
// 011