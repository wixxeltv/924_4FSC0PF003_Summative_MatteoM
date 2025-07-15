#ifndef STATUS_H
#define STATUS_H

namespace behaviour_tree {

enum class Status {
  kSuccess,
  kFailure,
  kRunning
};

}
#endif // STATUS_H