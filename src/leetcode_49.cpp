#include "leetcode_utils.h"

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (const string& str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      mp[key].push_back(str);
    }

    vector<vector<string>> ret;
    for (auto& [key, group] : mp) {
      ret.push_back(group);
    }
    return ret;
  }
};

int main() {
  vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
  Solution so;
  so.groupAnagrams(strs);
  return 0;
}