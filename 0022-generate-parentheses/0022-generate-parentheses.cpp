class Solution {
public:
    inline void doTheTrick(
        vector<string>& __res,
        string& __temp,
        const int& __n,
        int& __bal     
    ) const noexcept {
        if( __bal < 0 ) return;
        else if(
            !__bal && 
            __temp.length() == (__n << 1) 
        ) {
            if(
                find(
                    __res.begin(),
                    __res.end(),
                    __temp
                ) == __res.end()
            ) __res.emplace_back(__temp);
            return;

        }
        else if(
            __bal > 0 &&
            __temp.length() == (__n << 1)
        ) return;

        __temp += '(';
        ++__bal;

        doTheTrick(
            __res,
            __temp,
            __n,
            __bal     
        );

        --__bal;
        __temp.pop_back();

        __temp += ')';
        --__bal;

        doTheTrick(
            __res,
            __temp,
            __n,
            __bal    
        );

        ++__bal;
        __temp.pop_back();

    }

    inline const vector<string> generateParenthesis(
        const int& __n
    ) noexcept {
        vector<string> __res;
        string __temp="";
        int __bal{0};

        doTheTrick(
            __res,
            __temp,
            __n,
            __bal   
        );

        return __res;

    }

};