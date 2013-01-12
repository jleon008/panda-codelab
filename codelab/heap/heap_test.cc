#include "heap_soln.h"
#include "heap.h"

#include "gtest/gtest.h"

using codelab_soln::Heap;

namespace codelab_test {

class HeapTest : public testing::Test {
 public:
  HeapTest() : max_size_(5), heap_(), heap_with_size_(max_size_) { }
  virtual ~HeapTest() { }

 protected:
  virtual void SetUp() {
    heap_.clear();
    heap_with_size_.clear();
  }

  const size_t max_size_;
  Heap<int> heap_;
  Heap<int> heap_with_size_;
};

TEST_F(HeapTest, TestEmpty) {
  EXPECT_TRUE(heap_.empty());
  heap_.push(1);
  EXPECT_FALSE(heap_.empty());

  EXPECT_TRUE(heap_with_size_.empty());
  heap_with_size_.push(1);
  EXPECT_FALSE(heap_with_size_.empty());
}

TEST_F(HeapTest, TestPushAndPop) {
  heap_.push(2);
  heap_.push(1);
  heap_.push(3);
  EXPECT_EQ(3, heap_.top());
  EXPECT_EQ(3, heap_.size());
  heap_.pop();
  EXPECT_EQ(2, heap_.top());
  EXPECT_EQ(2, heap_.size());

  for (size_t i = 0; i < max_size_; ++i) {
    heap_with_size_.push(i+1);
  }
  EXPECT_FALSE(heap_with_size_.push(max_size_));
  EXPECT_FALSE(heap_with_size_.push(max_size_+1));
  EXPECT_EQ(max_size_, heap_with_size_.top());
  EXPECT_EQ(max_size_, heap_with_size_.size());

  EXPECT_TRUE(heap_with_size_.push(max_size_-1));
  EXPECT_EQ(max_size_-1, heap_with_size_.top());
  EXPECT_EQ(max_size_, heap_with_size_.size());

  heap_with_size_.pop();
  EXPECT_EQ(max_size_-1, heap_with_size_.top());
  EXPECT_EQ(max_size_-1, heap_with_size_.size());
}

}  // namespace codelab
