#ifndef CODELAB_MERGESORT_SOLN_H_
#define CODELAB_MERGESORT_SOLN_H_

#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using std::vector;
using std::copy;
using std::less;
using std::iterator_traits;

namespace codelab {

/////////////////////////////////////////////////////////////////////////
// V1 merge sort
// 1. Use vector<T> only
// 2. Assume T has operator< overloaded
// 3. Allocate vectors on stack (better to do on heap with scoped ptr).
template<typename T>
void merge_sort(const vector<T>& input, vector<T>& output) {
  size_t len = input.size();
  output.resize(len);
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

/////////////////////////////////////////////////////////////////////////
// V2 merge sort
// 3. Allocate vectors on stack (better to do on heap with scoped ptr).
template<typename InputIterator,
         typename OutputIterator,
         typename Comparator>
void merge_sort(InputIterator begin,
                InputIterator end,
                OutputIterator output) {
  typedef typename iterator_traits<InputIterator>::value_type T;
  // TODO(zhsun):
}

template<typename InputIterator,
         typename OutputIterator>
void merge(InputIterator begin1, InputIterator end1,
           InputIterator begin2, InputIterator end2,
           OutputIterator output) {
  merge(begin1, end1, begin2, end2, output,
        less<typename iterator_traits<InputIterator>::value_type>());
}

template<typename InputIterator,
         typename OutputIterator,
         typename Comparator>
void merge(InputIterator begin1, InputIterator end1,
           InputIterator begin2, InputIterator end2,
           OutputIterator output, Comparator comparator) {
  while (begin1 != end1 &&
         begin2 != end2) {
    if (comparator(*begin1, *begin2)) {
      *output++ = *begin1++;
    } else {
      *output++ = *begin2++;
    }
  }

  while (begin1 != end1) {
    copy(begin1, end1, output);
  }

  while (begin2 != end2) {
    copy(begin2, end2, output);
  }
}

}  // codelab

#endif  // CODELAB_MERGESORT_SOLN_H_
