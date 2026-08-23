class Solution {
public:
    inline const bool xorGame(
        vector<int>& __ns
    ) {
        int __xor{};

        for( auto& __n : __ns ) __xor ^= __n;

        if( !__xor ) return 1;

        return !( __ns.size() & 1 );
        
    }
};

// 001
// 010
// 011