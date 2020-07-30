int kth(const vector<int>& A,const vector<int>& B,int k,int aL,int aR,int bL,int bR)
{
   if(aL > aR) return B[bL + k - 1];
   if (bL > bR) return A[aL + k - 1];
        
        int aMid = (aL + aR) / 2;
        int bMid = (bL + bR) / 2;
        
        if (A[aMid] <= B[bMid]) {
            if (k <= (aMid - aL) + (bMid - bL) + 1) 
                return kth(A,B,k,aL, aR, bL, bMid - 1);
            else
                return kth(A,B, k - (aMid - aL) - 1,aMid + 1, aR, bL, bR);
        }
        else { // A[aMid] > B[bMid]
            if (k <= (aMid - aL) + (bMid - bL) + 1) 
                return kth(A,B,k,aL, aMid - 1, bL, bR);
            else
                return kth(A,B, k - (bMid - bL) - 1, aL, aR, bMid + 1, bR);
        }
}
double Solution::findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
    int n = nums1.size();
        int m = nums2.size();
        if((n+m)%2==1)
        {
            return kth(nums1,nums2,(n+m+1)/2,0,nums1.size()-1,0,nums2.size()-1);
        }
        int num1 = kth(nums1,nums2,(n+m)/2,0,nums1.size()-1,0,nums2.size()-1);
        int num2 = kth(nums1,nums2,(n+m)/2+1,0,nums1.size()-1,0,nums2.size()-1);
        return (num1+num2)/2.0;
}
