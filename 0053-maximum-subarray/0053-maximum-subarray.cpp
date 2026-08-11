class Solution {
public:
    inline const int maxSubArray(
        const vector<int>& __ns
    ) const noexcept {
        int __res{__ns.front()};
        int __sum{};

        for( int __i{}; __i < __ns.size(); ++__i ) {
            if( __sum < 0 ) __sum = 0;

            __sum += __ns[__i];
            __res = ( __res > __sum ? __res : __sum );

        }

        return __res;
        
    }
};

// -2, 1, -3, 4, -1, 2, 1, -5, 4
// -2, -1, -4, 0, -1, 1, 2, -3, 1