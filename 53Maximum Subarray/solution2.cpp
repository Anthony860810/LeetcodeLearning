/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums){
    int ans = nums[0];
    int tmp = nums[0];
    for (auto num :nums){
        cout<<"num: "<< num<<endl;
        cout<<tmp<<endl;
        tmp = num > (tmp+num) ? num : (tmp+num);
        ans = tmp > ans ? tmp : ans;
    }
    return ans;
}

int main()
{
    vector<int> array = {2, 4, 5, -13, 9, 3, 10};
    cout<<maxSubArray(array);
    return 0;
}
