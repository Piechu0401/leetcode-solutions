class Solution {
public:
    inline void doTheTrick(
        vector<string>&     __res,
        string&             __s,
        vector<char>&       __idxs
    ) const noexcept {
        if( 
            __idxs.size() == 3 &&
            __s.length() - 1 - __idxs[2] < 4
        ) {
            // cout 
            //     << __s.substr( 0, __idxs[0] + 1 ) << " "
            //     << __s.substr( __idxs[0] + 1, __idxs[1] - __idxs[0] ) << " "
            //     << __s.substr( __idxs[1] + 1, __idxs[2] - __idxs[1] ) << " "
            //     << __s.substr( __idxs[2] + 1, __s.length() - __idxs[2] ) << "\n";

            string __1{ __s.substr( 0, __idxs[0] + 1 ) };
            string __2{ __s.substr( __idxs[0] + 1, __idxs[1] - __idxs[0] ) };
            string __3{ __s.substr( __idxs[1] + 1, __idxs[2] - __idxs[1] ) };
            string __4{ __s.substr( __idxs[2] + 1, __s.length() - __idxs[2] ) };

            // cout << __1 << " " << __2 << " " << __3 << " " << __4 << "\n";
            // cout << (int)__idxs[0] << " " << (int)__idxs[1] << " " << (int)__idxs[2] << "\n";

            if( 
                !__1.length() ||
                !__2.length() ||
                !__3.length() ||
                !__4.length() ||
                ( __s[0] == '0' && ( __idxs[0] + 1 > 1 ) ) ||
                ( __s[__idxs[0] + 1] == '0' && ( __idxs[1] - __idxs[0] > 1 ) ) ||
                ( __s[__idxs[1] + 1] == '0' && ( __idxs[2] - __idxs[1] > 1 ) ) ||
                ( __s[__idxs[2] + 1] == '0' && ( __s.length() - 1 - __idxs[2] > 1 ) ) ||
                stoi( __1 ) > 255 ||
                stoi( __2 ) > 255 ||
                stoi( __3 ) > 255 ||
                stoi( __4 ) > 255
            ) return;

            __res.push_back( __1 + "." + __2 + "." +  __3 + "." + __4 );

            return;

        }

        if( __idxs.size() )
            for( char __i = __idxs.back() + 1; __i < min( (int)__idxs.back() + 4, (int)__s.length() - 1 ); ++__i ) {
                // doTheTrick(
                //     __res,
                //     __s,
                //     __idxs
                // );

                __idxs.emplace_back( __i );

                doTheTrick(
                    __res,
                    __s,
                    __idxs
                );

                __idxs.pop_back();

            }
        else
            for( char __i{}; __i < 3; ++__i ) {
                // doTheTrick(
                //     __res,
                //     __s,
                //     __idxs
                // );

                __idxs.emplace_back( __i );

                doTheTrick(
                    __res,
                    __s,
                    __idxs
                );

                __idxs.pop_back();

            }

    }

    inline const vector<string> restoreIpAddresses(
        string& __s
    ) const noexcept {
        if(
            __s.length() < 4 ||
            __s.length() > 12
        ) return {};

        vector<string>  __res;
        vector<char>    __idxs;

        doTheTrick(
            __res,
            __s,
            __idxs
        );

        return __res;

    }
};