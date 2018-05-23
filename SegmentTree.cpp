class NumArray {
public:
    
    class SegTreeNode
    {
        public:
        int leftInd;
        int rightInd;
        int val;
        SegTreeNode *left;
        SegTreeNode *right;
        
        SegTreeNode()
        {
            left = NULL;
            right = NULL;
        }
    };
    
    SegTreeNode *root;
    
    int makeTree(SegTreeNode *root, const vector<int> &vec)
    {
        if(root->leftInd == root->rightInd)
        {
            root->val = vec[root->leftInd];
            return vec[root->leftInd];
        }
        
        int mid = (root->leftInd + root->rightInd)/2;
        
        SegTreeNode *lf = new SegTreeNode();
        lf->leftInd = root->leftInd;
        lf->rightInd = mid;
        root->left = lf;
        SegTreeNode *rf = new SegTreeNode();
        rf->leftInd = mid+1;
        rf->rightInd = root->rightInd;
        root->right = rf;
        
        root->val = makeTree(lf, vec) + makeTree(rf, vec);
        return root->val;
    }
    
    NumArray(vector<int> nums) {
        if(nums.size() > 0){
        root = new SegTreeNode();
        root->leftInd = 0;
        root->rightInd = nums.size()-1;
        SegTreeNode *dummy = root;
        int sum = makeTree(dummy, nums);}
    }
    
    void update(int i, int val) {
        SegTreeNode *dummy = root;
        getUpdate(dummy, i, val);
        return;
    }
    
    int getUpdate(SegTreeNode *root, int &i, int &value)
    {
        if(root->leftInd == i && root->rightInd == i)
        {
            int diff = value - root->val;
            root->val = value;
            return diff;
        }
            
        if(i > root->rightInd || i < root->leftInd)
            return INT_MAX;
        
        int a = getUpdate(root->left, i, value);
        int b = getUpdate(root->right, i, value);
        
        if(a != INT_MAX)
        {   
            root->val += a; 
            return a;
        }
        if(b != INT_MAX)
        {
            root->val += b; 
            return b;
        }   
    }
    
    int sumRange(int i, int j) {
        SegTreeNode *dummy = root;
        return sumVal(dummy, i, j);
    }
    
    int sumVal(SegTreeNode *root, int &i, int &j)
    {
        if(i > root->rightInd || j < root->leftInd)
            return 0;
        
        if(root->leftInd >= i && root->rightInd <= j)
        {
//            cout<<"i "<<i<<" leftind "<<root->leftInd<<" r "<<root->rightInd<<endl;
            return root->val;
        }
        
        return sumVal(root->left, i, j) + sumVal(root->right, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
