class TextEditor {
public:
    explicit TextEditor() noexcept : 
        __left(""),
        __right("")
    {
        // ++__operation;
        // cout << __operation << ": CONSTRUCTOR\n";
    }
    
    inline void addText(
        const string& __t
    ) {
        __left += __t;

        // ++__operation;
        // cout << __operation << ": ADD: " << __left << "|" << __right << "\n";

    }
    
    inline const int deleteText(
        const int& __k
    ) {
        if( __left == "" ) {
            // ++__operation;
            // cout << __operation << " DELETE IF: " << __left << "|" << __right << "\n";
            return 0;
            
        }
        else if(
            __left.length() <= __k
        ) {
            int __res = __k > __left.length() ? __left.length() : __k;
            __left = "";
            // ++__operation;
            // cout << __operation << ": DELETE ELSE IF: " << __left << "|" << __right << "\n";
            return __res;

        }
        else {
            for( int __i{0}; __i < __k; ++__i )
                __left.pop_back();
            // ++__operation;
            // cout << __operation << ": DELETE ELSE: " << __left << "|" << __right << "\n";
            return __k;

        }
        
    }
    
    inline const string cursorLeft(
        const int& __k
    ) {
        if( __left == "" ) {
            // ++__operation;
            // cout << __operation << ": LEFT IF: " << __left << "|" << __right << "\n";
            return __left;
            
        }
        else if(
            __left.length() <= __k
        ) {
            string __res = __left;
            __right = __left + __right;
            __left = "";
            // ++__operation;
            // cout << __operation << ": LEFT ELSE IF: " << __left << "|" << __right << "\n";
            return __left.substr( 
                __left.length() - __MIN(__left.length(), 10), 
                __MIN(__left.length(), 10) 
            );

        }
        else {
            string __res = __left.substr( 
                __left.length() - __k, 
                __k 
            );  
            __right = __res + __right;
            for( int __i{0}; __i < __k; ++__i )
                __left.pop_back(); // pop_back insetead of erase
            // ++__operation;
            // cout << __operation << ": LEFT ELSE: " << __left << "|" << __right << "\n"; 
            return __left.substr( 
                __left.length() - __MIN(__left.length(), 10), 
                __MIN(__left.length(), 10) 
            );

        }

    }
    
    inline const int __MIN(
        const int& __a,
        const int& __b
    ) { return __a > __b ? __b : __a; }

    inline const string cursorRight(
        const int& __k
    ) {
        if( __right == "" ) {
            // ++__operation; 
            // cout << __operation << ": RIGHT IF: " << __left << "|" << __right << "\n";
            return 
                __left.substr( 
                    __left.length() - __MIN(__left.length(), 10), 
                    __MIN(__left.length(), 10) 
                );

        }
        else if(
            __right.length() <= __k
        ) {
            string __res = __right;
            __left = __left + __right;
            __right = "";
            // ++__operation;
            // cout << __operation <<": RIGHT ELSE IF: " << __left << "|" << __right << "\n";
            return __left.substr( 
                __left.length() - __MIN(__left.length(), 10), 
                __MIN(__left.length(), 10) 
            );

        }
        else {
            string __res = __right.substr( 0, __k );  
            __left = __left + __res;
            __right.erase( 0, __k );
            // ++__operation;
            // cout << __operation << ": RIGHT ELSE: " << __left << "|" << __right << "\n";
            return __left.substr( 
                __left.length() - __MIN(__left.length(), 10), 
                __MIN(__left.length(), 10) 
            );

        }

    }

    string __left;
    string __right;
    // int __operation{0};

};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */