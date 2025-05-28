#include "Field.hpp"
#include <memory>

using namespace LayOpts;

Field::Field(std::string name, std::shared_ptr<Type> type, size_t offset, size_t size, size_t alignment)
    : mName{name}, mType{type}, mOffset{offset}, mSize{size}, mAlignment{alignment} {}

std::string Field::getName() const { return mName; }
std::shared_ptr<Type> Field::getType() const { return mType; }
size_t Field::getOffset() const { return mOffset; }
void Field::setOffset(size_t offset) { mOffset = offset; }
size_t Field::getSize() const { return mSize; }
size_t Field::getAlignment() const { return mAlignment; }
