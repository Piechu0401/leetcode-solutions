class Solution {
public:
    inline const vector<vector<int>> updateMatrix(
        vector<vector<int>>& __g
    ) const noexcept {
        queue<pair<pair<short, short>, short>> __q;
        vector<char> __visited( __g.size() * __g.front().size(), 0 );

        for( short __i{}; __i < __g.size(); ++__i )
            for( short __j{}; __j < __g.front().size(); ++__j ) 
                if( !__g[__i][__j] ) {
                    __q.push( { { __i, __j }, 0 } );
                    __visited[ __i * __g.front().size() + __j ] = 1;

                }

        while( !__q.empty() ) {
            const short __i{ __q.front().first.first };
            const short __j{ __q.front().first.second };
            const short __v{ __q.front().second  };

            if(
                __i - 1 > -1 &&
                !__visited[ (__i - 1) * __g.front().size() + __j ]
            ) {
                __g[__i - 1][__j] = __v + 1;
                __visited[ (__i - 1) * __g.front().size() + __j ] = 1;
                __q.push( { { __i - 1, __j }, __v + 1 } );

            }

            if(
                __i + 1 < __g.size() &&
                !__visited[ (__i + 1) * __g.front().size() + __j ]
            ) {
                __g[__i + 1][__j] = __v + 1;
                __visited[ (__i + 1) * __g.front().size() + __j ] = 1;
                __q.push( { { __i + 1, __j }, __v + 1 } );

            }
        
            if(
                __j - 1 > -1 &&
                !__visited[ __i * __g.front().size() + __j - 1 ]
            ) {
                __g[__i][__j - 1] = __v + 1;
                __visited[ __i * __g.front().size() + __j - 1 ] = 1;
                __q.push( { { __i, __j - 1 }, __v + 1 } );

            }

            if(
                __j + 1 < __g.front().size() &&
                !__visited[ __i * __g.front().size() + __j + 1 ]
            ) {
                __g[__i][__j + 1] = __v + 1;
                __visited[ __i * __g.front().size() + __j + 1 ] = 1;
                __q.push( { { __i, __j + 1 }, __v + 1 } );

            }

            __q.pop();            

        }
        
        return __g;
        
    }
};