class Solution {
public:
    inline const int numEnclaves(
        const vector<vector<int>>& __g
    ) const noexcept {
        vector<char> __used( __g.size() * __g.front().size(), 0 );
        int __res{};

        for( short __i{1}; __i < __g.size() - 1; ++__i )
            for( short __j{1}; __j < __g.front().size() - 1; ++__j ) {
                // cout << __i << " " << __j << "\n";
                
                if(
                    !__g[__i][__j] ||
                    __used[__i * __g.front().size() + __j]
                ) continue;

                int __count{1};
                char __add{};
                queue<pair<int, int>> __q;
                // queue<pair<int, int>> __temp;
                __q.push( { __i, __j } );
                // __temp.push( { __i, __j } );
                __used[__i * __g.front().size() + __j] = 1;

                while( !__q.empty() ) {
                    short __y = __q.front().first;
                    short __x = __q.front().second;

                    if(
                        !__y ||
                        !__x ||
                        __y == __g.size() - 1 ||
                        __x == __g.front().size() - 1
                    ) __add = 1;

                    if(
                        __x - 1 > -1 &&
                        __g[__y][__x - 1] &&
                        !__used[__y * __g.front().size() + __x - 1]
                    ) {
                        ++__used[__y * __g.front().size() + __x - 1];
                        __q.push( { __y, __x - 1 } );
                        // __temp.push( { __y, __x - 1 } );
                        ++__count;

                    }

                    if(
                        __x + 1 < __g.front().size() &&
                        __g[__y][__x + 1] &&
                        !__used[__y * __g.front().size() + __x + 1]
                    ) {
                        ++__used[__y * __g.front().size() + __x + 1];
                        __q.push( { __y, __x + 1 } );
                        // __temp.push( { __y, __x + 1 } );
                        ++__count;

                    }

                    if(
                        __y - 1 > -1 &&
                        __g[__y - 1][__x] &&
                        !__used[( __y - 1 ) * __g.front().size() + __x]
                    ) {
                        ++__used[( __y - 1 ) * __g.front().size() + __x];
                        __q.push( { __y - 1, __x } );
                        // __temp.push( { __y - 1, __x } );
                        ++__count;

                    }

                    if(
                        __y + 1 < __g.size() &&
                        __g[__y + 1][__x] &&
                        !__used[( __y + 1 ) * __g.front().size() + __x]
                    ) {
                        ++__used[( __y + 1 ) * __g.front().size() + __x];
                        __q.push( { __y + 1, __x } );
                        // __temp.push( { __y + 1, __x } );
                        ++__count;

                    }
                
                    __q.pop();

                }

                if( !__add ) {
                    // while( !__temp.empty() ) {
                    //     __used[__temp.front().first * __g.front().size() + __temp.front().second] = 2;
                    //     __temp.pop();
                    // 
                    // }

                    __res += __count;
                    // cout << __i << " " << __j << "\n";
                    
                }

            }

                // for( short __i{}; __i < __g.size(); ++__i ) {
                //     for( short __j{}; __j < __g.front().size(); ++__j ) 
                //         cout << (int)__used[__i * __g.front().size() + __j] << " ";
                //     cout << "\n";
                // 
                // }

        return __res;

    }
};

// 0 1 1 0 0 0 0 1 1 0 0 0
// 1 0 1 1 1 0 1 0 1 1 1 0
// 1 1 0 1 0 0 1 1 0 1 1 1
// 1 0 0 1 1 0 1 0 1 0 1 0
// 1 0 0 0 0 1 0 0 1 1 0 1
// 1 1 1 0 0 0 1 0 0 1 1 1
// 1 1 1 0 0 0 0 1 0 1 0 1
// 0 1 1 1 1 0 0 1 1 0 0 0
// 0 1 0 1 0 1 0 1 0 0 0 1
// 0 0 1 0 1 1 0 0 0 1 1 1