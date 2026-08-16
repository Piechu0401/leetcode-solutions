class Solution {
public:
    inline const bool areSentencesSimilar(
        string& __s1, 
        string& __s2
    ) const noexcept {
        if( __s1.length() == __s2.length() ) return __s1 == __s2;
        else if( __s1 == "" || __s2 == "" ) return 1;
        
        vector<string> __ws1;
        vector<string> __ws2;
        string __word{};

        for( auto& __c : __s1 )
            if( __c == ' ' ) {
                __ws1.emplace_back( __word );
                __word = "";

                // cout << __ws1.back() << "\n";

            }
            else __word += __c;

        if( __word.length() ) {
            __ws1.emplace_back( __word );
            __word = "";

            // cout << __ws1.back() << "\n";

        }
        
        for( auto& __c : __s2 )
            if( __c == ' ' ) {
                __ws2.emplace_back( __word );
                __word = "";

                // cout << __ws2.back() << "\n";

            }
            else __word += __c;

        if( __word.length() ) {
            __ws2.emplace_back( __word );
            __word = "";

            // cout << __ws2.back() << "\n";

        }

        if( __s1.length() < __s2.length() ) {
            while(
                __ws1.size() &&
                __ws1.back() == __ws2.back()
            ) {
                __ws1.pop_back();
                __ws2.pop_back();

            }

            if( !__ws1.size() ) return 1;

            char __res{};

            while(
                __res < __ws1.size() &&
                __ws1[__res] == __ws2[__res]
            ) ++__res;

            return __res == __ws1.size();

        }

        while(
            __ws2.size() &&
            __ws1.back() == __ws2.back()
        ) {
            __ws1.pop_back();
            __ws2.pop_back();

        }

        if( !__ws2.size() ) return 1;

        char __res{};

        while(
            __res < __ws2.size() &&
            __ws1[__res] == __ws2[__res]
        ) ++__res;

        return __res == __ws2.size();

    }
};