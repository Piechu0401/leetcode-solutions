class Solution {
public:
    inline const bool parseBoolExpr(
        string __e
    ) {
        int __i{0};
        int __beg{0};
        short __operation{0};

        while( __e.length() > 1 ) {
            // cout << __e << "\n";
            if( 
                __e[__i] == ',' ||
                __e[__i] == '&' ||
                __e[__i] == '|' ||
                __e[__i] == '!' || 
                __e[__i] == 'f' ||
                __e[__i] == 't'
            ) { ++__i; continue; }
            else if( __e[__i] == '(' ) { 
                __beg = __i;
                __operation = __e[__i - 1] == '!' ? 1 : __e[__i - 1] == '&' ? 2 : 3;

            }
            else if( __e[__i] == ')' ) {
                if( __operation == 1 ) {
                    cout << __e << "\n";
                    bool __b = __e[__i - 1] == 'f' ? 0 : 1;
                    __e.erase( __beg - 1, __i - __beg + 2 );
                    __e.insert( __beg - 1, __b ? "f" : "t" ); 
            
                }
                else if( __operation == 2 ) {
                    bool __b = 1;
                    int __I{__beg};

                    while( __I < __i ) {
                        if( __e[__I] == 'f') {
                            __b = 0;
                            break;

                        }

                        ++__I;

                    }
                    __e.erase( __beg - 1, __i - __beg + 2 );
                    __e.insert( __beg - 1, __b ? "t" : "f" );

                }
                else if( __operation == 3 ) {
                    bool __b = 0;
                    int __I{__beg};

                    while( __I < __i ) {
                        if( __e[__I] == 't') {
                            __b = 1;
                            break;

                        }

                        ++__I;

                    }
                    __e.erase( __beg - 1, __i - __beg + 2 );
                    __e.insert( __beg - 1, __b ? "t" : "f" );


                }
                __i = 0;
                __beg = 0;
                continue;

            }

            ++__i;

            if( __i == __e.length() ) 
                __i = 0;

        }

        if( __e == "f" ) return 0;
        else if( __e == "t" ) return 1;

        return 0;

    }
};