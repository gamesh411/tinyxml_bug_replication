XTU-Analyzer bug replication for Tinyxml2
==========
clang --version
clang version 5.0.0 (https://github.com/dkrupp/clang.git 2c77498f81bead02403dda18ed4e60f184d06659) (http://llvm.org/git/llvm.git 093eb4f6ff33d70ecd9de34d233d8f252669a5fc)
Target: x86_64-unknown-linux-gnu
Thread model: posix
InstalledDir: /home/gamesh411/clang_build_debug/bin

Stacktrace:

```
/home/gamesh411/llvm/tools/clang/tools/scan-build-py/bin/analyze-cc -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include /home/gamesh411/tinyxml2anal/tinyxml2/xmltest.cpp /home/gamesh411/tinyxml2anal/tinyxml2/libtinyxml2.a -o /home/gamesh411/tinyxml2anal/tinyxml2/xmltest
analyze: INFO: execute compiler: g++ -I/usr/include/c++/5 -I/usr/include/x86_64-linux-gnu/c++/5 -I/usr/include/c++/5/backward -I/usr/local/include -I/usr/include/x86_64-linux-gnu -I/usr/include /home/gamesh411/tinyxml2anal/tinyxml2/xmltest.cpp /home/gamesh411/tinyxml2anal/tinyxml2/libtinyxml2.a -o /home/gamesh411/tinyxml2anal/tinyxml2/xmltest
analyze: INFO: Importing function _ZN8tinyxml211XMLDocumentC1EbNS_10WhitespaceE@x86_64 from /home/gamesh411/tinyxml2anal/debug_anal/.xtu//ast/x86_64/home/gamesh411/tinyxml2anal/tinyxml2/tinyxml2.cpp.ast
analyze: INFO: #0 0x0000000002ac4296 llvm::sys::PrintStackTrace(llvm::raw_ostream&) /home/gamesh411/llvm/lib/Support/Unix/Signals.inc:402:0
analyze: INFO: #1 0x0000000002ac4635 PrintStackTraceSignalHandler(void*) /home/gamesh411/llvm/lib/Support/Unix/Signals.inc:466:0
analyze: INFO: #2 0x0000000002ac25cf llvm::sys::RunSignalHandlers() /home/gamesh411/llvm/lib/Support/Signals.cpp:44:0
analyze: INFO: #3 0x0000000002ac3af6 SignalHandler(int) /home/gamesh411/llvm/lib/Support/Unix/Signals.inc:256:0
analyze: INFO: #4 0x00007f19fb776390 __restore_rt (/lib/x86_64-linux-gnu/libpthread.so.0+0x11390)
analyze: INFO: #5 0x0000000003074be6 clang::Expr::getObjectKind() const /home/gamesh411/llvm/tools/clang/include/clang/AST/Expr.h:409:0
analyze: INFO: #6 0x00000000052e0812 clang::CXXDefaultArgExpr::CXXDefaultArgExpr(clang::Stmt::StmtClass, clang::SourceLocation, clang::ParmVarDecl*) /home/gamesh411/llvm/tools/clang/include/clang/AST/ExprCXX.h:994:0
analyze: INFO: #7 0x00000000052e093a clang::CXXDefaultArgExpr::Create(clang::ASTContext const&, clang::SourceLocation, clang::ParmVarDecl*) /home/gamesh411/llvm/tools/clang/include/clang/AST/ExprCXX.h:1003:0
analyze: INFO: #8 0x00000000059c9848 clang::ASTNodeImporter::VisitCXXDefaultArgExpr(clang::CXXDefaultArgExpr*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:6442:0
analyze: INFO: #9 0x00000000059d344b clang::StmtVisitorBase<clang::make_ptr, clang::ASTNodeImporter, clang::Stmt*>::Visit(clang::Stmt*) /home/gamesh411/clang_build/tools/clang/include/clang/AST/StmtNodes.inc:227:0
analyze: INFO: #10 0x00000000059ccf23 clang::ASTImporter::Import(clang::Stmt*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:7056:0
analyze: INFO: #11 0x00000000059cce38 clang::ASTImporter::Import(clang::Expr*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:7042:0
analyze: INFO: #12 0x00000000059cb378 clang::ASTNodeImporter::VisitCallExpr(clang::CallExpr*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:6723:0
analyze: INFO: #13 0x00000000059d35e3 clang::StmtVisitorBase<clang::make_ptr, clang::ASTNodeImporter, clang::Stmt*>::Visit(clang::Stmt*) /home/gamesh411/clang_build/tools/clang/include/clang/AST/StmtNodes.inc:329:0
analyze: INFO: #14 0x00000000059ccf23 clang::ASTImporter::Import(clang::Stmt*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:7056:0
analyze: INFO: #15 0x00000000059cce38 clang::ASTImporter::Import(clang::Expr*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:7042:0
analyze: INFO: #16 0x00000000059c31ef clang::ASTNodeImporter::VisitIfStmt(clang::IfStmt*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:5394:0
analyze: INFO: #17 0x00000000059d3d33 clang::StmtVisitorBase<clang::make_ptr, clang::ASTNodeImporter, clang::Stmt*>::Visit(clang::Stmt*) /home/gamesh411/clang_build/tools/clang/include/clang/AST/StmtNodes.inc:843:0
analyze: INFO: #18 0x00000000059ccf23 clang::ASTImporter::Import(clang::Stmt*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:7056:0
analyze: INFO: #19 0x00000000059d52a2 bool clang::ASTNodeImporter::ImportArrayChecked<clang::Stmt**, clang::Stmt**>(clang::Stmt**, clang::Stmt**, clang::Stmt**)::{lambda(clang::Stmt*)#1}::operator()(clang::Stmt*) const /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:302:0
analyze: INFO: #20 0x00000000059d8cba clang::Stmt** std::transform<clang::Stmt**, clang::Stmt**, bool clang::ASTNodeImporter::ImportArrayChecked<clang::Stmt**, clang::Stmt**>(clang::Stmt**, clang::Stmt**, clang::Stmt**)::{lambda(clang::Stmt*)#1}>(clang::Stmt**, clang::Stmt**, clang::Stmt**, bool clang::ASTNodeImporter::ImportArrayChecked<clang::Stmt**, clang::Stmt**>(clang::Stmt**, clang::Stmt**, clang::Stmt**)::{lambda(clang::Stmt*)#1}) /usr/include/c++/5/bits/stl_algo.h:4175:0
analyze: INFO: #21 0x00000000059d5336 bool clang::ASTNodeImporter::ImportArrayChecked<clang::Stmt**, clang::Stmt**>(clang::Stmt**, clang::Stmt**, clang::Stmt**) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:307:0
analyze: INFO: #22 0x00000000059d0fa2 bool clang::ASTNodeImporter::ImportContainerChecked<llvm::iterator_range<clang::Stmt**>, llvm::SmallVector<clang::Stmt*, 8u> >(llvm::iterator_range<clang::Stmt**> const&, llvm::SmallVector<clang::Stmt*, 8u>&) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:315:0
analyze: INFO: #23 0x00000000059c2880 clang::ASTNodeImporter::VisitCompoundStmt(clang::CompoundStmt*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:5310:0
analyze: INFO: #24 0x00000000059d3229 clang::StmtVisitorBase<clang::make_ptr, clang::ASTNodeImporter, clang::Stmt*>::Visit(clang::Stmt*) /home/gamesh411/clang_build/tools/clang/include/clang/AST/StmtNodes.inc:79:0
analyze: INFO: #25 0x00000000059ccf23 clang::ASTImporter::Import(clang::Stmt*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:7056:0
analyze: INFO: #26 0x00000000059b85df clang::ASTNodeImporter::VisitFunctionDecl(clang::FunctionDecl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:3408:0
analyze: INFO: #27 0x00000000059b8681 clang::ASTNodeImporter::VisitCXXMethodDecl(clang::CXXMethodDecl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:3423:0
analyze: INFO: #28 0x00000000059d262b clang::declvisitor::Base<clang::declvisitor::make_ptr, clang::ASTNodeImporter, clang::Decl*>::Visit(clang::Decl*) /home/gamesh411/clang_build/tools/clang/include/clang/AST/DeclNodes.inc:393:0
analyze: INFO: #29 0x00000000059cc908 clang::ASTImporter::Import(clang::Decl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:6951:0
analyze: INFO: #30 0x00000000059b1e1f clang::ASTNodeImporter::ImportDeclContext(clang::DeclContext*, bool) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:2296:0
analyze: INFO: #31 0x00000000059b46d5 clang::ASTNodeImporter::VisitNamespaceDecl(clang::NamespaceDecl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:2782:0
analyze: INFO: #32 0x00000000059d22cb clang::declvisitor::Base<clang::declvisitor::make_ptr, clang::ASTNodeImporter, clang::Decl*>::Visit(clang::Decl*) /home/gamesh411/clang_build/tools/clang/include/clang/AST/DeclNodes.inc:105:0
analyze: INFO: #33 0x00000000059cc908 clang::ASTImporter::Import(clang::Decl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:6951:0
analyze: INFO: #34 0x00000000059ccb2b clang::ASTImporter::ImportContext(clang::DeclContext*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:6987:0
analyze: INFO: #35 0x00000000059b1979 clang::ASTNodeImporter::ImportDeclParts(clang::NamedDecl*, clang::DeclContext*&, clang::DeclContext*&, clang::DeclarationName&, clang::NamedDecl*&, clang::SourceLocation&) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:2211:0
analyze: INFO: #36 0x00000000059b71b1 clang::ASTNodeImporter::VisitFunctionDecl(clang::FunctionDecl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:3213:0
analyze: INFO: #37 0x00000000059b8681 clang::ASTNodeImporter::VisitCXXMethodDecl(clang::CXXMethodDecl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:3423:0
analyze: INFO: #38 0x00000000059b86a7 clang::ASTNodeImporter::VisitCXXConstructorDecl(clang::CXXConstructorDecl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:3427:0
analyze: INFO: #39 0x00000000059d2643 clang::declvisitor::Base<clang::declvisitor::make_ptr, clang::ASTNodeImporter, clang::Decl*>::Visit(clang::Decl*) /home/gamesh411/clang_build/tools/clang/include/clang/AST/DeclNodes.inc:397:0
analyze: INFO: #40 0x00000000059cc908 clang::ASTImporter::Import(clang::Decl*) /home/gamesh411/llvm/tools/clang/lib/AST/ASTImporter.cpp:6951:0
analyze: INFO: #41 0x00000000058cd7c6 clang::ASTContext::getXTUDefinition(clang::FunctionDecl const*, clang::CompilerInstance&, llvm::StringRef, clang::DiagnosticsEngine&, std::function<clang::ASTUnit* (llvm::StringRef)>) /home/gamesh411/llvm/tools/clang/lib/AST/ASTContext.cpp:1557:0
analyze: INFO: #42 0x0000000004a8a801 clang::ento::AnyFunctionCall::getRuntimeDefinition() const /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/CallEvent.cpp:394:0
analyze: INFO: #43 0x0000000004af83c3 clang::ento::ExprEngine::defaultEvalCall(clang::ento::NodeBuilder&, clang::ento::ExplodedNode*, clang::ento::CallEvent const&) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/ExprEngineCallAndReturn.cpp:912:0
analyze: INFO: #44 0x0000000004af26cd clang::ento::ExprEngine::VisitCXXConstructExpr(clang::CXXConstructExpr const*, clang::ento::ExplodedNode*, clang::ento::ExplodedNodeSet&) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/ExprEngineCXX.cpp:344:0
analyze: INFO: #45 0x0000000004ac9235 clang::ento::ExprEngine::Visit(clang::Stmt const*, clang::ento::ExplodedNode*, clang::ento::ExplodedNodeSet&) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/ExprEngine.cpp:1198:0
analyze: INFO: #46 0x0000000004ac5b57 clang::ento::ExprEngine::ProcessStmt(clang::CFGStmt, clang::ento::ExplodedNode*) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/ExprEngine.cpp:509:0
analyze: INFO: #47 0x0000000004ac4de7 clang::ento::ExprEngine::processCFGElement(clang::CFGElement, clang::ento::ExplodedNode*, unsigned int, clang::ento::NodeBuilderContext*) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/ExprEngine.cpp:357:0
analyze: INFO: #48 0x0000000004ab2d4c clang::ento::CoreEngine::HandlePostStmt(clang::CFGBlock const*, unsigned int, clang::ento::ExplodedNode*) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/CoreEngine.cpp:532:0
analyze: INFO: #49 0x0000000004ab1ab1 clang::ento::CoreEngine::dispatchWorkItem(clang::ento::ExplodedNode*, clang::ProgramPoint, clang::ento::WorkListUnit const&) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/CoreEngine.cpp:279:0
analyze: INFO: #50 0x0000000004ab16b6 clang::ento::CoreEngine::ExecuteWorkList(clang::LocationContext const*, unsigned int, llvm::IntrusiveRefCntPtr<clang::ento::ProgramState const>) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Core/CoreEngine.cpp:235:0
analyze: INFO: #51 0x000000000452120b clang::ento::ExprEngine::ExecuteWorkList(clang::LocationContext const*, unsigned int) /home/gamesh411/llvm/tools/clang/include/clang/StaticAnalyzer/Core/PathSensitive/ExprEngine.h:110:0
analyze: INFO: #52 0x00000000044d362e (anonymous namespace)::AnalysisConsumer::ActionExprEngine(clang::Decl*, bool, clang::ento::ExprEngine::InliningModes, llvm::DenseSet<clang::Decl const*, llvm::DenseMapInfo<clang::Decl const*> >*) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Frontend/AnalysisConsumer.cpp:826:0
analyze: INFO: #53 0x00000000044d3a25 (anonymous namespace)::AnalysisConsumer::RunPathSensitiveChecks(clang::Decl*, clang::ento::ExprEngine::InliningModes, llvm::DenseSet<clang::Decl const*, llvm::DenseMapInfo<clang::Decl const*> >*) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Frontend/AnalysisConsumer.cpp:862:0
analyze: INFO: #54 0x00000000044d33c7 (anonymous namespace)::AnalysisConsumer::HandleCode(clang::Decl*, unsigned int, clang::ento::ExprEngine::InliningModes, llvm::DenseSet<clang::Decl const*, llvm::DenseMapInfo<clang::Decl const*> >*) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Frontend/AnalysisConsumer.cpp:792:0
analyze: INFO: #55 0x00000000044d1c8f (anonymous namespace)::AnalysisConsumer::HandleDeclsCallGraph(unsigned int) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Frontend/AnalysisConsumer.cpp:575:0
analyze: INFO: #56 0x00000000044d2705 (anonymous namespace)::AnalysisConsumer::HandleTranslationUnit(clang::ASTContext&) /home/gamesh411/llvm/tools/clang/lib/StaticAnalyzer/Frontend/AnalysisConsumer.cpp:657:0
analyze: INFO: #57 0x0000000004b99ca3 clang::ParseAST(clang::Sema&, bool, bool) /home/gamesh411/llvm/tools/clang/lib/Parse/ParseAST.cpp:161:0
analyze: INFO: #58 0x0000000003398959 clang::ASTFrontendAction::ExecuteAction() /home/gamesh411/llvm/tools/clang/lib/Frontend/FrontendAction.cpp:559:0
analyze: INFO: #59 0x00000000033983a6 clang::FrontendAction::Execute() /home/gamesh411/llvm/tools/clang/lib/Frontend/FrontendAction.cpp:463:0
analyze: INFO: #60 0x000000000333976e clang::CompilerInstance::ExecuteAction(clang::FrontendAction&) /home/gamesh411/llvm/tools/clang/lib/Frontend/CompilerInstance.cpp:954:0
analyze: INFO: #61 0x00000000034d7406 clang::ExecuteCompilerInvocation(clang::CompilerInstance*) /home/gamesh411/llvm/tools/clang/lib/FrontendTool/ExecuteCompilerInvocation.cpp:249:0
analyze: INFO: #62 0x00000000019e47af cc1_main(llvm::ArrayRef<char const*>, char const*, void*) /home/gamesh411/llvm/tools/clang/tools/driver/cc1_main.cpp:221:0
analyze: INFO: #63 0x00000000019d9e2d ExecuteCC1Tool(llvm::ArrayRef<char const*>, llvm::StringRef) /home/gamesh411/llvm/tools/clang/tools/driver/driver.cpp:299:0
analyze: INFO: #64 0x00000000019daa4b main /home/gamesh411/llvm/tools/clang/tools/driver/driver.cpp:380:0
analyze: INFO: #65 0x00007f19fa4d4830 __libc_start_main /build/glibc-t3gR2i/glibc-2.23/csu/../csu/libc-start.c:325:0
analyze: INFO: #66 0x00000000019d75f9 _start (/home/gamesh411/clang_build_debug/bin/clang-5.0+0x19d75f9)
analyze: INFO: Stack dump:
analyze: INFO: 0.	Program arguments: /home/gamesh411/clang_build_debug/bin/clang-5.0 -cc1 -triple x86_64-unknown-linux-gnu -analyze -disable-free -main-file-name xmltest.cpp -analyzer-store=region -analyzer-opt-analyze-nested-blocks -analyzer-eagerly-assume -analyzer-checker=core -analyzer-checker=apiModeling -analyzer-checker=unix -analyzer-checker=deadcode -analyzer-checker=cplusplus -analyzer-checker=security.insecureAPI.UncheckedReturn -analyzer-checker=security.insecureAPI.getpw -analyzer-checker=security.insecureAPI.gets -analyzer-checker=security.insecureAPI.mktemp -analyzer-checker=security.insecureAPI.mkstemp -analyzer-checker=security.insecureAPI.vfork -analyzer-checker=nullability.NullPassedToNonnull -analyzer-checker=nullability.NullReturnedFromNonnull -analyzer-output plist-multi-file -w -analyzer-config xtu-dir=/home/gamesh411/tinyxml2anal/debug_anal/.xtu -analyzer-config reanalyze-xtu-visited=true -analyzer-stats -mrelocation-model static -mthread-model posix -mdisable-fp-elim -fmath-errno -masm-verbose -mconstructor-aliases -munwind-tables -fuse-init-array -target-cpu x86-64 -dwarf-column-info -debugger-tuning=gdb -resource-dir /home/gamesh411/clang_build_debug/bin/../lib/clang/5.0.0 -I /usr/include/c++/5 -I /usr/include/x86_64-linux-gnu/c++/5 -I /usr/include/c++/5/backward -I /usr/local/include -I /usr/include/x86_64-linux-gnu -I /usr/include -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/x86_64-linux-gnu/c++/5.4.0 -internal-isystem /usr/lib/gcc/x86_64-linux-gnu/5.4.0/../../../../include/c++/5.4.0/backward -internal-isystem /usr/local/include -internal-isystem /home/gamesh411/clang_build_debug/bin/../lib/clang/5.0.0/include -internal-externc-isystem /usr/include/x86_64-linux-gnu -internal-externc-isystem /include -internal-externc-isystem /usr/include -fdeprecated-macro -fdebug-compilation-dir /home/gamesh411/tinyxml2anal/tinyxml2 -ferror-limit 19 -fmessage-length 0 -fobjc-runtime=gcc -fcxx-exceptions -fexceptions -fdiagnostics-show-option -o /home/gamesh411/tinyxml2anal/debug_anal/.xtu-out/report-X1rPoc.plist -x c++ /home/gamesh411/tinyxml2anal/tinyxml2/xmltest.cpp
analyze: INFO: 1.	<eof> parser at end of file
analyze: INFO: 2.	While analyzing stack:
analyze: INFO: 	#0 int example_2()
analyze: INFO: 	#1 int main(int argc, const char **argv)
analyze: INFO: 3.	/home/gamesh411/tinyxml2anal/tinyxml2/xmltest.cpp:130:14: Error evaluating statement
analyze: INFO: 4.	/home/gamesh411/tinyxml2anal/tinyxml2/xmltest.cpp:130:14: Error evaluating statement
```
