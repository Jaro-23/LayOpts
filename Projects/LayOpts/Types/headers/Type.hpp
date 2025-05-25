#pragma once

#include <cstddef>
#include <string>
namespace LayOpts {
	class Type {
	public:
		enum class Kind { PRIMITIVE, ARRAY, STRUCT };
		Type(std::string name, Kind kind, size_t size, size_t alignment);

		virtual std::string getName() const;
		virtual Kind getKind() const;
		virtual size_t getSize() const;
		virtual size_t getAlignment() const;

	private:
		std::string mName;
		Kind mKind;
		size_t mSize;
		size_t mAlignment;
	};
} // namespace LayOpts
