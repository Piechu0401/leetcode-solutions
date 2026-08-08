class Solution {
public:
    inline const vector<long long> findPrefixScore(
        const vector<int>& __ns
    ) const noexcept {
        vector<long long> __res( __ns.size(), 0 );
        int __max{};

        for( int __i{}; __i < __ns.size(); ++__i ) {
            if( __ns[__i] > __max ) __max = __ns[__i];
            __res[__i] = __ns[__i] + __max;

        }

        for( int __i{1}; __i < __ns.size(); ++__i )
            __res[__i] += __res[__i - 1];

        return __res;

    }
};