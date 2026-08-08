class Solution {
public:
    inline const int minSetSize(
        const vector<int>& __ns
    ) const noexcept {
        unordered_map<int, int> __m;

        for( auto& __n : __ns ) ++__m[__n];

        vector<int> __fs;

        for( auto& __n : __m ) __fs.emplace_back( __n.second );

        sort( 
            __fs.begin(), 
            __fs.end(),
            [](
                const int& __a,
                const int& __b
            ) -> const bool {
                return __b < __a;

            }
        );

        int __res{};
        int __count{};

        while( ( __ns.size() >> 1 ) > __count ) {
            __count += __fs[__res];
            ++__res;

        }

        return __res;
        
    }
};