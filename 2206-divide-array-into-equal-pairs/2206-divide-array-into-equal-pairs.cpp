class Solution {
public:
    inline const bool divideArray(
        const vector<int>& __ns
    ) const noexcept {
        short __nums[500]{};

        for( auto& __n : __ns ) ++__nums[__n - 1];
        
        for( short __i{}; __i < 500; ++__i )
            if( __nums[__i] & 1 ) return 0;

        return 1;

    }
};