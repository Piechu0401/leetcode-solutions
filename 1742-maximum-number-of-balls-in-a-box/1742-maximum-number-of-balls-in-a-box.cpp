class Solution {
public:
    inline const int countBalls(
        int& __ll, 
        int& __hl
    ) const noexcept {
        int __res{};
        unordered_map<char, int> __um;

        for( __ll = __ll; __ll <= __hl; ++__ll ) {
            int __curr{__ll};
            char __sum{};

            while( __curr ) {
                __sum += __curr % 10;
                __curr /= 10;

            }

            if( ++__um[__sum] > __res ) __res = __um[__sum];

        }

        return __res;
        
    }
};