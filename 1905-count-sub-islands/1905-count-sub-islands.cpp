class Solution {
public:
    inline const int countSubIslands(
        const vector<vector<int>>& __g1, 
        const vector<vector<int>>& __g2
    ) const noexcept {
        int __res{};
        vector<char> __used( __g2.size() * __g2.front().size(), 0 );

        for( short __i{}; __i < __g2.size(); ++__i )
            for( short __j{}; __j < __g2.front().size(); ++__j ) {
                if(
                    !__g2[__i][__j] ||
                    __used[__i * __g2.front().size() + __j]
                ) continue;

                char __inc{1};
                queue<pair<short, short>> __q;
                __q.push( { __i, __j } );
                __used[__i * __g2.front().size() + __j] = 1;

                while( !__q.empty() ) {
                    short __y{ __q.front().first };
                    short __x{ __q.front().second };

                    if(
                        __g2[__y][__x] &&
                        !__g1[__y][__x]
                    ) __inc = 0;

                    if(
                        __x - 1 > -1 &&
                        !__used[__y * __g2.front().size() + __x - 1] &&
                        __g2[__y][__x - 1]
                    ) {
                        __used[__y * __g2.front().size() + __x - 1] = 1;
                        __q.push( { __y, __x - 1 } );

                    }

                    if(
                        __x + 1 < __g2.front().size() &&
                        !__used[__y * __g2.front().size() + __x + 1] &&
                        __g2[__y][__x + 1]
                    ) {
                        __used[__y * __g2.front().size() + __x + 1] = 1;
                        __q.push( { __y, __x + 1 } );

                    }

                    if(
                        __y - 1 > -1 &&
                        !__used[( __y - 1 ) * __g2.front().size() + __x] &&
                        __g2[__y - 1][__x]
                    ) {
                        __used[( __y - 1 ) * __g2.front().size() + __x] = 1;
                        __q.push( { __y - 1, __x } );

                    }

                    if(
                        __y + 1 < __g2.size() &&
                        !__used[( __y + 1 ) * __g2.front().size() + __x] &&
                        __g2[__y + 1][__x]
                    ) {
                        __used[( __y + 1 ) * __g2.front().size() + __x] = 1;
                        __q.push( { __y + 1, __x } );

                    }

                    __q.pop();

                }

                if( __inc ) ++__res;

            }

        return __res;

    }
};