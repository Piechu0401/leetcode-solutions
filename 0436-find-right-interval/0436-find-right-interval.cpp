class Solution {
public:
    struct __vecHash {
        inline const unsigned long operator()(
            const vector<int>& __v
        ) const noexcept {
            return
                hash<int>{}( __v[0]      ) ^
                hash<int>{}( __v[1] << 1 );

        }

    };

    inline const vector<int> findRightInterval(
        vector<vector<int>>& __is
    ) const noexcept {
        vector<int> __res( __is.size(), -1 );
        unordered_map<vector<int>, int, __vecHash> __um;

        for( int __i{}; __i < __is.size(); ++__i ) __um[__is[__i]] = __i;

        sort(
            __is.begin(),
            __is.end(),
            [](
                const vector<int>& __a,
                const vector<int>& __b 
            ) {
                if( __a[0] == __b[0] ) return __a[1] < __b[1];

                return __a[0] < __b[0];

            }

        );

        for( auto& __i : __is ) {
            int __b{};
            int __e{ (int)__is.size() - 1 };
            int __idx{-1};

            while( __b <= __e ) {
                int __m{ __b + ( ( __e - __b ) >> 1 ) };

                if( __is[__m][0] >= __i[1] ) {
                    __idx = __m;
                    __e = --__m;

                } else __b = ++__m;

            }
            
            if( __idx > -1 ) __res[__um[__i]] = __um[__is[__idx]];

        }

        return __res;
        
    }
};