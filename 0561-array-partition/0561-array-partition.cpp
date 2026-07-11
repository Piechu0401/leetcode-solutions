class Solution {
public:
    inline const int arrayPairSum(
        vector<int>& __ns
    ) const noexcept {
        int __res{};

        sort( __ns.begin(), __ns.end() );

        for( int __i{}; __i < __ns.size(); __i += 2 )
            __res += __ns[__i] < __ns[__i + 1] ? __ns[__i] : __ns[__i + 1];

        return __res;
        
    }
};

// 1 2 3 4

// 1 2 2 5 6 6