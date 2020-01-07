#include<map>
#include<unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
#include <string>
using namespace std;


//方法以：通过哈希映射的方法进行求解，并且将交集元素放入到两个数组中的一个，这样可以有助于节省空间
/*
*时间复杂度：O(n+m)其中 nn，mm 分别代表了数组的大小。
* 空间复杂度：O(min(n,m))，我们对较小的数组进行哈希映射使用的空间。
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        if(nums1.size()>nums2.size()){
            return intersect(nums2,nums1);
        }
        //vector<>
        unordered_map<int,int > m;
        //记录num1中的元素个数
        for(auto num:nums1){
            ++m[num];
        }

        int k=0;
        for(auto n:nums2){
            auto it = m.find(n);
            if(it!=m.end()&& --it->second>=0){//判断num1中的元素是否在num2中的元素存在，如果元素存在，则存入到num1列表中
                nums1[k++]=n;
            }
        }
        return vector(nums1.begin(),nums1.begin()+k);
        
    }
};