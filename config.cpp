#include "config.h"
#include <list>

PosConfig::PosConfig()
{
    cfgpath = "./example.cfg";
    initPosConfig(cfgpath);
}
PosConfig::PosConfig(string path)
{
    cfgpath = path.c_str();
    initPosConfig(cfgpath);
}

PosConfig::~PosConfig()
{

}

int PosConfig::readIntCfg(string key, int& value)
{
    try {
        value = mConfig.lookup(key.c_str());
        cout << key << ":" << value << endl;
        return 0;
    } catch (...) {
        cout << "Get Number from " << cfgpath << "failed." << endl;
        return -1;
    }
}
int PosConfig::readFloatCfg(string key, float& value)
{
    try {
        value = mConfig.lookup(key.c_str());
        cout << key << ":" << value << endl;
        printf("%f\n", value);
        return 0;
    } catch (...) {
        cout << "Get Number from " << cfgpath << " failed." << endl;
        return -1;
    }
}
int PosConfig::readStringCfg(string key, string& value)
{
    try {
        //value = mConfig.lookup(key.c_str());
        mConfig.lookupValue(key.c_str(), value);
        cout << key << " : " << value << endl;
        return 0;
    } catch (...) {
        cout << "Get String from " << cfgpath << " failed." << endl;
        return -1;
    }
}
int PosConfig::readListCfg(string key, list<int>& lst)
{
    try {
        libconfig::Setting &root = mConfig.getRoot();
        libconfig::Setting &list = root[key.c_str()];
        int cnt = list.getLength();
        for(int i = 0; i < cnt; i++)
        {
            lst.push_back(list[i]);
        }
        return cnt;
    } catch (...) {
        cout << "Get List from " << cfgpath << " failed." << endl;
        return -1;
    }
}
int PosConfig::readArrayCfg(string key, int* array, int len)
{
    try {
        const libconfig::Setting &root = mConfig.getRoot();
        const libconfig::Setting &arr  = root[key.c_str()];
        for(int i = 0; i < len; i++)
        {
            array[i] = arr[i];
        }
        return 0;
    } catch (...) {
        cout << "Get Array from " << cfgpath << " failed." << endl;
        return -1;
    }

}
int PosConfig::readMapCfg(string group, string key, string& value)
{
    try
    {
        const libconfig::Setting &root = mConfig.getRoot();
        const libconfig::Setting &maps = root[group.c_str()];
        int cnt = maps.getLength();
        if(maps.exists(key.c_str()))
        {
            maps.lookupValue(key.c_str(), value);
            cout << key << " = " << value << endl;
            return 0;
        }
        return -1;
    }
    catch(...)
    {
        cout<<"Get Map from "<< cfgpath <<" failed ..."<<endl;
        return -1;
    }
}
int PosConfig::readMapCfg(string group, map<string,string>& mp)
{
    try {
        const libconfig::Setting &root = mConfig.getRoot();
        const libconfig::Setting &maps = root[group.c_str()];
        //int cnt = maps.getLength();
        //printf("cnt = %d\n", cnt);

        string key;
        string value;
        libconfig::Setting::const_iterator it = maps.begin() ;
        //libconfig::SettingConstIterator it = maps.begin();
        while(it != maps.end()) {
            key = it->getName();
            maps.lookupValue(key,value);
            mp.insert(make_pair(key, value));
            it++;
        }
    } catch (...) {
        cout << "Get Map from "<< cfgpath <<" failed ..." << endl;
        return -1;
    }
}


int PosConfig::writeIntCfg(string key, int value)
{
    try {
        libconfig::Setting &root = mConfig.getRoot();
        if(root.exists(key.c_str()))
        {
            cout << "exists" << endl;
            root.remove(key.c_str());
        }
        root.add(key.c_str(), libconfig::Setting::TypeInt) = value;
        writePosConfig();
        return 0;
    } catch (...) {
        cout << "Put Number from " << cfgpath << "failed." << endl;
        return -1;
    }
}
int PosConfig::writeFloatCfg(string key, float value)
{
    try {
        libconfig::Setting &root = mConfig.getRoot();
        if(root.exists(key.c_str()))
        {
            cout << "exists" << endl;
            root.remove(key.c_str());
        }
        root.add(key.c_str(), libconfig::Setting::TypeFloat) = value;
        writePosConfig();
        return 0;
    } catch (...) {
        cout << "Put Number from " << cfgpath << " failed." << endl;
        return -1;
    }
}
int PosConfig::writeStringCfg(string key, string value)
{
    try {
        libconfig::Setting &root = mConfig.getRoot();
        if(root.exists(key.c_str()))
        {
            root.remove(key.c_str());
        }
        root.add(key.c_str(), libconfig::Setting::TypeString) = value.c_str();
        writePosConfig();
        return 0;
    } catch (...) {
        cout << "Put String from " << cfgpath << " failed." << endl;
        return -1;
    }
}
int PosConfig::writeListCfg(string key, list<int> lst)
{
    try {
        libconfig::Setting &root = mConfig.getRoot();
        if(root.exists(key.c_str()))
        {
            root.remove(key.c_str());
        }
        libconfig::Setting &setlist = root.add(key.c_str(), libconfig::Setting::TypeList);
        list<int>::iterator it = lst.begin();
        for(; it != lst.end(); it++)
        {
            setlist.add(libconfig::Setting::TypeInt) = *it;
        }
        writePosConfig();
        return 0;
    } catch (...) {
        cout << "Put List from " << cfgpath << " failed." << endl;
        return -1;
    }
}
int PosConfig::writeArrayCfg(string key, int* array, int len)
{
    try {
        libconfig::Setting &root = mConfig.getRoot();
        if(root.exists(key.c_str()))
        {
            root.remove(key.c_str());
        }
        libconfig::Setting &setarray = root.add(key.c_str(), libconfig::Setting::TypeArray);

        for(int i = 0; i < len; i++)
        {
            setarray.add(libconfig::Setting::TypeInt) = array[i];
        }
        writePosConfig();
        return 0;
    } catch (...) {
        cout << "Put Array from " << cfgpath << " failed." << endl;
        return -1;
    }

}
int PosConfig::writeMapCfg(string group, string key, string value)
{
    try {
        libconfig::Setting &root = mConfig.getRoot();
        if(!root.exists(group.c_str()))
        {
            root.add(group.c_str(), libconfig::Setting::TypeGroup);
        }
        libconfig::Setting &address = root[group.c_str()];

        if(address.exists(key.c_str()))
        {
            cout << key << endl;
            address.remove(key.c_str());
        }
        address.add(key.c_str(), libconfig::Setting::TypeString) = value.c_str();
        writePosConfig();
        return 0;
    } catch (...) {
        cout<<"Put Map from "<< cfgpath <<" failed ..."<<endl;
        return -1;
    }
}

//解读配置文件
int PosConfig::initPosConfig(string cfgPath)
{
    try {
        mConfig.readFile(cfgPath.c_str());
    } catch (libconfig::FileIOException &e) {
        cout << "read file [" << cfgPath << "] FileIOException." << endl;
        return -1;
    } catch (libconfig::ParseException &e) {
        cout << "read file [" << cfgPath << "],ParaseException:" << e.getError() << ",line:" << e.getLine() << endl;
        return -1;
    } catch (...) {
        cout << "read file [" << cfgPath << "] unknow exception" << endl;
        return -1;
    }
}
int PosConfig::writePosConfig()
{
    try {
        mConfig.writeFile(cfgpath.c_str());
        cout << "New configuration successfully writen to: " << cfgpath << endl;
        return 0;
    } catch (...) {
        cout << "I/O error while writing file:" << cfgpath << endl;
        return -1;
    }
}
