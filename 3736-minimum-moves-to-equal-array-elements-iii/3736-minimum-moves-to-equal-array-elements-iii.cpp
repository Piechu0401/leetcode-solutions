class Solution {
public:
    inline const int minMoves(
        const vector<int>& __ns
    ) const noexcept {
        int __max{};
        int __sum{};

        for( auto& __n : __ns ) {
            __max = __max < __n ? __n : __max;
            __sum += __n;

        }

        return __max * __ns.size() - __sum;
        
    }

};