#pragma once

#include "Parser.hpp"
#include "clang/AST/ASTConsumer.h"

#include <clang/AST/ASTContext.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Basic/SourceManager.h>
#include <clang/Frontend/FrontendActions.h>
#include <clang/Tooling/CommonOptionsParser.h>
#include <clang/Tooling/Tooling.h>
#include <llvm/Support/CommandLine.h>

#include <memory>

namespace LayOpts {
	class ClangParser : public Parser {
	public:
		ClangParser(const std::string& path, const std::string& version);
	};

	class ClangVisitor : public clang::RecursiveASTVisitor<ClangVisitor> {
	public:
		explicit ClangVisitor(clang::ASTContext* context);
		bool VisitCXXRecordDecl(clang::CXXRecordDecl* decl);

	private:
		clang::ASTContext* mContext;
	};

	class ClangConsumer : public clang::ASTConsumer {
	public:
		explicit ClangConsumer(clang::ASTContext* context);
		void HandleTranslationUnit(clang::ASTContext& context) override;

	private:
		ClangVisitor mVisitor;
	};

	class ClangFrontend : public clang::ASTFrontendAction {
	public:
		std::unique_ptr<clang::ASTConsumer>
		    CreateASTConsumer(clang::CompilerInstance& CI, llvm::StringRef file) override;
	};
} // namespace LayOpts
