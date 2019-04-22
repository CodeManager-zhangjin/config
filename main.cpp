#include <iostream>
#include <stdio.h>
#include "config.h"

int main(int argc, char* argv[])
{
    PosConfig poscfg("./setting.cfg");
    PosConfig pos;
#if 0
    float num = 0;
    poscfg.readFloatCfg("aaa", num);
    poscfg.writeFloatCfg("aaa", 100.99);
    poscfg.readFloatCfg("bbb", num);
    poscfg.writeFloatCfg("bbb", 200.88);
    poscfg.readFloatCfg("ccc", num);
    poscfg.writeFloatCfg("ccc", 300.77);
#endif

#if 0
    string str = "123";
    pos.readStringCfg("str1", str);
    pos.writeStringCfg("str1", "12345");
    pos.readStringCfg("str2", str);
    pos.writeStringCfg("str2", "67890");
    pos.readStringCfg("str3", str);
    pos.writeStringCfg("str3", "00000");
#endif

#if 0
    list<int> lst, lst2;
    lst.push_back(0);
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    poscfg.writeListCfg("list", lst);
    poscfg.readListCfg("list", lst2);

    list<int>::iterator iter = lst2.begin();
    for (; iter != lst2.end(); iter++) {
        cout << *iter << endl;
    }
#endif

#if 0
    int array[24] = {0}, array2[24] = {1, 2,3 ,4, 5, 6,7 ,8, 9};
    poscfg.writeArrayCfg("array", array2, 9);
    poscfg.readArrayCfg("array", array, 9);
    for (int i = 0; i < 9; i++) {
        cout << array[i] << endl;
    }
#endif

#if 1
    poscfg.writeMapCfg("map", "city1", "TianJin");
    poscfg.writeMapCfg("map", "city2", "BeiJing");
    poscfg.writeMapCfg("map", "city3", "ShangHai");

//    string value;
//    poscfg.readMapCfg("map", "city1", value);

    map<string, string> mp;
    poscfg.readMapCfg("map", mp);
    map<string, string>::iterator it = mp.begin();
    for(; it != mp.end(); it++){
        cout << it->first << " = " << it->second << endl;
    }
#endif

    return 0;
}
