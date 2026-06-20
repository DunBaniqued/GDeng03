// ShaderCompiler.h
#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <string>
#include <iostream>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dcompiler.lib")

class ShaderErrorChecker {
public:
    static ShaderErrorChecker* get();

    void ShaderErrorCheck(const wchar_t* file_name, ID3DBlob* error_blob, const char file[]);
};

