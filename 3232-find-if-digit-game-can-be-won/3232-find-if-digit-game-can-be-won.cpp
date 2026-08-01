class Solution {
public:
    inline const bool canAliceWin(
        const vector<int>& __ns
    ) const noexcept {
        int __st{};
        int __at{};

        for( auto& __n : __ns )
            if( __n < 10 ) __st += __n;
            else __at += __n;

        return __at != __st;
        
    }
};