#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;

bool cmp (pp & p1, pp &p2){         // p1.fist->value     p1.second-> weight
    double r1 = (p1.first *1.0)/(p1.second*1.0);
    double r2 = (p2.first *1.0)/(p2.second*1.0);

    return r1>r2;
    // if the above condition is true then the first element will be picked     p1
    // if the above condition is false then the second element will be picked   p2
}

// trick 
// > (big first and then small ) -> descending order
// < (small first and then big) -> ascending order

double fractionalKnapsack(vector<int> & value , vector<int> & weight , int n , int W){

    // Time : O(log n)

    vector<pp> arr;         // knapsack value , weight pair
    for(int i = 0 ; i< value.size();i++){
        arr.push_back({value[i],weight[i]});
    }

    sort(arr.begin(),arr.end(),cmp);

    double profit = 0; 

    for(int i = 0 ; i< arr.size();i++){
        if(arr[i].second <=W){                  //pick fully
            profit += arr[i].first;
            W -= arr[i].second;
        } else {                                //pick partially
            profit += ((arr[i].first*1.0)/arr[i].second*1.0) * W;
            W=0; 
            break;          // if wright becomes zero then no need to traverse more
        }                     
    }

    return profit;

}

// value = profit / weight
 


int main(){

    vector<int> value  = { 60,100,120  };
    vector<int> weight  = { 10,20,30 };
    int W= 50;
    int n =3;

    cout<<fractionalKnapsack(value,weight, n , W);

    return 0;
}
