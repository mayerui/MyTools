// MyConfig.cpp: 定义 DLL 应用程序的导出函数。
//

#include <windows.h>
#include <iostream>
#include <map>
#include "MyConfig.h"

using std::string;
using std::map;
using std::cout;
using std::endl;

const string strConfigFileName = "config.cfg";
const int iMaxBufferCount = 1024;

MYDLL bool CreateInstanceConfig(IMyConfig* &InterfaceClass)
{
    if (NULL == InterfaceClass)
    {
        InterfaceClass = new CMyConfig();
        return true;
    }
    else
        return false;
}

CMyConfig::CMyConfig()
{
    getCurrentPath();
}

string CMyConfig::getCurrentPath()
{
    if (!m_strCurrentPath.empty())
        return m_strCurrentPath;

    char path[MAX_PATH];
    GetModuleFileNameA(NULL, path, sizeof(path));
    string strPath = path;
    string::size_type pos = strPath.rfind("\\");
    m_strCurrentPath = strPath.substr(0, pos).c_str();
    return m_strCurrentPath;
}

int CMyConfig::readConfigFile()
{
    return readConfigFile(m_strCurrentPath + "\\" + strConfigFileName);
}

int CMyConfig::readConfigFile(const string& strFilePath)
{
    FILE* file = NULL;
    char buffer[iMaxBufferCount] = { 0 };
    string strKey, strValue;
    fopen_s(&file, strFilePath.c_str(), "r");
    if (NULL == file)
    {
        return 1;
    }
    
    while (!feof(file))
    {
        fgets(buffer, iMaxBufferCount, file);
        parseConfig(buffer, strKey, strValue);
    }
    fclose(file);
    return 0;
}

int CMyConfig::parseConfig(const char* buffer, string& strKey, string& strValue)
{
    string strBuffer = buffer;
    string::size_type posEqual = strBuffer.find("=");
    string::size_type posEnter = strBuffer.find("\n");
    strKey = strBuffer.substr(0, posEqual);
    strValue = strBuffer.substr(posEqual + 1, posEnter - posEqual - 1);
    //todo:去除头尾空格
    m_ConfigMap.insert(std::make_pair(strKey, strValue));
    return 0;
}

string CMyConfig::getValue(const string& Key)
{
    if (m_ConfigMap.end() == m_ConfigMap.find(Key))return "";
    else return m_ConfigMap[Key];
}

void CMyConfig::print()
{
    map<string, string>::iterator it = m_ConfigMap.begin();
    while (m_ConfigMap.end() != it)
    {
        cout << it->first << "=" << it->second << endl;
        ++it;
    }
    return;
}