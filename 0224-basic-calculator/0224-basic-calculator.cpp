class Solution {
public:
    inline const int calculate(
        string __s
    ) {
        int __res{0};
        int __i{0};
        int __begin{0};

        while( __i < __s.length() ) {
            if( __s[__i] == ' ' ) {
                __s.erase(__i, 1);
                continue;

            }

            ++__i;

        }

        __i = 0;

        auto myEval = [](
            string __sub
        ) -> string {
            int __res = 0;
            int __number = 0;
            int __ind = 0;
            int __sign = 0;

            while( __ind < __sub.length() ) {
                if( 
                    __sub[__ind] == '(' ||
                    __sub[__ind] == ')' 
                ) { ++__ind; continue;}
                else if( 
                    __ind < __sub.length() - 1 &&
                    (__sub[__ind] == '-' &&
                    (__sub[__ind + 1] == '+' ||
                    __sub[__ind + 1] == '-')) ||
                    (__sub[__ind] == '+' &&
                    (__sub[__ind + 1] == '-' ||
                    __sub[__ind + 1] == '+')) 
                ) {
                    __number = 0;
                    string __signStr = (((__sub[__ind] == '-' && __sub[__ind + 1] == '+') || (__sub[__ind] == '+' && __sub[__ind + 1] == '-')) ? "-" : "+");
                    __sub.erase( __ind, 2 );
                    __sub.insert(
                        __ind,
                        __signStr
                    );
                    // cout << "NEW SIGN: " << __ind << __sub << "\n";
                    __sign = 0;
                    __ind = 0;
                    continue;
                    
                }
                else if( __sub[__ind] == '-' ) {
                    if( __sign == 0 ) {
                        __res = __number;
                        __sign = -1;
                        __number = 0;
            
                    }
                    else {
                        __res += __number;
                        __sign = -1;
                        __number = 0;

                    }

                }
                else if( __sub[__ind] == '+' ) {
                    if( __sign == 0 ) {
                        __res = __number;
                        __sign = 1;
                        __number = 0;

                    }
                    else {
                        __sign = 1;
                        __res += __number;
                        // cout << __res << "\n";
                        __number = 0;

                    }

                }
                else if(
                    __sub[__ind] - 48 < 10 &&
                    __sub[__ind] - 48 > -1
                ) {
                    if( __sign == 0 ) 
                        __number = __number * 10 + (__sub[__ind] - 48);
                    else
                        __number = __number * 10 + __sign * (__sub[__ind] - 48);
                    //cout << __number << "\n";

                }

                ++__ind;

            }

            // cout << "NUMBER: " << __number << "\n";
            __res += __number;

            return to_string(__res); // could do a loop that does it, but im lazy today

        };

        int __count = 0;

        while( __i < __s.length() ) {
            if( __s[__i] == '(' ) { __begin = __i; ++__count; }
            else if( __s[__i] == ')' ) { 
                // cout << __s << "\n";
                string __temp = myEval( __s.substr( __begin, __i - __begin + 1 ) );
                __s.erase( __begin, __i - __begin + 1 );
                __s.insert( __begin, __temp );
                __i = 0;
                // cout << __s << "\n";
                continue;

            }

            ++__i;

            if( __i >= __s.length() ) {
                if( __count == 0 ) { 
                    string __temp = myEval( __s );
                    
                    // cout << "COUNT: " << __temp << "\n";

                    return stoi( __temp );

                }

                __count = 0;   
                __i = 0;
                bool __digit = 1;
                for( int __j{0}; __j < __s.length(); ++__j ) {
                    if( 
                        __s[__j] == '(' ||
                        __s[__j] == ')' ||
                        __s[__j] == '+' ||
                        __s[__j] == '-'
                    ) { __res = 0; __i = 0; __digit = 0; break; }
                    else __res = __res * 10 + ( __s[__j] - 48 );

                }

                if( __digit ) { 
                    break;
                    
                }

            }

        }

        // cout << "END: " << __i << " " << __s << "\n";

        return __res;

    }
};