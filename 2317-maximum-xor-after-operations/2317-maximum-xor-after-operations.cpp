class Solution {
public:
    inline const int maximumXOR(
        const vector<int>& __ns
    ) const noexcept {
        int __res{};
        int __p{1};
        int __max{};

        for( auto& __n : __ns ) __max = ( __max < __n ? __n : __max );

        while( __p <= __max ) {
            char __is{};

            for( auto& __n : __ns ) if( __n & __p ) __is = 1;

            if( __is ) __res += __p;

            __p <<= 1;

        }

        return __res;
        
    }
};

// 0001
// 0010
// 0011
// 1001
// 0010