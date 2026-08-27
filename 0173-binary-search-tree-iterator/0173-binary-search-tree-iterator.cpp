/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    explicit BSTIterator(
        TreeNode* __r
    ) noexcept { 
        doTheTrick( __r ); 
        __q.push( __r->val );
    
    }
    
    inline const int next() noexcept {
        int __res{__q.front()};
        __q.pop();

        return __res;

    }
    
    inline const bool hasNext() const noexcept { return __q.size() > 1; }
    
    queue<int> __q;

    private:
        inline void doTheTrick(
            TreeNode* __r
        ) noexcept {
            if( !__r ) return;

            doTheTrick( __r->left );

            __q.push( __r->val );

            doTheTrick( __r->right );

        }

};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */