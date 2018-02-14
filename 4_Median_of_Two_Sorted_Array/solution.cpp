class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. insert short vector item into longer vector by binary search
        vector<int> *longerVec = (nums1.size() >= nums2.size())? &nums1 : &nums2;
        vector<int> *shorterVec = (nums1.size() >= nums2.size())? &nums2 : &nums1;
        
        int low = 0;
        int high = longerVec->size() - 1;
        for (size_t i = 0; i < shorterVec->size(); i++){
            int index = binarySearch (*longerVec, shorterVec->at(i), low, high);
            longerVec->insert(longerVec->begin() + index, shorterVec->at(i));
            low = index;
            high = longerVec->size() - 1;
        }

        // 2. caculate median
        // max index is size() - 1
        int medianIdx = (longerVec->size() - 1) / 2;

        if (0 == (longerVec->size() % 2)){
            return (longerVec->at(medianIdx) + longerVec->at(medianIdx + 1)) / 2.0;
        }else{
            return (double) longerVec->at(medianIdx);
        }
    }

private:
    int binarySearch(vector<int> &a, int item, int low, int high){
        if (high <= low)
            return (item > a[low])?  (low + 1) : low;
 
        int mid = (low + high)/2;
 
        if(item == a[mid])
            return mid + 1;
 
        if(item > a[mid])
            return binarySearch(a, item, mid+1, high);
        return binarySearch(a, item, low, mid-1);
    }
};
