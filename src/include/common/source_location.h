#pragma once

#include <string>
#include <string_view>

#include "common/ostream.h"
#include "common/nonnull.h"

namespace common {

class SourceLocation {
 public:
  // The filename should be eternal or arena-allocated to eliminate copies.
  constexpr SourceLocation(const char* filename, int line_num)
      : filename_(filename), line_num_(line_num) {}
  SourceLocation(Nonnull<const std::string*> filename, int line_num)
      : filename_(filename->c_str()), line_num_(line_num) {}

  SourceLocation(const SourceLocation&) = default;
  SourceLocation(SourceLocation&&) = default;
  auto operator=(const SourceLocation&) -> SourceLocation& = default;
  auto operator=(SourceLocation&&) -> SourceLocation& = default;

  auto operator==(SourceLocation other) const -> bool {
    return filename_ == other.filename_ && line_num_ == other.line_num_;
  }

  void Print(llvm::raw_ostream& out) const {
    out << filename_ << ":" << line_num_;
  }
  LLVM_DUMP_METHOD void Dump() const { Print(llvm::errs()); }

 private:
  std::string_view filename_;
  int line_num_;
};

}  // namespace common
