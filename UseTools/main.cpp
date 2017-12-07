#include <iostream>
#include "IToolsInterface.h"

using namespace std;

int testConfig(std::string strPath);

int main()
{
    int iRet = 0;

    iRet = testConfig("C:\\Users\\admin\\source\\repos\\MyTools\\Debug\\test.cfg");
    if (0 == iRet) cout << "testConfig success" << endl;
    else cout << "testConfig fail" << endl;

    system("pause");
    return 0;
}

int testConfig(std::string strPath)
{
    int iRet = 1;
    string ip;
    IMyConfig* poConfig = NULL;
    if (CreateInstanceConfig(poConfig))
    {
        iRet = poConfig->readConfigFile(strPath);
        ip = poConfig->getValue("ip");
        if (ip.empty())
            iRet = 1;
    }
    poConfig->print();
    delete poConfig;
    poConfig = NULL;
    return iRet;
}