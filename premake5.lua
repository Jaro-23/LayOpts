-- LLVM/Clang Setup
local llvmDir = "/usr/lib/llvm-15"
local llvmInclude = llvmDir .. "/include"
local llvmLib = llvmDir .. "/lib"

local clangLibs = {
	"clangTooling",
	"clangBasic",
	"clangAST",
	"clangASTMatchers",
	"clangFrontend",
	"clangLex",
	"clangParse",
	"clangSerialization",
	"clangDriver",
	"clangSema",
	"clangEdit",
	"clangAnalysis",
	"clangRewrite",
	"clangRewriteFrontend",
	"clangARCMigrate",
	"clangIndex",
	"clangFormat",
}

local llvmLibs = {
	"LLVMCore",
	"LLVMSupport",
	"LLVMMC",
	"LLVMOption",
}

workspace("LayOpts")
location("Generated")
language("C++")
cppdialect("C++20")
architecture("x86_64")
startproject("LayOpts_CLI")

configurations({ "Debug", "Release" })

filter("configurations:Debug")
symbols("On")
filter("configurations:Release")
optimize("On")
filter({})

flags({
	"MultiProcessorCompile",
})

targetdir("Build/Bin/%{prj.name}/%{cfg.buildcfg}")
objdir("Build/Obj/%{prj.name}/%{cfg.buildcfg}")

function includeLayOpts()
	includedirs("Projects/LayOpts/Parsers/headers")
	includedirs("Projects/LayOpts/Types/headers")
	links("LayOpts")
end

project("LayOpts")
kind("StaticLib")
files({
	"Projects/LayOpts/**.cpp",
	"Projects/LayOpts/**.hpp",
})

includedirs({
	"Projects/LayOpts/Parsers/headers",
	"Projects/LayOpts/Types/headers",
	llvmInclude,
})

libdirs({ llvmLib })

links(clangLibs)
links(llvmLibs)

filter("system:linux")
links({ "pthread", "z", "tinfo", "dl" })

project("LayOpts_CLI")
kind("ConsoleApp")
files({
	"Projects/Interfaces/**.cpp",
	"Projects/Interfaces/**.hpp",
})
includeLayOpts()
