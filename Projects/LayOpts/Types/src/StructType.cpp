#include "StructType.hpp"
#include "Type.hpp"
#include <cstddef>

using namespace LayOpts;

StructType::StructType(std::string name) : Type(name, Kind::STRUCT, 0, 0) {}

void StructType::addField(const Field&& field) { mFields.push_back(field); }

size_t StructType::getSize() const { return mTotalSize; }
size_t StructType::getAlignment() const { return mMaxAlignment; }
