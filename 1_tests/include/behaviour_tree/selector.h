#ifndef SELECTOR_H
#define SELECTOR_H

#include "composite.h"

namespace behaviour_tree {

class Selector final : public Composite {
  public:
    Status Tick() override;
};

inline Status Selector::Tick() {
  // SELECT THE FIRST WHO DON'T FAIL
  // RETURN FAILURE IF ALL CHILDREN RETURN FAILURE
  // RETURN SUCCESS IF ANY CHILDREN RETURN SUCCESS
  // RETURN RUNNING IF ANY CHILDREN RETURN RUNNING
  if (children_.empty()) {
    return Status::kFailure;
  }

  while (current_child_ < children_.size())
  {
    Status status = children_[current_child_]->Tick();
    if (status == Status::kFailure) {
      current_child_++;
    }else {
      return status;
    }
  }

  Reset();
  return Status::kFailure;

}

}

#endif //SELECTOR_H
