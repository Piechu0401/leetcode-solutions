class Solution {
public:
    inline const long long zeroFilledSubarray(
        const vector<int>& __ns
    ) const noexcept {
        long long __res{};
        int __count{};

        for( auto& __n : __ns ) {
            if( __n ) { __count = 0; continue; }

            ++__count;
            __res += __count;

        }

        return __res;
        
    }
};