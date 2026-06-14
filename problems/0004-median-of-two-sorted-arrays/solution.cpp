class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        vector<int> merge(n+m);
        int k=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                merge[k++]=(nums1[i++]);
            }
            else{
                merge[k++]=(nums2[j++]);
            }
        }
        while(i<n){
            merge[k++]=(nums1[i++]);
        }
        while(j<m){
            merge[k++]=(nums2[j++]);
        }
        int low=0;
        int high=m+n-1;
        int mid=(low+high)/2;
        double ans=0;
        if(merge.size()%2==0){
            ans=(merge[mid]+merge[mid+1])/2.0;
        }
        else{
            ans=merge[mid];
        }
        return ans;
    }
};