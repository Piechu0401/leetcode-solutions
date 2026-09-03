class Solution {
public:
    inline const string doTheTrick(
        const string& __sub
    ) const noexcept {
        long long __mult{1};
        short __e = __sub.length() - 1;

        while( 
            __sub[__e] >= '0' &&
            __sub[__e] <= '9'
        ) --__e;

        if( __e == __sub.length() - 1 ) return __sub.substr( 1, __sub.length() - 2 );

        __mult = stoll( __sub.substr( __e + 1, __sub.length() - __e - 1 ) );

        string __res{};

        for( short __i{1}; __i < __e; ++__i ) {
            if( 
                __sub[__i] < 'A' ||
                __sub[__i] > 'Z'
            ) continue;

            short __b = __i + 1;

            while(
                __b < __sub.length() &&
                __sub[__b] >= 'a' &&
                __sub[__b] <= 'z'
            ) ++__b;

            __res += __sub.substr( __i, __b - __i );

            if( __b == __sub.length() ) {
                if( __mult > 1 ) __res += to_string( __mult );
                break;

            }
            else if( 
                __sub[__b] >= 'A' &&
                __sub[__b] <= 'Z'
            ) {
                if( __mult > 1 ) __res += to_string( __mult );
                __i = --__b;
                continue;

            }

            short __st{__b};

            while(
                __b < __sub.length() &&
                __sub[__b] >= '0' &&
                __sub[__b] <= '9'
            ) ++__b;

            if( __st == __b && __mult > 1 ) {
                __res += to_string( __mult );
                continue;

            }

            __res += to_string( __mult * stoll( __sub.substr( __st, __b - __st ) ) );
            
            __i = --__b;

        }

        // cout << "__RES: " << __res << "\n";

        return __res;

    }

    inline const string countOfAtoms(
        string& __f
    ) const noexcept {
        short __i{};
        stack<short> __st{};

        while( __i < __f.length() ) {
            if( __f[__i] == '(' ) __st.push( __i );
            else if( __f[__i] == ')' ) {
                // cout << __i << " " << __f.length() << "\n";
                // cout << __f.substr( __st.top(), __i - __st.top() + 1 ) << "\n";
                
                // if( __i + 1 == __f.length() ) {
                //     string __temp{ __f.substr( __st.top() + 1, __i - __st.top() ) };
                //     __f.erase( __f.begin() + __i, __f.begin() + __i - __st.top() + 1 );
                //     __f.insert( __f.begin() + __i, __temp.begin(), __temp.end() );
                //     cout << "bracketless: " << __f << "\n"; 
                //     break;
                // 
                // }

                string __temp{};
                short __b{__i};

                ++__i;
                while(
                    __i < __f.length() &&
                    __f[__i] >= '0' &&
                    __f[__i] <= '9'
                ) { __temp += __f[__i]; ++__i; }

                // if( __i == __f.length() || !( __f[__i] >= '0' && __f[__i] <= '9' ) ) --__i;
                // cout << __f << "\n";

                string __load{ doTheTrick( __f.substr( __st.top(), __i - __st.top() ) ) };
                // cout << __f.length() << " " << __st.top() << " " << ( __i ) << "\n";
                __f.erase( __f.begin() + __st.top(), __f.begin() + __i );
                __f.insert( __f.begin() + __st.top(), __load.begin(), __load.end() );

                // cout << __f.substr( __st.top(), __i - __st.top() + 1 ) << "\n";
                // cout << doTheTrick( __f.substr( __st.top(), __i - __st.top() + 1 ) ) << "\n";

                if( __st.size() ) {
                    __st.pop();
                    if( __st.size() ) __i = __st.top() + 1;
                    else __i = 0;
                    continue;
                    
                }              

            }
            
            ++__i;

        }

        // part above was such a pain in the ass, but I made it here getting
        // string that has no parentheses, and valid counts

        map<string, long long> __strs;
        // cout << __f << "\n";

        for( int __i{}; __i < __f.length(); ++__i ) {
            string __name{}; 
            __name += __f[__i];
            int __b{__i + 1};

            while(
                __b < __f.length() &&
                __f[__b] >= 'a' &&
                __f[__b] <= 'z'
            ) { __name += __f[__b]; ++__b; }

            if( __b == __f.length() ) { ++__strs[__name]; break; }
            else if( __f[__b] >= 'A' && __f[__b] <= 'Z' ) { 
                ++__strs[__name]; 
                __i = --__b;
                continue;
                
            }

            int __st{__b};

            string __num{};

            while(
                __b < __f.length() &&
                __f[__b] >= '0' &&
                __f[__b] <= '9'
            ) { __num += __f[__b]; ++__b; }

            __strs[__name] += stoll( __num );
            __i = --__b;

        }

        __f = "";

        for( auto& __str : __strs ) {
            // cout << __str.first << " " << __str.second << "\n";
            __f += __str.first;
            if( __str.second > 1 ) __f += to_string( __str.second );

        }

        return __f;
        
    }
};

// H20 --> H20
// Mg(OH)2 --> H2MgO2
// K4(ON(SO3)2)2 --> K4(ONS2O6)2 --> K4O2N2S4O12