leetcode215:https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

采用快排思想，枢纽左边都比它小，右边都比它大，如果选取a[r]为枢纽只需要对左边处理
最终如果枢纽就是k(这里是n-k)，就返回a[枢纽]，否则去左边或者右边迭代
复杂度：每划分一趟是O(n)的，最坏情况是每次分成1个元素和其他，O(n^2)，随机化后期望是O(n)

class Solution {
public:
    //快速选择算法
    int quickSelect(vector<int>& a,int l,int r, int k){
        int q=randomPartition(a,l,r);
        if(q==k)return a[q];
        if(q<k)return quickSelect(a,q+1,r,k);//枢纽<k，则去找比它大的一侧
        else return quickSelect(a,l,q-1,k);
    }
    
    //获取一个随机枢纽的划分结果
    int randomPartition(vector<int>& a,int l,int r){
        int x=rand()%(r-l+1)+l;//随机化，避免样例为难
        swap(a[x],a[r]);
        int key=a[r],i=l-1;
        for(int j=l;j<r;++j){
            if(a[j]<=key){
                swap(a[++i],a[j]);//保证小于key的都放在前面
            }
        }
        swap(a[++i],a[r]);//key放在此时的i
        return i;
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect(nums,0,nums.size()-1,nums.size()-k);//第k大即第n-k小
    }
};
