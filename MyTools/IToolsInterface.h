#pragma once

#include <string>
using std::string;

//DLL的导出函数声明
#define EXPORT_LIB
#define LIB_DLL
#ifdef EXPORT_LIB//导出库
    #ifdef LIB_DLL
        #define MYDLL extern "C" __declspec(dllexport)
    #else
        #define MYDLL
    #endif
#else//引用库
    #ifdef LID_DLL
        #define MYDLL extern "C" __declspec(dllimport)
    #else
        #define MYDLL
    #endif
#endif

//读取配置文件接口类
//默认为exe目录下的config.cfg文件
class IMyConfig
{
public:
    IMyConfig() {};
    virtual ~IMyConfig() = 0 {};
    virtual int readConfigFile(const string& strFilePath) = 0;
    virtual int readConfigFile() = 0;
    virtual string getCurrentPath() = 0;
    virtual string getValue(const string& Key) = 0;
    virtual void print() = 0;
};

MYDLL bool CreateInstanceConfig(IMyConfig* &InterfaceClass);