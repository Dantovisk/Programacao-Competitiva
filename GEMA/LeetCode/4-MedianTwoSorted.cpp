#include <bits/stdc++.h>

using namespace std;

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m1 = (nums1.size() + nums2.size())/2;
        int m2 = (nums1.size() + nums2.size() - 1)/2;
        int maxx = nums1.size();
        int minn = 0;


        double mediana = 0;
        int m = m1;

        for(int z=0; z<2; z++){
            
            while(minn<maxx){
                int med = (minn+maxx)/2;
                int k = nums1[med];

                auto it = lower_bound(nums2.begin(), nums2.end(), k);
                auto it2 = upper_bound(nums2.begin(), nums2.end(), k);
                if(*it == k) it2--;
                
                int indminn = distance(nums2.begin(), it);
                int indmaxx = distance(nums2.begin(), it2);

                if(m >= indminn && m <= indmaxx){
                    mediana += m;
                    break;
                }
                else if(m<indminn){
                    minn = med+1;
                } else{
                    maxx = med;
                }
            } 

            m = m2; 
        }

        return mediana/2;
        
    }

int main(){
    vector <int> v1 = {1,2,3};
    vector <int> v2 = {4,5};

    cout<<findMedianSortedArrays(v1, v2);


    return 0;
}