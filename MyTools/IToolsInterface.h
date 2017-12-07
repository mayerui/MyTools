#pragma once

#include <string>
using std::string;

//DLL�ĵ�����������
#define EXPORT_LIB
#define LIB_DLL
#ifdef EXPORT_LIB//������
    #ifdef LIB_DLL
        #define MYDLL extern "C" __declspec(dllexport)
    #else
        #define MYDLL
    #endif
#else//���ÿ�
    #ifdef LID_DLL
        #define MYDLL extern "C" __declspec(dllimport)
    #else
        #define MYDLL
    #endif
#endif

//��ȡ�����ļ��ӿ���
//Ĭ��ΪexeĿ¼�µ�config.cfg�ļ�
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