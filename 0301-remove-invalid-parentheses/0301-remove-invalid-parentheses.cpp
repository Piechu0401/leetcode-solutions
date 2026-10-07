class Solution {
public:
    inline const bool validPar(
        const string& __src
    ) const noexcept {
        if(
            !__src.length()
        ) return 0;

        int __res{0};
        int __brack{0};

        for( auto& __c : __src ) {
            if( __c == '(' ) { ++__res; ++__brack; }
            else if( __c == ')' ) { 
                if( !__res ) return 0;
                --__res; 
                ++__brack; 

            }

        }

        return !__res && __brack;

    }

    inline void doTheTrick(
        const string& __s,
        vector<string>& __res,
        string& __curr,
        int& __min,
        const int& __i,
        const int& __removed
    ) noexcept {
        // cout << __curr << "\n";

        if( __removed > __min ) return;
        else if(
            !__p &&
            __i == __s.length() &&
            __removed < __min &&
            validPar( __curr ) 
        ) {
            __res.clear();
            __used.clear();
            __min = __removed;
            __res.emplace_back( __curr );
            __used.insert( __curr );
            return;

        }
        else if(
            !__p &&
            __i == __s.length() &&
            __removed == __min &&
            validPar( __curr ) &&
            !__used.count( __curr )
        ) {
            __res.emplace_back( __curr );
            __used.insert( __curr );
            return;

        }
        else if( __i == __s.length() ) return;

        __curr += __s[__i];
        __p += 
            __curr.back() == '(' ? 1 :\
            __curr.back() == ')' ? -1 :\
            0;

        doTheTrick(
            __s,
            __res,
            __curr,
            __min,
            __i + 1,
            __removed
        );

        __p += 
            __curr.back() == '(' ? -1 :\
            __curr.back() == ')' ? 1 :\
            0;
        __curr.pop_back();

        doTheTrick(
            __s,
            __res,
            __curr,
            __min,
            __i + 1,
            __removed + 1
        );

    }

    inline const vector<string> removeInvalidParentheses(
        const string& __s
    ) noexcept {
        vector<string> __res;
        int __min{INT_MAX};
        string __curr{""};
        
        doTheTrick(
            __s,
            __res,
            __curr,
            __min,
            0,
            0
        );

        if( !__res.size() ) {
            string __str{""};

            for( auto& __c : __s )
                if(
                    __c != '(' &&
                    __c != ')'
                ) __str += __c;

            return {__str};

        }

        return __res;

    }

    unordered_set<string> __used;
    int __p{0};

};