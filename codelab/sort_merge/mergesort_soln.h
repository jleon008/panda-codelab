#ifndef CODELAB_MERGESORT_SOLN_H_
#define CODELAB_MERGESORT_SOLN_H_

#include <vector>
#include <algorithm>

using std::vector;
using std::copy;

namespace codelab {

/////////////////////////////////////////////////////////////////////////////
// V1 merge sort
// 1. Use vector<T> only
// 2. Assume T has operator< overloaded
template<typename T>
void merge_sort(const vector<T>& input, vector<T>& output) {
  size_t len = input.size();
  output.resize(input.size());
  if (len == 0 || len == 1) {
    copy(input.begin(), input.end(), output.begin());
    return;
  }

  size_t len_left = len / 2;
  vector<T> input_left(len_left);
  vector<T> output_left(len_left);
  copy(input.begin(), input.begin() + len_left, input_left.begin());
  merge_sort(input_left, output_left);

  vector<T> input_right(len - len_left);
  vector<T> output_right(len - len_left);
  copy(input.begin() + len_left, input.end(), input_right.begin());
  merge_sort(input_right, output_right);

  merge(output_left, output_right, output);
}

template<typename T>
void merge(const vector<T>& a, const vector<T>& b, vector<T>& merged) {
  merged.resize(a.size() + b.size());

  typename vector<T>::const_iterator a_iter = a.begin();
  typename vector<T>::const_iterator b_iter = b.begin();
  typename vector<T>::iterator merged_iter = merged.begin();

  while (a_iter != a.end() &&
         b_iter != b.end()) {
    if (*a_iter < *b_iter) {
      *merged_iter = *a_iter;
      ++a_iter;
    } else {
      *merged_iter = *b_iter;
      ++b_iter;
    }
    ++merged_iter;
  }

  while (a_iter != a.end()) {
    *merged_iter = *a_iter;
    ++a_iter, ++merged_iter;
  }

  while (b_iter != b.end()) {
    *merged_iter = *b_iter;
    ++b_iter, ++merged_iter;
  }
}

}  // codelab

#endif  // CODELAB_MERGESORT_SOLN_H_
