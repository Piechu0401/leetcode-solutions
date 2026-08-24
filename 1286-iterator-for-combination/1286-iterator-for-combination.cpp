class CombinationIterator {
public:
    explicit CombinationIterator(
        const string&   __chs, 
        const int&      __cl
    ) :
        __src( __chs ),
        __max( __cl )
    {
        unsigned short __curr{};

        doTheTrick(
            __curr,
            0,
            0
        );

        //cout << __q.size();

    }
    
    inline const string next() noexcept {
        string __res{};
        char __i{15};
        unsigned short __p{ ( 1 << 15 ) };

        while( __p > 0 ) {
            if( ( __p & __q.front() ) == __p ) { 
                __res = __src[__i] + __res;

            }
            // cout << (int)__i << "\n";
            __p >>= 1;
            --__i;

        }

        // cout << "\n";
        
        __q.pop();

        return __res;

    }
    
    inline const bool hasNext() const noexcept { return !__q.empty(); }

    private:
        inline void doTheTrick(
            unsigned short&     __curr,
            const char&         __idx,
            const char&         __len
        ) noexcept {
            if( __len == __max ) {
                __q.push( __curr );
                // cout << __curr << "\n";
                return;

            }

            for( char __i{__idx}; __i < __src.length(); ++__i ) {
                __curr += ( 1 << __i );

                doTheTrick(
                    __curr,
                    __i + 1,
                    __len + 1
                );

                __curr -= ( 1 << __i );

            }

        }

        const int               __max;
        queue<unsigned short>   __q;
        const string            __src;

};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 // 0000000000000011
 // 0000000000000101
 // 0000000000000110