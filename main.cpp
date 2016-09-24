
#include <vector>
#include <unordered_map>
#include "file_process.h"

using namespace std;

int find_kth(int A[], int m, int B[], int n, int k) {
    //always assume that m is equal or smaller than n
    if (m > n) return find_kth(B, n, A, m, k);
    if (m == 0) return B[k - 1];
    if (k == 1) return min(A[0], B[0]);
    //divide k into two parts
    int ia = min(k / 2, m), ib = k - ia;
    if (A[ia - 1] < B[ib - 1])
        return find_kth(A + ia, m - ia, B, n, k - ia);
    else if (A[ia - 1] > B[ib - 1])
        return find_kth(A, m, B + ib, n - ib, k - ib);
    else
        return A[ia - 1];
}

int longestConsective(const vector<int> &num){
    unordered_map<int, bool> used;
    for(auto i : num)   used[i] = false;
    int longest = 0;
    for(auto i : num){
        if(!used[i]){
            int m = i , n = i;
            while (used.find(++m) != used.end()) used[m] = true;//be careful
            while (used.find(--n) != used.end()) used[n] = true;
            used[i] = true;
            longest = max(m - n - 1 , longest);// not m-n+1
        }
    }
    return longest;
    
}

vector<int> twoSum(const vector<int> &num , int target){

    unordered_map<int,int> mapping;
    vector<int> result;//不能返回引用，这是局部变量
    for (int i = 0; i < num.size(); ++i) {
        mapping[num[i]] = i;
    }
    for (int j = 0; j < num.size(); ++j) {
        const int gap = target - num[j];
        if(mapping.find(gap) != mapping.end() && mapping[gap] > j){
            result.push_back(j+1);
            result.push_back(mapping[gap]+1);
        }
    }
    return result;

}

int main() {
    //string s;
    //vector<string> vector1;
    ifstream input(string("file1.txt"));
    ifstream map_file(string("transfile.txt"));
    if(map_file && input)   word_transform(map_file, input);
    else    cerr << "can not open the file!" << endl;
    map_file.close();
    input.close();
    vector<int> num{1,3,5,2,4,34,33,6,7,8};
    cout << longestConsective(num) << endl;
    vector<int> num1(twoSum(num,9));
    for(auto j : num1)
        cout << j << "   ";
    cout << endl;
   /* while (cin >> s && s!=";"){
        vector1.push_back(s);
        cout << s << endl;
    }
    cout << vector1.back() << "   " << vector1.front() << endl;

    */



    int a[] = {1,2,3,3,5}, b[] = {1,2,2,3};
    cout << find_kth(a,5,b,4,6) << endl;
    return 0;
}

