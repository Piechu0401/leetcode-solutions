class Solution {
public:
    inline const int distinctEchoSubstrings(
        const string& __temp
    ) const noexcept {
        // if you are struggling to do this, and somehow this fenomenal description 
        // of some genius individual didn't help plus you stumbled on me reading this
        // the question basicly wants you to find all subs that are made of some string
        // this hints that you need to check only subs of even length plus using a hashmap
        // to not check whole shit again, hope this clicks in for you.

        string_view __t = __temp;
        unordered_set<string_view> __us;
        short   __size{1};
        int     __res{};

        while( __size <= __t.length() ) {
            if( !( __size & 1 ) )
                for( short __i{}; __i <= __t.length() - __size; ++__i ) {
                    // string __temp{ __t.substr( __i, __size ) };
                    char __valid{1};

                    for( short __j{__i}; __j < __i + ( __size >> 1 ); ++__j )
                        if( __t[__j] != __t[__j + ( __size >> 1 )] ) {
                            __valid = 0;
                            break;

                        }

                    if( __valid && !__us.count( __t.substr( __i, __size ) ) ) {
                        ++__res;
                        __us.erase( __t.substr( __i, ( __size >> 1 ) ) );
                        __us.insert( __t.substr( __i, __size ) );

                    }

                }
            // no point in checking odd lengths

            ++__size;

        }

        return __res;
        
    }
};