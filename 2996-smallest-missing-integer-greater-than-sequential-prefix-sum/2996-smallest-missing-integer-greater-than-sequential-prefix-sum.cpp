class Solution {
public:
    inline const int missingInteger(
        const vector<int>& __ns
    ) const noexcept {
        char __nums[50]{};
        short __res = __ns.front();
        char __fuckOff{};

        for( char __i{1}; __i < __ns.size(); ++__i ) {
            if( !__fuckOff && __ns[__i] - __ns[__i - 1] == 1 ) __res += __ns[__i];
            else __fuckOff = 1;

            ++__nums[__ns[__i - 1] - 1];

        }

        ++__nums[__ns.back() - 1];

        // cout << __res;

        while( __res < 51 && __nums[__res - 1] ) ++__res;

        return __res;
        
    }
};