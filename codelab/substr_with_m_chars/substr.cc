#include "substr.h"
#include <algorithm>

using std::string;
using std::swap;

namespace codelab {

int substr2chars(const string& str, string* substr) {
  if (str.empty()) {
    *substr = "";
    return 0;
  }
  char pre_ch = str[0];
  int cur_soln_start = 0;
  char cur_ch;
  int cur_ch_start = str.size();
  for (int i = 1; i < str.size(); i++) {
    if (pre_ch != str[i]) {
      cur_ch = str[i];
      cur_ch_start = i;
      break;
    }
  }
  // Check if it's single char string.
  if (cur_ch_start == str.size()) {
    *substr = str;
    return str.size();
  }

  // For longest substr with 2 chars.
  int best_start = 0;
  int best_len = cur_ch_start + 1;
  for (int i = cur_ch_start + 1; i < str.size(); i++) {
    char ch = str[i];
    if (ch == cur_ch) {
      // do nothing.
    } else if (ch == pre_ch) {
      swap(cur_ch, pre_ch);
      cur_ch_start = i;
    } else {
      if (i - cur_soln_start > best_len) {
	// find better soln.
	best_start = cur_soln_start;
	best_len = i - cur_soln_start;
      }
      cur_soln_start = cur_ch_start;
      pre_ch = cur_ch;
      cur_ch = ch;
      cur_ch_start = i;
    }
  }
  if (str.size() - cur_soln_start > best_len) {
    best_start = cur_soln_start;
    best_len = str.size() - cur_soln_start;
  }  
  *substr = str.substr(best_start, best_len);
  return best_len;
}

}
