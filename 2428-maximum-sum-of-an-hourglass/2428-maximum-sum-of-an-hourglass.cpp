class Solution {
public:
    inline const int maxSum(
        const vector<vector<int>>& __g
    ) const noexcept {
        int __res{};

        for( unsigned char __i{1}; __i < __g.size() - 1; ++__i )
            for( unsigned char __j{1}; __j < __g.front().size() - 1; ++__j )
                if(
                    __g[__i][__j] +
                    __g[__i - 1][__j - 1] +
                    __g[__i - 1][__j] +
                    __g[__i - 1][__j + 1] +
                    __g[__i + 1][__j - 1] +
                    __g[__i + 1][__j] +
                    __g[__i + 1][__j + 1] > __res
                ) __res = 
                    __g[__i][__j] +
                    __g[__i - 1][__j - 1] +
                    __g[__i - 1][__j] +
                    __g[__i - 1][__j + 1] +
                    __g[__i + 1][__j - 1] +
                    __g[__i + 1][__j] +
                    __g[__i + 1][__j + 1];

        return __res;

    }
};