#include "substr.h"
#include "gtest/gtest.h"

using std::cout;
using std::endl;
using std::string;
using codelab::substr2chars;

namespace codelab_test {

class SubstrTest : public testing::Test {
 protected:
  virtual void SetUp() {
    substr_.clear();
  }
  virtual void TearDown() {
    cout << "Returned substr: " << substr_ << endl;
  }

  string substr_;
};

TEST_F(SubstrTest, TestWithEmptyStr) {
  string str = "";
  EXPECT_EQ(str.size(), substr2chars(str, &substr_));
}

TEST_F(SubstrTest, TestWithSingleCharStr) {
  const string str = "aaaaaa";
  EXPECT_EQ(str.size(), substr2chars(str, &substr_));
  EXPECT_EQ(str, substr_);
}

TEST_F(SubstrTest, TestWithAlternate2CharStr) {
  const string str = "abababa";
  EXPECT_EQ(str.size(), substr2chars(str, &substr_));
  EXPECT_EQ(str, substr_);
}

TEST_F(SubstrTest, TestWith2CharStr) {
  const string str = "aaabbbb";
  EXPECT_EQ(str.size(), substr2chars(str, &substr_));
  EXPECT_EQ(str, substr_);
}

TEST_F(SubstrTest, TestWithAlternate3charStr) {
  const string str = "abcabcab";
  EXPECT_EQ(2, substr2chars(str, &substr_));
}

TEST_F(SubstrTest, TestWith3CharStr) {
  const string str = "abbcccdddde";
  EXPECT_EQ(7, substr2chars(str, &substr_));
  EXPECT_EQ("cccdddd", substr_);
}

}
