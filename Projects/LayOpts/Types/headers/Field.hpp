#pragma once

#include "Type.hpp"
#include <cstddef>
#include <memory>

namespace LayOpts {
	class Field {
	public:
		Field(std::string name, std::shared_ptr<Type> type, size_t offset, size_t size, size_t alignment);

		std::string getName() const;
		std::shared_ptr<Type> getType() const;
		size_t getOffset() const;
		void setOffset(size_t offset);
		size_t getSize() const;
		size_t getAlignment() const;

	private:
		std::string mName;
		std::shared_ptr<Type> mType;
		size_t mOffset;
		size_t mSize;
		size_t mAlignment;
	};
} // namespace LayOpts
