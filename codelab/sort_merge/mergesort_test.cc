#include "mergesort_soln.h"
//#include "mergesort.h"

#include <vector>
#include <list>
#include <algorithm>
#include "gtest/gtest.h"

using std::vector;
using std::sort;
using std::list;
using std::greater;

namespace codelab {

//////////////////////////////////////////////////////////
// Test V1 merge sort
// 1. Test merge function
TEST(MergeSortV1Test, TestMergeTwoEmptyVectors) {
  vector<int> empty_input;
  vector<int> output;

  merge(empty_input, empty_input, output);
  EXPECT_EQ((size_t) 0, output.size());
}

TEST(MergeSortV1Test, TestMergeEmptyVectorWithNonemptyVector) {
  vector<int> empty_input;
  vector<int> nonempty_input;
  nonempty_input.push_back(1);
  nonempty_input.push_back(2);
  nonempty_input.push_back(3);
  vector<int> output;

  merge(empty_input, nonempty_input, output);
  EXPECT_EQ(nonempty_input, output);
}

TEST(MergeSortV1Test, TestMergeTwoShortNonemptyVector) {
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

  merge(input_a, input_b, output);
  EXPECT_EQ(expected_output, output);
}

TEST(MergeSortV1Test, TestMergeOneShortVectorOneLongVector) {
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

  merge(input_short, input_long, output);
  EXPECT_EQ(expected_output, output);
}

// 2. Test merge sort
TEST(MergeSortV1Test, TestSortEmptyVector) {
  vector<int> empty_input;
  vector<int> output;

  merge_sort(empty_input, output);
  EXPECT_EQ((size_t) 0, output.size());
}

TEST(MergeSortV1Test, TestSortNonemptyVector) {
  int len = 10;
  vector<int> input(len);
  vector<int> output;
  vector<int> expected_output(len);

  for (int i = 0; i < len; i++) {
    input[i] = len - i - 1;
    expected_output[i] = i;
  }
  merge_sort(input, output);
  EXPECT_EQ(expected_output, output);
}

//////////////////////////////////////////////////////////
// Test V2 merge sort
// 1. Test merge function
TEST(MergeSortV2Test, TestMergeTwoEmptyLists) {
  list<int> empty_input;
  list<int> output;

  merge(empty_input.begin(), empty_input.end(),
        empty_input.begin(), empty_input.end(),
        output.begin());
  EXPECT_EQ((size_t) 0, output.size());
}

TEST(MergeSortV2Test, TestMergeEmptyListWithNonemptyList) {
  list<int> empty_input;
  list<int> nonempty_input;
  nonempty_input.push_back(1);
  nonempty_input.push_back(2);
  nonempty_input.push_back(3);
  list<int> output(nonempty_input.size());

  merge(empty_input.begin(), empty_input.end(),
        nonempty_input.begin(), nonempty_input.end(),
        output.begin());
  EXPECT_EQ(nonempty_input, output);
}

TEST(MergeSortV2Test, TestMergeTwoShortNonemptyList) {
  int len = 5;
  list<int> input_a;
  input_a.push_back(1);
  input_a.push_back(2);
  input_a.push_back(3);
  list<int> input_b;
  input_b.push_back(4);
  input_b.push_back(5);

  list<int> output(5);
  list<int> expected_output;
  for (int i = 0; i < len; i++) {
    expected_output.push_back(i+1);
  }

  merge(input_a.begin(), input_a.end(),
        input_b.begin(), input_b.end(),
        output.begin());
  EXPECT_EQ(expected_output, output);
}

}  // namespace codelab
