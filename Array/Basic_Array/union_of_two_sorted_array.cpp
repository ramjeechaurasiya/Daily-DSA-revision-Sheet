#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>arr1(n),arr2(m);

    // this is method using set

    //   set<int>st;
    // for(int i=0;i<n;i++){
    //     cin>>arr1[i];
    //  st.insert(arr1[i]);
    // }
    // for(int i=0;i<m;i++){
    //     cin>>arr2[i];
    //     st.insert(arr2[i]);
    // }
// vector<int>res(st.begin(),st.end());


//  now usiing map 
// map<int,int>mp;
// for(int i=0;i<n;i++){
//         cin>>arr1[i];
//        mp[arr1[i]]++;
//     }

//     for(int i=0;i<m;i++){
//         cin>>arr2[i];
//        mp[arr2[i]]++;
//     }

//     vector<int>res;

//     for(auto t:mp){
//         res.push_back(t.first);
//     }

//  now approaching for optimal solution with two pointer approach

for(int i=0;i<n;i++){
       cin>>arr1[i];
}

for(int i=0;i<m;i++){
       cin>>arr2[i];
}
sort(arr1.begin(), arr1.end());
sort(arr2.begin(), arr2.end());

 vector<int> Union;

        // Initialize two pointers for both arrays
        int i = 0, j = 0;

        // Loop until either pointer reaches the end
        while (i < n && j < m) {
            // If current element in arr1 is smaller
            if (arr1[i] < arr2[j]) {
                // Add element if union empty or different from last added
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++;  // Move pointer in arr1
            }
            // If current element in arr2 is smaller
            else if (arr2[j] < arr1[i]) {
                // Add element if union empty or different from last added
                if (Union.empty() || Union.back() != arr2[j])
                    Union.push_back(arr2[j]);
                j++;  // Move pointer in arr2
            }
            else {
                // Elements are equal, add once if not duplicate
                if (Union.empty() || Union.back() != arr1[i])
                    Union.push_back(arr1[i]);
                i++; j++;  // Move both pointers
            }
        }

        // Append remaining elements from arr1
        while (i < n) {
            if (Union.empty() || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }

        // Append remaining elements from arr2
        while (j < m) {
            if (Union.empty() || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }

    for(int i=0;i<Union.size();i++){
        cout<<Union[i]<<" ";
    }
    cout<<endl;
    return 0;
}