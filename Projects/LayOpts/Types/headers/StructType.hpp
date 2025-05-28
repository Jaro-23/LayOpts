#pragma once

#include "Field.hpp"
#include "Type.hpp"
#include <cstddef>
#include <vector>

namespace LayOpts {
	class StructType : public Type {
	public:
		StructType(std::string name);
		void addField(const Field&& field);

		size_t getSize() const override;
		size_t getAlignment() const override;

	private:
		std::vector<Field> mFields;
		size_t mTotalSize;
		size_t mMaxAlignment;
	};
} // namespace LayOpts
