#pragma once

#include "Type.hpp"
#include <memory>
namespace LayOpts {
	class ArrayType : public Type {
	public:
		ArrayType(std::shared_ptr<Type> type, size_t count);
	};
} // namespace LayOpts
