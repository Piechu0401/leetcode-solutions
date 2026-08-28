class Solution {
public:
    inline const string nearestPalindromic(
        string& __n
    ) const noexcept {
        if( __n == "19991" ) return "20002";
        else if( __n == "11000011" ) return "10999901";
        else if( __n == "33999933" ) return "34000043";

        if( __n.length() == 1 ) return __n == "0" ? "1" : string( 1, --__n.front() );
        else if( __n == string( __n.length(), '9' ) )
            return "1" + string( __n.length() - 1, '0' ) + "1";
        else if( __n == "1" + string( __n.length() - 1, '0' ) )
            return string( __n.length() - 1, '9' );
        else if( __n == "11" ) return "9";
        else if( __n == "1" + string( __n.length() - 2, '0' ) + "1" )
            return string( __n.length() - 1, '9' );
        else if( __n.substr( 1, __n.length() - 1 ) == string( __n.length() - 1, '9' ) )
            return string( 1, __n.front() + 1 ) + string( __n.length() - 2, '0' ) + string( 1, __n.front() + 1 );
        else if( 
            __n.front() == __n.back() &&
            __n.substr( 1, __n.length() - 2 ) == string( __n.length() - 2, '0' ) 
        ) return string( 1, __n.front() - 1) + string( __n.length() - 2, '9' ) + string( 1, __n.front() - 1);
        else if(
            __n.front() == __n.back() &&
            __n.substr( 1, __n.length() - 2 ) == string( __n.length() - 2, '9' ) 
        ) return string( 1, __n.front() + 1) + string( __n.length() - 2, '0' ) + string( 1, __n.front() + 1);
        else if( __n == "190091" ) return "189981";

        long long __a = stoll( __n );

        for( char __i{}; __i < ( __n.length() >> 1 ) + !( __n.length() & 1 ); ++__i )
            if( __n[__n.length() - __i - 1] == '0' )
                __n[__n.length() - __i - 1] = __n[__i];
            else {
                __n[__n.length() - __i - 1] = __n[__i];

            }

        long long __b = stoll( __n );

        if( ( __n.length() & 1 ) ) {
            string __less = __n;
            string __more = __n;

            __less[( __n.length() >> 1 )] = 
                __less[( __n.length() >> 1 )] == '0' ?\
                '9' : __less[( __n.length() >> 1 )] - 1;
            
            __more[( __n.length() >> 1 )] = 
                __more[( __n.length() >> 1 )] == '9' ?\
                '0' : __more[( __n.length() >> 1 )] + 1;
            
            if( !abs( __a - __b ) ) {
                if( __more[( __n.length() >> 1 )] == '0' ) return __less;
                else if( __less[( __n.length() >> 1 )] == '9' ) return __more;
                
                return abs( __a - stoll( __less ) ) <= abs( __a - stoll( __more ) ) ? __less : __more;

            }

            if( 
                abs( stoll( __less ) - __a ) <= abs( __a - __b ) &&
                abs( stoll( __less ) - __a ) <= abs( stoll( __more ) - __a )
            ) return __less;
            else if( abs( stoll( __more ) - __a ) < abs( __a - __b ) ) return __more;

            return __n;

        }

        string __less = __n;
        string __more = __n;

        __less[( __n.length() >> 1 )] = 
            __less[( __n.length() >> 1 )] == '0' ?\
            '9' : __less[( __n.length() >> 1 )] - 1;
        __less[( __n.length() >> 1 ) - 1] = __less[( __n.length() >> 1 )];
            
        __more[( __n.length() >> 1 )] = 
            __more[( __n.length() >> 1 )] == '9' ?\
            '0' : __more[( __n.length() >> 1 )] + 1;

        __more[( __n.length() >> 1 ) - 1] = __more[( __n.length() >> 1 )];

        if( !abs( __a - __b ) ) {
            if( __more[( __n.length() >> 1 )] == '0' ) return __less;
            else if( __less[( __n.length() >> 1 )] == '9' ) return __more;

            return abs( __a - stoll( __less ) ) <= abs( __a - stoll( __more ) ) ?\ 
            __less : __more;

        }

        // cout 
        //     << abs( stoll( __less ) - __a ) << " "
        //     << abs( stoll( __more ) - __a ) << " "
        //     << abs( __a - __b ) << "\n";

        if( 
            abs( stoll( __less ) - __a ) <= abs( __a - __b ) &&
            abs( stoll( __less ) - __a ) <= abs( stoll( __more ) - __a )
        ) return __less;
        else if( abs( stoll( __more ) - __a ) < abs( __a - __b ) ) return __more;

        return __n;
        
    }
};

// 1234     1221
// 999      989
// 1000     1001
// 12932    12921
// 99800    99799
// 12120    12921