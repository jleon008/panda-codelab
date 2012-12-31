#ifndef CODELAB_MERGESORT_SOLN_H_
#define CODELAB_MERGESORT_SOLN_H_

#include <iostream>
#include <vector>
using std::vector;

namespace codelab_soln {

///////////////////////////////////////////
// V0 merge sort
void merge(const vector<int>& a, const vector<int>& b, vector<int>* out) {
  if (out == NULL) {
    return;
  }
  out->resize(a.size() + b.size());
  vector<int>::const_iterator a_iter = a.begin();
  vector<int>::const_iterator b_iter = b.begin();
  vector<int>::iterator out_iter = out->begin();
  while (a_iter != a.end() && b_iter != b.end()) {
    if (*a_iter <= *b_iter) {
      *(out_iter++) = *(a_iter++);
    } else {
      *(out_iter++) = *(b_iter++);
    }
  }

  while (a_iter != a.end()) {
    *(out_iter++) = *(a_iter++);
  }
  while (b_iter != b.end()) {
    *(out_iter++) = *(b_iter++);
  }
}

void merge_sort(const vector<int>& input, vector<int>* output) {
  if (output == NULL) {
    return;
  }
  if (input.size() < 2) {
    *output = input;
    return;
  }
  size_t middle = input.size() / 2;
  vector<int> left(input.begin(), input.begin() + middle);
  vector<int> sorted_left;
  merge_sort(left, &sorted_left);

  vector<int> right(input.begin() + middle, input.end());
  vector<int> sorted_right;
  merge_sort(right, &sorted_right);

  merge(sorted_left, sorted_right, output);
}

}  // namespace codelab

#endif  // CODELAB_MERGESORT_SOLN_H_
