class FreqStack {
public:
    // trust me, check out this sick shit
    // https://www.youtube.com/watch?v=HW9FghkVuQU

    struct __orderBy {
        explicit __orderBy(
            int& __I
        ) noexcept : __i( __I ) {}

        int& __i;

        inline const bool operator()(
            const pair<int, pair<int, int>>& __p1,
            const pair<int, pair<int, int>>& __p2
        ) const noexcept {
            if( __p1.second.second == __p2.second.second )
                return __p1.second.first > __p2.second.first; 

            return __p1.second.second > __p2.second.second;

        }

    };

    explicit FreqStack() noexcept :
        __s(__orderBy{__idx})
    {}
    
    inline void push(
        const int& __v
    ) noexcept {
        if( !__vals.count( __v ) ) {
            __vals[__v].push( ++__idx ); 
            __s.insert( { __v, { __idx, 1 } } );
            return;

        }

        // const pair<int, pair<int, int>> __key = { 
        //     __v, 
        //     { 
        //         __vals[__v].front(), 
        //         __vals[__v].size() 
        //     } 
        // };

        __s.erase(
            { 
                __v, 
                { 
                    __vals[__v].top(), 
                    __vals[__v].size() 
                } 
            }
        );
        __vals[__v].push( ++__idx );
        __s.insert( { __v, { __vals[__v].top(), __vals[__v].size() } } );

    }
    
    inline const int pop() noexcept {
        const pair<int, pair<int, int>> __top{ *__s.begin() };
        __s.erase( __top );

        // cout << __top.first << " " << __top.second.first << " " << __top.second.second << "\n";

        if( __vals[__top.first].size() == 1 ) {
            __vals.erase( __top.first );
            return __top.first;

        }

        __vals[__top.first].pop();
        __s.insert(
            {
                __top.first,
                {
                    __vals[__top.first].top(),
                    __vals[__top.first].size()
                }
            }
        );

        return __top.first;

    }
    
    // idx as you can see, and -1, because we will push ++__idx -> 0, 1, 2, 3, ...
    int                                         __idx{-1};

    // will store all idxs of some fuckass value
    unordered_map<int, stack<int>>              __vals;

    // will store value, and its min idx with number of occurences of given motherfucker 
    set<pair<int, pair<int, int>>, __orderBy>   __s;

};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */