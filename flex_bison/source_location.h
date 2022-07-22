// Part of the pxc Language project, under the Apache License v2.0 with LLVM
// Exceptions. See /LICENSE for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef PXC_SOURCE_LOCATION_H_
#define PXC_SOURCE_LOCATION_H_

#include <string>
#include <string_view>

#include <iostream>
#include <sstream>

namespace pxc {

class SourceLocation {
 public:
  // The filename should be eternal or arena-allocated to eliminate copies.
  constexpr SourceLocation(const char* filename, int line_num)
      : filename_(filename), line_num_(line_num) {}
  SourceLocation(const std::string filename, int line_num)
      : filename_(filename->c_str()), line_num_(line_num) {}

  SourceLocation(const SourceLocation&) = default;
  SourceLocation(SourceLocation&&) = default;
  auto operator=(const SourceLocation&) -> SourceLocation& = default;
  auto operator=(SourceLocation&&) -> SourceLocation& = default;

  auto operator==(SourceLocation other) const -> bool {
    return filename_ == other.filename_ && line_num_ == other.line_num_;
  }

  void Print(std::ostream& out) const {
    out << filename_ << ":" << line_num_;
  }
  void Dump() const { Print(std::cerr); }

  std::string str() {
    std::stringstream oss;
    oss << filename_ << ":" << line_num_;
    return oss.str();
  }
  friend std::ostream& operator<< (std::ostream &out, const SourceLocation& loc);
 private:
  std::string_view filename_;
  int line_num_;
};


}  // namespace pxc

#endif  // PXC_SOURCE_LOCATION_H_
