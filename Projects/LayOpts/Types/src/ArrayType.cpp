#include "ArrayType.hpp"
#include "Type.hpp"
#include <string>

using namespace LayOpts;

ArrayType::ArrayType(std::shared_ptr<Type> type, size_t count)
    : Type(
          type->getName() + "[" + std::to_string(count) + "]",
          Kind::ARRAY,
          type->getSize() * count,
          type->getAlignment()
      ) {}
