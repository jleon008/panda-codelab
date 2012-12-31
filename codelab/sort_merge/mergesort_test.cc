#include "mergesort_soln.h"
#include "mergesort.h"

#include <vector>
#include <list>
#include <algorithm>
#include "gtest/gtest.h"

using std::vector;
using std::sort;
using std::list;
using std::greater;

using codelab_soln::merge;
using codelab_soln::merge_sort;

namespace codelab_test {

//////////////////////////////////////////////////////////
// Test V0 merge sort
// 1. Test merge function
TEST(MergeSortV0Test, TestMergeTwoEmptyVectors) {
  vector<int> empty_input;
  vector<int> output;

  merge(empty_input, empty_input, &output);
  EXPECT_EQ((size_t) 0, output.size());
}

TEST(MergeSortV0Test, TestMergeEmptyVectorWithNonemptyVector) {
  vector<int> empty_input;
  vector<int> nonempty_input;
  nonempty_input.push_back(1);
  nonempty_input.push_back(2);
  nonempty_input.push_back(3);
  vector<int> output;

  merge(empty_input, nonempty_input, &output);
  EXPECT_EQ(nonempty_input, output);
}

TEST(MergeSortV0Test, TestMergeTwoShortNonemptyVector) {
  int len = 10;
  vector<int> input_a(len);
  vector<int> input_b(len);
  vector<int> output(2 * len);
  vector<int> expected_output(2 * len);

  for (int i = 0; i < len; i++) {
    input_a[i] = input_b[i] = i;
    expected_output[2 * i] = i;
    expected_output[2 * i + 1] = i;
  }

  merge(input_a, input_b, &output);
  EXPECT_EQ(expected_output, output);
}

TEST(MergeSortV0Test, TestMergeOneShortVectorOneLongVector) {
  int short_len = 10;
  int long_len = 100;
  vector<int> input_short(short_len);
  vector<int> input_long(long_len);
  vector<int> output(short_len + long_len);
  vector<int> expected_output(short_len + long_len);

  for (int i = 0; i < short_len; i++) {
    input_short[i] = expected_output[i] = i;
  }
  for (int i = 0; i < long_len; i++) {
    input_long[i] = expected_output[short_len + i] = i;
  }
  sort(expected_output.begin(), expected_output.end());

  merge(input_short, input_long, &output);
  EXPECT_EQ(expected_output, output);
}

// 2. Test merge sort
TEST(MergeSortV0Test, TestSortEmptyVector) {
  vector<int> empty_input;
  vector<int> output;

  merge_sort(empty_input, &output);
  EXPECT_EQ((size_t) 0, output.size());
}

TEST(MergeSortV0Test, TestSortSingleElemVector) {
  vector<int> single_elem_input;
  single_elem_input.push_back(1);
  vector<int> output;
  merge_sort(single_elem_input, &output);
  EXPECT_EQ(single_elem_input, output);
}

TEST(MergeSortV0Test, TestSortNonemptyVector) {
  int len = 10;
  vector<int> input(len);
  vector<int> output;
  vector<int> expected_output(len);

  for (int i = 0; i < len; i++) {
    input[i] = len - i - 1;
    expected_output[i] = i;
  }
  merge_sort(input, &output);
  EXPECT_EQ(expected_output, output);
}

}  // namespace codelab
