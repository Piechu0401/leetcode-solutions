class Solution {
public:
    inline const double averageWaitingTime(
        const vector<vector<int>>& __cs
    ) const noexcept {
        double __res{};
        int __t{};

        for( auto& __c : __cs ) {
            __t = ( __t < __c[0] ? __c[0] : __t );
            __t += __c[1]; 
            __res += __t - __c[0];

        }

        return __res / __cs.size();
        
    }
};