#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/GlobalVariable.h>

#include <gtest/gtest.h>

using namespace llvm;

TEST(TestLLVM, TestModule) {
    llvm::LLVMContext context;
    llvm::Module *module = new llvm::Module("test module", context);
    module->print(llvm::outs(), nullptr);
    module->print(llvm::errs(), nullptr);
    delete module;
}

TEST(TestLLVM, TestFunction) {
    LLVMContext context;
    Module *module = new Module("test function", context);

    Type *voidType = Type::getVoidTy(context);
    FunctionType *functionType = FunctionType::get(voidType, false);
    Function *func = Function::Create(functionType, GlobalValue::ExternalLinkage, "testfunction", module);
    verifyFunction(*func);
    module->print(outs(), nullptr);


    delete module;
}

TEST(TestLLVM, TestBasicBlock) {
    LLVMContext context;
    IRBuilder<> builder(context);

    Module *module = new Module("test basic block", context);
    Type *voidType = Type::getVoidTy(context);
    FunctionType *funcType = FunctionType::get(voidType, false);
    Function *func = Function::Create(funcType, GlobalValue::ExternalLinkage, "TestBaiscBlock", module);

    BasicBlock* entry = BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(entry);

    verifyFunction(*func);
    module->print(outs(), nullptr);

    delete module;
}

TEST(TestLLVM, TestGlobalVariable) {
    LLVMContext context;
    Module *module = new Module("test global variable", context);

    module->getOrInsertGlobal("globalVariable", Type::getInt32Ty(context));
    GlobalVariable *globalVariable = module->getNamedGlobal("globalVariable");
    globalVariable->setLinkage(GlobalValue::ExternalLinkage);
    // globalVariable->setLinkage(GlobalValue::CommonLinkage);
    globalVariable->setAlignment(MaybeAlign(4));

    module->print(outs(), nullptr);

    delete module;
}

TEST(TestLLVM, TestRet) {
    LLVMContext context;
    IRBuilder<> builder(context);
    Module *module = new Module("test ret", context);

    module->getOrInsertGlobal("globalVariable", Type::getInt32Ty(context));
    GlobalVariable *globalVariable = module->getNamedGlobal("globalVariable");
    globalVariable->setLinkage(GlobalValue::ExternalLinkage);
    globalVariable->setAlignment(MaybeAlign(4));

    Type *i32Type = Type::getInt32Ty(context);
    FunctionType *funcType = FunctionType::get(i32Type, false);
    Function *func = Function::Create(funcType, GlobalValue::ExternalLinkage, "testret", module);
    BasicBlock *block = BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);

    ConstantInt *const_0 = builder.getInt32(0);
    builder.CreateRet(const_0);

    verifyFunction(*func);

    module->print(outs(), nullptr);

    delete module;
}

TEST(TestLLVM, TestFunctionArgs) {
    LLVMContext context;
    IRBuilder<> builder(context);
    Module *module = new Module("test function args", context);

    module->getOrInsertGlobal("globalVariable", Type::getInt32Ty(context));
    GlobalVariable *globalVariable = module->getNamedGlobal("globalVariable");
    globalVariable->setLinkage(GlobalValue::ExternalLinkage);
    globalVariable->setAlignment(MaybeAlign(4));

    std::vector<Type*> parameters(2, builder.getInt32Ty());
    FunctionType *funcType = FunctionType::get(builder.getInt32Ty(), parameters, false);
    Function *func = Function::Create(funcType, GlobalValue::ExternalLinkage, "test_func_args", module);
    func->getArg(0)->setName("a");
    func->getArg(1)->setName("b");

    BasicBlock *block = BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);

    ConstantInt *const_0 = builder.getInt32(0);
    builder.CreateRet(const_0);

    verifyFunction(*func);

    module->print(outs(), nullptr);

    delete module;
}

TEST(TestLLVM, TestArithmetic) {
    LLVMContext context;
    IRBuilder<> builder(context);
    Module *module = new Module("test arithmetic", context);

    module->getOrInsertGlobal("globalVariable", Type::getInt32Ty(context));
    GlobalVariable *globalVariable = module->getNamedGlobal("globalVariable");
    globalVariable->setLinkage(GlobalValue::ExternalLinkage);
    globalVariable->setAlignment(MaybeAlign(4));

    std::vector<Type*> parameters(2, builder.getInt32Ty());
    FunctionType *funcType = FunctionType::get(builder.getInt32Ty(), parameters, false);
    Function *func = Function::Create(funcType, GlobalValue::ExternalLinkage, "test_arithmetic", module);
    auto arg0 = func->getArg(0);
    arg0->setName("a");
    auto arg1 = func->getArg(1);
    arg1->setName("b");

    BasicBlock *block = BasicBlock::Create(context, "entry", func);
    builder.SetInsertPoint(block);

    ConstantInt *const_3 = builder.getInt32(3);
    Value *tmp0 = builder.CreateMul(arg0, arg1, "tmp0");
    builder.CreateMul(tmp0, const_3, "tmp1");

    ConstantInt *const_0 = builder.getInt32(0);
    builder.CreateRet(const_0);

    verifyFunction(*func);

    module->print(outs(), nullptr);

    delete module;
}