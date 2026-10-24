class Solution {
public:
    inline const int countDaysTogether(
        string& __aa, 
        string& __la, 
        string& __ab, 
        string& __lb
    ) const noexcept {
        short __res{};
        char __days[366]{};
        short __monthsPref[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

        for( 
            short __i = ( __monthsPref[(__aa[0] - 48) * 10 + ( __aa[1] - 48) - 1] + ( __aa[3] - 48 ) * 10 + ( __aa[4] - 48 ) );
            __i <= ( __monthsPref[(__la[0] - 48) * 10 + ( __la[1] - 48) - 1] + ( __la[3] - 48 ) * 10 + ( __la[4] - 48 ) );
            ++__i
        ) ++*( __days + __i );

        for( 
            short __i = ( __monthsPref[(__ab[0] - 48) * 10 + ( __ab[1] - 48) - 1] + ( __ab[3] - 48 ) * 10 + ( __ab[4] - 48 ) );
            __i <= ( __monthsPref[(__lb[0] - 48) * 10 + ( __lb[1] - 48) - 1] + ( __lb[3] - 48 ) * 10 + ( __lb[4] - 48 ) );
            ++__i
        ) ++*( __days + __i );

        // cout 
        //    << ( __monthsPref[(__aa[0] - 48) * 10 + ( __aa[1] - 48) - 1] + ( __aa[3] - 48 ) * 10 + ( __aa[4] - 48 ) ) % 365 << " "
        //    << ( __monthsPref[(__la[0] - 48) * 10 + ( __la[1] - 48) - 1] + ( __la[3] - 48 ) * 10 + ( __la[4] - 48 ) ) % 365 << " "
        //    << ( __monthsPref[(__ab[0] - 48) * 10 + ( __ab[1] - 48) - 1] + ( __ab[3] - 48 ) * 10 + ( __ab[4] - 48 ) ) % 365 << " "
        //    << ( __monthsPref[(__lb[0] - 48) * 10 + ( __lb[1] - 48) - 1] + ( __lb[3] - 48 ) * 10 + ( __lb[4] - 48 ) ) % 365 << "\n";

        for( short __i{}; __i < 366; ++__i ) {
            // cout << (int)__days[__i] << " ";
            __res += ( __days[__i] == 2 ? 1 : 0 );

        }

        return __res;
        
    }
};