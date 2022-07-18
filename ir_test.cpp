#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

void genir() {
    auto context = std::make_unique<llvm::LLVMContext>();
    auto mod = std::make_unique<llvm::Module>("genir.cpp", *context);
    auto builder = std::make_unique<llvm::IRBuilder<>>(*context);
    std::vector<llvm::Type*> args(2, llvm::Type::getInt32Ty(*context));
    llvm::FunctionType *functionType =
        llvm::FunctionType::get(llvm::Type::getInt32Ty(*context), args, false);
    llvm::Function *f = llvm::Function::Create(functionType, llvm::Function::ExternalLinkage, "add", mod.get());

    llvm::BasicBlock *BB = llvm::BasicBlock::Create(*context, "entry", f);
    builder->SetInsertPoint(BB);

    auto retVal = llvm::ConstantInt::get(*context, llvm::APInt(32, 666, true));

    builder->CreateRet(retVal);
    mod->print(llvm::errs(), nullptr);
}