class Solution {
public:
    inline const int minOperations(
        vector<int>& __ns
    ) const noexcept {
        int __res{};

        for( short __i{1}; __i < __ns.size(); ++__i )
            if( __ns[__i - 1] >= __ns[__i] ) {
                __res += __ns[__i - 1] + 1 - __ns[__i];
                __ns[__i] = __ns[__i - 1] + 1;

            }

        return __res;
        
    }
};