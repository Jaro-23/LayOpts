#include "Parser.hpp"
#include <memory>

using namespace LayOpts;

void Parser::reset() { mIndex = 0; }
std::shared_ptr<Type> Parser::parseNext() { return mTypes.at(mIndex); }
std::vector<std::shared_ptr<Type>> Parser::parseAll() { return mTypes; }
