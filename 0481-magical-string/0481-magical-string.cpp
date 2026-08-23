class Solution {
public:
    inline const int magicalString(
        const int& __n
    ) const noexcept {
        // dear author of this fuck ass description
        // you wouldnt know how to write a good one even
        // if it fucked you in the ass like your uncle did
        // when you were younger, from the bottom of my heart - fuck you.

        if( __n < 4 ) return 1;

        string __s{"122"};
        int __res{1};
        int __idx{2};

        while( __s.length() < __n ) {
            if( __s.back() == '2' )
                if( __s[__idx] == '2' ) {  
                    if( __s.length() + 2 > __n ) ++__res; 
                    else __res += 2; 

                    __s += "11";
                
                }
                else { __s += '1'; ++__res; }
            else
                if( __s[__idx] == '2' ) __s += "22";
                else __s += '2';

            ++__idx;

        }

        return __res;
        
    }
};

// 1 - a
// 2 - b
// 11 - c
// 22 - d
// adcbadadcbcd