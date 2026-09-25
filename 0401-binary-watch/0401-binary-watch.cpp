class Solution {
public:
    inline void doTheTrick(
        vector<string>& __res,
        short&          __curr,
        char&           __count,
        int&            __to,
        const char&     __idx
    ) const noexcept {
        if( __count == __to ) {
            char __hours{
                (char)(( ( __curr & ( 1 << 6 )   ) >> 6 ) +
                ( ( __curr & ( 1 << 7 )   ) >> 6 ) +
                ( ( __curr & ( 1 << 8 )   ) >> 6 ) +
                ( ( __curr & ( 1 << 9 )   ) >> 6 ))
            };

            char __minutes{
                (char)(( __curr & 1            ) +
                ( __curr & ( 1 << 1 )   ) +
                ( __curr & ( 1 << 2 )   ) +
                ( __curr & ( 1 << 3 )   ) +
                ( __curr & ( 1 << 4 )   ) +
                ( __curr & ( 1 << 5 )   ))
            };

            if( __hours < 12 && __minutes < 60 ) // {
                __res.push_back(
                    to_string( __hours ) + ":" +
                    (__minutes < 10 ? "0" + to_string( __minutes ) : to_string( __minutes ))
                );

                // cout << __res.back() << "\n";

            // }

            return;

        }

        for( char __i{__idx}; __i < 10; ++__i ) {    
            if( __curr & ( 1 << __i ) ) continue;

            __curr += ( 1 << __i );
            ++__count;

            doTheTrick(
                __res,
                __curr,
                __count,
                __to,
                __i + 1
            );

            --__count;
            __curr -= ( 1 << __i );

        }

    }

    inline const vector<string> readBinaryWatch(
        int& __to
    ) const noexcept {
        vector<string>  __res;
        short           __curr{};
        char            __count{};

        doTheTrick(
            __res,
            __curr,
            __count,
            __to,
            0
        );

        return __res;

    }
};