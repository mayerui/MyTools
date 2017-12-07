#pragma once
#include "IToolsInterface.h"
#include <map>

class CMyConfig:
    public IMyConfig
{
public:
    CMyConfig();
    int readConfigFile(const std::string& strFilePath);
    int readConfigFile();
    string getCurrentPath();
    string getValue(const string& Key);
    void print();
private:
    int parseConfig(const char* buffer, std::string& strKey, std::string& strValue);
private:
    std::string m_strCurrentPath;
    std::map<std::string, std::string> m_ConfigMap;
};