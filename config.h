#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <list>
#include <map>
#include "libconfig.h++"

using namespace std;

class PosConfig
{
public:
    PosConfig();
    PosConfig(string path);
    ~PosConfig();

    int readIntCfg(string key, int& value);
    int readFloatCfg(string key, float& value);
    int readStringCfg(string key, string& value);
    int readListCfg(string key, list<int>& lst);
    int readArrayCfg(string key, int* array, int len);
    int readMapCfg(string group, string key, string& value);
    int readMapCfg(string group, map<string, string>& mp);

    int writeIntCfg(string key, int value);
    int writeFloatCfg(string key, float value);
    int writeStringCfg(string key, string value);
    int writeListCfg(string key, list<int> lst);
    int writeArrayCfg(string key, int* array, int len);
    int writeMapCfg(string group, string key, string value);

protected:
    //解读配置文件
    int initPosConfig(string cfgPath);
    int writePosConfig();
private:
    libconfig::Config mConfig;
    string cfgpath;

};



#endif // CONFIG_H
