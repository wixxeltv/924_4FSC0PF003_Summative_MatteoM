#include <gtest/gtest.h>
#include "behaviour_tree/behaviour_tree.h"

// Useless test : Workflow validation
TEST(BehaviourTree, Intro) {
  SUCCEED();
}

TEST(BehaviourTree, Leaf_Basics) {
  auto AlwaysSuccess = [](){return behaviour_tree::Status::kSuccess;};
  auto AlwaysRunning = [](){return behaviour_tree::Status::kRunning;};
  auto AlwaysFailed = [](){return behaviour_tree::Status::kFailure;};

  behaviour_tree::Leaf leaf_q(AlwaysSuccess);
  EXPECT_EQ(leaf_q.Tick(), behaviour_tree::Status::kSuccess);

  behaviour_tree::Leaf leaf_b(AlwaysRunning);
  EXPECT_EQ(leaf_b.Tick(), behaviour_tree::Status::kRunning);

  behaviour_tree::Leaf leaf_c(AlwaysFailed);
  EXPECT_EQ(leaf_c.Tick(), behaviour_tree::Status::kFailure);

}