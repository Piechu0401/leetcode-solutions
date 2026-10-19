class RandomizedSet {
public:
    explicit RandomizedSet() noexcept {}
    
    inline const bool insert(
        const int& __v
    ) noexcept { 
        if( __vals.count(__v) ) return 0;
        __vals.insert(__v); 
        return 1;
        
    }
    
    inline const bool remove(
        const int& __v
    ) noexcept { 
        if( !__vals.count(__v) ) return 0;
        __vals.erase( __v ); 
        return 1;
        
    }
    
    inline const int getRandom() const noexcept {
        auto __beg = __vals.begin();
        advance(__beg, rand() % __vals.size());
        return *__beg;

    };

    unordered_set<int> __vals;

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */