#include "lcp.h"
#include <algorithm>

using std::string;
using std::vector;
using std::min;

namespace codelab {

string longest_common_prefix(const vector<string>& strs) {
  if (strs.empty()) {
    return "";
  }
  size_t max_possible_len = strs[0].size();
  for (size_t i = 1; i < strs.size(); ++i) {
    max_possible_len = min(max_possible_len, strs[i].size());
  }
  bool is_common_for_all = true;
  size_t end = 0;
  while (end < max_possible_len) {
    char ch = strs[0][end];
    for (size_t i = 1; i < strs.size(); ++i) {
      if (ch != strs[i][end]) {
        is_common_for_all = false;
        break;
      }
    }
    if (is_common_for_all == false) {
      break;
    }
    ++end;
  }
  return string(strs[0].begin(), strs[0].begin() + end);
}

}
