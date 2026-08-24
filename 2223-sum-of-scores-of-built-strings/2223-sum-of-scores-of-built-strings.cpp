class Solution {
public:
    inline const long long sumScores(
        string& __s
    ) const noexcept {
        long long __res{};
        string_view __svs( __s );

        for( int __i{1}; __i <= __s.length(); ++__i ) {
            int __b{};
            int __e{__i};
            int __add{};

            if( __svs.substr( 0, __i ) == __svs.substr( __s.length() - __i, __i ) ) {
                __res += __i;
                continue;

            }

            while( __b <= __e ) {
                int __mid{ __b + ( ( __e - __b ) >> 1 ) };

                if( __svs.substr( 0, __mid ) == __svs.substr( __s.length() - __i, __mid ) ) {
                    __add = __mid;
                    __b = ++__mid;

                } else __e = --__mid;

            }

            __res += __add;

        }

        return __res;

    }
};