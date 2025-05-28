#include "PrimitiveType.hpp"
#include "Type.hpp"

using namespace LayOpts;

PrimitiveType::PrimitiveType(std::string name, size_t size, size_t alignment)
    : Type(name, Kind::PRIMITIVE, size, alignment) {}
