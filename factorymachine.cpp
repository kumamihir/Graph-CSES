#include <bits/stdc++.h>
using namespace std;
long long  prod(vector<int> x , long long  mid , int size){
    long long ans = 0;
    for(int i = 0; i < size; i++){
        long long  tem = mid / x[i];
        ans += tem;
    }
    return ans;
}
 
int main() {
    int n ;
    long long t;
    cin >>n >> t;
    vector<int> mac(n);
    for(int i = 0; i < n; i++){
        cin >> mac[i];
    }
    sort(mac.begin() , mac.end());
    long long low = 1;
    long long high = (long long)t * mac[0];
    long long  count = high;
    while(low <= high){
        long long  mid = low + ((high - low)/2);
        long long  a = prod(mac , mid , n);
        if( a >= t ) {
            count = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    cout << count;
 
    return 0;
}