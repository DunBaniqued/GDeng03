#include "ShaderErrorChecker.h"

ShaderErrorChecker* ShaderErrorChecker::get()
{
    static ShaderErrorChecker errCheck;
    return &errCheck;
}

void ShaderErrorChecker::ShaderErrorCheck(const wchar_t* file_name, ID3DBlob* error_blob, const char file[])
{
    if (error_blob) {
        std::cerr << "Compilation failed:\n"
            << (char*)error_blob->GetBufferPointer() << std::endl;
        error_blob->Release();
    }
    else {
        std::wcout << "Unknown error compiling: "
            << file_name << std::endl;
        std::wcout << "From File: " << file << std::endl;
    }
}
