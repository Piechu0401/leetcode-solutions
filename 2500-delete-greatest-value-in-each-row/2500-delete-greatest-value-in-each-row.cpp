class Solution {
public:
    inline const int deleteGreatestValue(
        vector<vector<int>>& __g
    ) const noexcept {
        int __res{};

        while( __g.front().size() ) {
            char __max{};

            for( auto& __v : __g ) {
                char __localMax{};
                char __idx{};

                for( char __i{}; __i < __v.size(); ++__i ) {
                    if( __v[__i] > __localMax ) {
                        __localMax = __v[__i];
                        __idx = __i;
                        
                    }

                }

                __v[__idx] = __v[__v.size() - 1];
                __v.pop_back();

                __max = ( __localMax > __max ? __localMax : __max );

            }

            __res += __max;

        }

        return __res;

    }
};