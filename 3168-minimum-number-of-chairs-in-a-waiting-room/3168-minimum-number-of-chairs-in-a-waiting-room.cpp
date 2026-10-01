class Solution {
public:
    inline const int minimumChairs(
        string& __s
    ) const noexcept {
        char __res{};
        char __curr{};

        for( auto& __ch : __s ) {
            if( __ch == 'E' )   ++__curr;
            else                --__curr;

            __res = ( __res < __curr ? __curr : __res );

        }

        return __res;

    }
};