class Solution {
public:
    inline const int maximizeSum(
        const vector<int>& __ns, 
        const int& __k
    ) const noexcept {
        int __max{};

        for( auto& __n : __ns ) __max = ( __max < __n ? __n : __max ); 
        
        return (int)( (double)( __max + __max + __k - 1 ) / 2.0 * __k );

    }
};