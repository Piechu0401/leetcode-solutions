class Solution {
public:
    inline const int furthestDistanceFromOrigin(
        const string& __m
    ) const noexcept {
        int __res{0};
        int __A{0};

        for( auto& __c : __m )
            if( __c == '_' ) ++__res;
            else if( __c == 'R' ) ++__A;
            else --__A;

        return __res + abs(__A);

    }
};