#pragma once

namespace pxcompiler {

struct Pos {
    int _line;
    int _col;
    int _offset;
    bool operator==(const Pos &pos) const { return _line == pos._line && _col == pos._col && _offset == pos._offset; }
};

} // namespace pxcompiler