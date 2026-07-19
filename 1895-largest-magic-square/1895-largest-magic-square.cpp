class Solution {
public:
    inline const int largestMagicSquare(
        vector<vector<int>>& __g
    ) const noexcept {
        char __res = ( __g.size() > __g.front().size() ? __g.front().size() : __g.size() ); 

        while( __res > 1 ){
            for( char __i{}; __i <= __g.size() - __res; ++__i )
                for( char __j{}; __j <= __g.front().size() - __res; ++__j ) {
                    vector<int> __rs( __res, 0 );
                    vector<int> __cs( __res, 0 );
                    int __d1{};
                    int __d2{};

                    for( char __k{}; __k < __res; ++__k ) {
                        __d1 += __g[__i + __k][__j + __k];
                        __d2 += __g[__i + __k][__j + __res - 1 - __k];
                        
                        for( char __l{}; __l < __res; ++__l ) {
                            __rs[__k] += __g[__i + __k][__j + __l];
                            __cs[__k] += __g[__i + __l][__j + __k];

                        }

                    }

                    if(
                        __rs == __cs &&
                        __rs == vector<int>( __res, __cs.front() ) &&
                        __d1 == __d2 &&
                        __d1 == __rs.front()
                    ) return __res;

                }

            --__res;

        }

        return __res;

    }
};