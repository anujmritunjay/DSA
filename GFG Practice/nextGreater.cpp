#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void printVector(vector<long long>& vec) {
    for (const auto& element : vec) {
        cout << element << " ";
    }
}

vector<long long>nextLargerElement(vector<long long>arr, int n){
    vector<long long> ans(n,-1);
    stack<long long> st;

    for(int i = n-1; i>=0; i--){

        while(st.empty() == false && st.top() <=arr[i]){
            st.pop();
        }

        if(st.empty()==false) ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

vector<long long>nextLargerElementBruteForce(vector<long long> arr, int n){
    vector<long long> res;
    for(int i = 0; i<n; i++){
        int found = 0;
        for(int j = i+1; j<n; j++){
            if(arr[i] < arr[j]){
                res.push_back(arr[j]);
                found = 1;
                break;
            }
        }
        if(found == 0){
            res.push_back(-1);
        }
    }
    return res;
}

int main(){
   int n;
   cin>>n;
   vector<long long> arr(n);
   for(int i = 0; i<n; i++){
    cin>>arr[i];
   }
   vector<long long> res = nextLargerElement(arr, n); // Brute 
   printVector(res);
   
   return 0;
}