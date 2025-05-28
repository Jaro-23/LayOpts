#include "ClangParser.hpp"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Tooling/CompilationDatabase.h"
#include "clang/Tooling/Tooling.h"
#include <iostream>
#include <memory>

using namespace LayOpts;

ClangParser::ClangParser(const std::string& path, const std::string& version) {
	clang::tooling::FixedCompilationDatabase comps(".", {"-std=" + version});
	clang::tooling::ClangTool tool(comps, {path});
	tool.run(clang::tooling::newFrontendActionFactory<ClangFrontend>().get());
}

// ClangVisitor
ClangVisitor::ClangVisitor(clang::ASTContext* context) : mContext(context) {}
bool ClangVisitor::VisitCXXRecordDecl(clang::CXXRecordDecl* decl) {
	if (!decl->isThisDeclarationADefinition()) return true;

	if (decl->isStruct() || decl->isClass()) {
		std::cout << (decl->isStruct() ? "Struct: " : "Class: ")
		          << decl->getNameAsString() << "\n";

		for (const auto* field : decl->fields()) {
			clang::QualType qt    = field->getType();
			std::string typeStr   = qt.getAsString();
			std::string fieldName = field->getNameAsString();
			std::cout << "  Field: " << fieldName << " : " << typeStr << "\n";
		}
		std::cout << "\n";
	}
	return true;
}

// ClangConsumer
ClangConsumer::ClangConsumer(clang::ASTContext* context) : mVisitor(context) {}
void ClangConsumer::HandleTranslationUnit(clang::ASTContext& context) {
	mVisitor.TraverseDecl(context.getTranslationUnitDecl());
}

// ClangFrontend
std::unique_ptr<clang::ASTConsumer>
    ClangFrontend::CreateASTConsumer(clang::CompilerInstance& CI, llvm::StringRef file) {
	return std::make_unique<ClangConsumer>(&CI.getASTContext());
}
