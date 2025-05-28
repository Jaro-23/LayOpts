#pragma once

#include "Type.hpp"
#include <cstddef>
#include <memory>
#include <vector>

namespace LayOpts {
	class Parser {
	public:
		void reset();
		std::shared_ptr<Type> parseNext();
		std::vector<std::shared_ptr<Type>> parseAll();

	protected:
		std::vector<std::shared_ptr<Type>> mTypes{};
		size_t mIndex = 0;
	};
} // namespace LayOpts
