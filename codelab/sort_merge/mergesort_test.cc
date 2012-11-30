#include "mergesort_soln.h"
//#include "mergesort.h"

#include <vector>
#include "gtest/gtest.h"

using std::vector;

namespace codelab {

//////////////////////////////////////////////////////////
// Test V1 merge sort
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

TEST(MergeSortV1Test, TestSortEmptyVector) {
  vector<int> empty_input;
  vector<int> output;

  merge_sort(empty_input, output);
  EXPECT_EQ((size_t) 0, output.size());
}


}
