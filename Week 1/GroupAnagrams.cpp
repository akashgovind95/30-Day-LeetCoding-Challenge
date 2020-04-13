/*
Given an array of strings, group anagrams together.

Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
All inputs will be in lowercase.
The order of your output does not matter.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int > aMap;
        vector<vector<string>> result;
        int count = -1;
        for (auto str : strs) {
            
            string temp = str;
            sort(temp.begin(), temp.end());
            
            if (aMap.count(temp)) 
                result[aMap[temp]].push_back(str);
            
            else {
                result.push_back({str});
                aMap[temp] = ++count;
            }
        }
        
        return result;
    }
};

int main()
{
    Solution obj;
    vector<string> vec = {"ate","eat","tea","nat","tan","bat"};
    vector<vector<string>> res;
    res = obj.groupAnagrams(vec);
    for(auto i : res){
        for(auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}