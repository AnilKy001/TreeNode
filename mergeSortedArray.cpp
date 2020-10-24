/* Created by Anil Kaya */
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
        if(nums1.size() == 0){
            exit(1);
        }
        if(nums2.size() != 0){

            vector<int> retVector;
            int ind = 0;
            while(*(nums1.end() - 1) == 0){
                nums1.pop_back();
            }
            for(auto k = nums1.begin(); k < nums1.end(); k++){
                if(ind < nums2.size()){
                    if(*k <= nums2[ind]){
                        retVector.push_back(*k);
                    }
                    else{
                        while((nums2[ind] < *k)&&(ind < nums2.size())){
                            retVector.push_back(nums2[ind]);
                            ind++;
                        }
                    }
                }
                else{
                    retVector.push_back(*k);
                }


            }

            nums1 = retVector;
        }
    }
};

int main(){
    vector <int> vec1 = {1, 1, 2, 5, 5, 6, 7, 0, 0, 0, 0};
    int len1 = 7;
    vector<int> vec2 = {2, 3, 4, 4};
    int len2 = 4;
    Solution v;
    v.merge(vec1, len1, vec2, len2);

    for(auto i = vec1.begin(); i < vec1.end(); i++){
        cout << *i;
    }
    cout << endl;
}
