#include "lcp.h"
#include "gtest/gtest.h"

using std::string;
using std::vector;
using codelab::longest_common_prefix;

namespace codelab_test {

TEST(LCPTest, TestWithEmptyInputVector) {
  vector<string> empty_input;
  EXPECT_EQ("", longest_common_prefix(empty_input));
}

TEST(LCPTest, TestWithSingleElemInput) {
  const string str = "Single elem";
  vector<string> strs;
  strs.push_back(str);
  EXPECT_EQ(str, longest_common_prefix(strs));
}

TEST(LCPTest, TestWithIdenticalStringsInput) {
  const string str = "Identical string";
  const size_t kNumElem = 5;
  vector<string> strs;
  for (size_t i = 0; i < kNumElem; ++i) {
    strs.push_back(str);
  }
  EXPECT_EQ(str, longest_common_prefix(strs));
}

TEST(LCPTest, TestWithDiffStringsInput) {
  vector<string> strs;
  strs.push_back("aaaaab");
  strs.push_back("aaabaa");
  strs.push_back("aaaaaaaaa");
  strs.push_back("aa");
  EXPECT_EQ("aa", longest_common_prefix(strs));
}

TEST(LCPTest, TestWithPossiblySlowInput) {
  // This test case reminds you the running time of algorithms.
  const string all_a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  const string all_b = "bbbbbbbbbbbbbbbbbbbbbbbbb";
  vector<string> strs;
  const size_t kBigNum = 10;
  for (size_t i = 0; i < kBigNum; ++i) {
    strs.push_back(all_a);
  }
  strs.push_back(all_b);
  EXPECT_EQ("", longest_common_prefix(strs));
}

}
