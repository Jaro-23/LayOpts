#include "Type.hpp"

using namespace LayOpts;

Type::Type(std::string name, Kind kind, size_t size, size_t alignment)
    : mName{name}, mKind{kind}, mSize{size}, mAlignment{alignment} {}

std::string Type::getName() const { return mName; }
Type::Kind Type::getKind() const { return mKind; }
size_t Type::getSize() const { return mSize; }
size_t Type::getAlignment() const { return mAlignment; }
