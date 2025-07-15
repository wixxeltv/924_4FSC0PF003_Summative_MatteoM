#ifndef STATUS_H
#define STATUS_H

namespace behaviour_tree {

enum class Status {
  kSuccess,
  kFailure,
  kRunning
};

// Helpers ---------------------------------------------------------------------------------------
inline std::string status_to_str(const Status& status) {
  switch (status) {
  case Status::kSuccess:
    return "Success";
  case Status::kFailure:
    return "Failure";
  case Status::kRunning:
    return "Running";
  }
  return "Unknown";
}

}
#endif // STATUS_H