class Solution {
public:
    inline const vector<vector<int>> differenceOfDistinctValues(
        const vector<vector<int>>& __g
    ) const noexcept {
        vector<vector<int>> __res(
            __g.size(),
            vector<int>( __g.front().size() )
        );

        for( char __i{}; __i < __g.size(); ++__i )
            for( char __j{}; __j < __g.front().size(); ++__j ) {
                char __l{1};
                char __left[50]{};
                char __right[50]{};

                while(
                    (__i - __l > -1 &&
                    __j - __l > -1) ||
                    (__i + __l < __g.size() &&
                    __j + __l < __g.front().size())
                ) {
                    if(
                        __i - __l > -1 &&
                        __j - __l > -1
                    ) if( !__left[__g[__i - __l][__j - __l] - 1] )
                        __left[__g[__i - __l][__j - __l] - 1] = 1;

                    if(
                        __i + __l < __g.size() &&
                        __j + __l < __g.front().size()
                    ) if( !__right[__g[__i + __l][__j + __l] - 1] )
                        __right[__g[__i + __l][__j + __l] - 1] = 1;

                    ++__l;

                }

                for( char __idx{}; __idx < 50; ++__idx )
                    if( __left[__idx] ^ __right[__idx] )
                        __res[__i][__j] += (
                            __left[__idx] ? 1 : -1
                        );

                __res[__i][__j] = (
                    __res[__i][__j] < 0 ?\
                    -__res[__i][__j] :\
                    __res[__i][__j]
                );

            }

        return __res;
        
    }
};