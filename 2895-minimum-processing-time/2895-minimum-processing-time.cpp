class Solution {
public:
    inline const int minProcessingTime(
        vector<int>& __pt, 
        vector<int>& __ts
    ) const noexcept {
        int __res{};
        sort( __pt.begin(), __pt.end() );
        sort( __ts.begin(), __ts.end() );

        for( int __i{}; __i < __pt.size(); ++__i )
            __res = max(
                __res,
                max(
                    {
                        __ts[__ts.size() - 1 - ( __i << 2 )] + __pt[__i],
                        __ts[__ts.size() - 2 - ( __i << 2 )] + __pt[__i],
                        __ts[__ts.size() - 3 - ( __i << 2 )] + __pt[__i],
                        __ts[__ts.size() - 4 - ( __i << 2 )] + __pt[__i]
                    }
                )   
            );

        return __res;

    }
};