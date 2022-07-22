#include "source_location.h"

std::ostream& operator<< (std::ostream &out, const SourceLocation& loc) {
    out << str();
    return out;
}
