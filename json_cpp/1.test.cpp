/*************************************************************************
	> File Name: 1.test.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 24 Jan 2025 12:59:35 PM CST
 ************************************************************************/

#include <iostream>
#include <jsoncpp/json/json.h>
#include <fstream>

void writeJson() {
	Json::Value root;
	root.append("lucy");
	root.append(19);
	root.append(170);
	root.append(false);

	Json::Value subArray;
	subArray.append("ace");
	subArray.append("sabo");
	root.append(subArray);

	Json::Value obj;
	obj["sex"] = "man";
	obj["girlfriend"] = "Hancock";
	root.append(obj);
#if 0
	std::string json = root.toStyledString();
#else
	Json::FastWriter w;
	std::string json = w.write(root);
#endif
	//write -> ofstream -->wo
	//read -> ifstream --> ri
	std::ofstream ofs("test.json");
	ofs << json;
	ofs.close();
}

void readJson() {
	std::ifstream ifs("test.json");
	Json::Reader rd;
	Json::Value root;
	rd.parse(ifs, root);

	if(root.isArray()) {
		for (int i = 0; i < root.size(); ++i) {
			Json::Value item = root[i];
			if (item.isInt()) {
				std::cout << item.asInt() << ", ";
			}
			if (item.isString())
            {
                std::cout << item.asString() << ", ";
            }
            else if (item.isInt())
            {
                std::cout << item.asInt() << ", ";
            }
            else if (item.isBool())
            {
                std::cout << item.asBool() << ", ";
            }
            else if (item.isDouble())
            {
                std::cout << item.asFloat() << ", ";
            }
            else if (item.isArray())
            {
                for (int j = 0; j < item.size(); ++j)
                {
                   std::cout << item[j].asString() << ", ";
                }
            }
	else if (root.isObject()) {
		// 对象
        // 得到所有的key
        Json::Value::Members keys = item.getMemberNames();
        for (int k = 0; k < keys.size(); ++k)
        {
            std::cout << keys.at(k) << ":" << item[keys[k]] << ", ";
        }
	}
	}
	std::cout << std::endl;
	}
}

int main()
{
	writeJson();
	readJson();

	return 0;
}