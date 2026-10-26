class Solution {
public:
    inline const int countIslands(
        vector<vector<int>>&    __g, 
        int&                    __k
    ) const noexcept {
        int             __res{};
        vector<char>    __used( __g.size() * __g[0].size(), 0 );

        for( short __i{}; __i < __g.size(); ++__i )
            for( short __j{}; __j < __g[0].size(); ++__j )
                if(
                    __g[__i][__j] &&
                    !__used[__i * __g[0].size() + __j]
                ) {
                    int                         __sum{};
                    queue<pair<short, short>>   __q;
                    __q.push( { __i, __j } );
                    __used[__i * __g[0].size() + __j] = 1;

                    while( __q.size() ) {
                        __sum = ( 
                            __sum + 
                            __g[__q.front().first][__q.front().second] 
                        ) % __k;

                        if(
                            __q.front().first - 1 > -1 &&
                            __g[__q.front().first - 1][__q.front().second] &&
                            !__used[( __q.front().first - 1 ) * __g[0].size() + __q.front().second]
                        ) {
                            __used[( __q.front().first - 1 ) * __g[0].size() + __q.front().second] = 1;
                            __q.push( { __q.front().first - 1, __q.front().second } );

                        }

                        if(
                            __q.front().first + 1 < __g.size() &&
                            __g[__q.front().first + 1][__q.front().second] &&
                            !__used[( __q.front().first + 1 ) * __g[0].size() + __q.front().second]
                        ) {
                            __used[( __q.front().first + 1 ) * __g[0].size() + __q.front().second] = 1;
                            __q.push( { __q.front().first + 1, __q.front().second } );

                        }

                        if(
                            __q.front().second - 1 > -1 &&
                            __g[__q.front().first][__q.front().second - 1] &&
                            !__used[__q.front().first * __g[0].size() + __q.front().second - 1]
                        ) {
                            __used[__q.front().first * __g[0].size() + __q.front().second - 1] = 1;
                            __q.push( { __q.front().first, __q.front().second - 1 } );

                        }

                        if(
                            __q.front().second + 1 < __g[0].size() &&
                            __g[__q.front().first][__q.front().second + 1] &&
                            !__used[__q.front().first * __g[0].size() + __q.front().second + 1]
                        ) {
                            __used[__q.front().first * __g[0].size() + __q.front().second + 1] = 1;
                            __q.push( { __q.front().first, __q.front().second + 1 } );

                        }

                        __q.pop();

                    }

                    __res += !__sum;

                }

        return __res;
        
    }
};