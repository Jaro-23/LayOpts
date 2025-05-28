#pragma once

#include "Type.hpp"
#include <string>

namespace LayOpts {
	class PrimitiveType : public Type {
	public:
		PrimitiveType(std::string name, size_t size, size_t alignment);
	};
} // namespace LayOpts
