class Solution {
public:
    inline const int countKConstraintSubstrings(
        string&     __s, 
        int&        __k
    ) const noexcept {
        short __res{};

        for( char __i{}; __i < __s.length(); ++__i ) {
            char __o{};
            char __z{};
            char __j{__i};

            while(
                __j < __s.length() &&
                (
                    __o <= __k ||
                    __z <= __k
                )
            ) { 
                if( __s[__j] == '0' ) ++__z;  
                else ++__o;

                if(
                    __o <= __k ||
                    __z <= __k
                ) ++__res;
                
                ++__j; 
                
            }

        }

        return __res;
        
    }
};