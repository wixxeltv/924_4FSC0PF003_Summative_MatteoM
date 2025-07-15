#ifndef NO_LOOP_H
#define NO_LOOP_H

#include "composite.h"

namespace behaviour_tree {

class NoLoop final : public Composite {
public:
  Status Tick() override;
};

inline Status NoLoop::Tick() {
  // SELECT ONE CHILD AFTER THE OTHER UNTIL EVERY CHILD SUCCEED
  // RETURN SUCCESS IF ALL CHILDREN RETURN SUCCESS
  // RETURN FAILURE IF ANY CHILDREN RETURN FAILURE
  // RETURN RUNNING IF ANY CHILDREN RETURN RUNNING
  if (children_.empty()) {
    return Status::kFailure;
  }

  while (current_child_ < children_.size())
  {
    Status status = children_[current_child_]->Tick();
    if (status == Status::kSuccess) {
      current_child_++;
    }else {
      return status;
    }
  };

  return Status::kSuccess;

}

}

#endif //SEQUENCE_H
