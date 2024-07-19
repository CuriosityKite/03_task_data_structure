#include <iostream>
#include <json/json.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <string>                                                               
#include <boost/foreach.hpp>
#include <windows.h>

class json
{
public:
    json(std::string fileName)
    {
        boost::property_tree::read_json(fileName, tree);
    }

    void print_json()
    {
        print_json(tree);
    }

private:
    boost::property_tree::ptree tree;

    void print_json(const boost::property_tree::ptree tree, const std::string path = "")
    {
        BOOST_FOREACH(auto tr, tree)
        {
            std::string key = path.empty() ? tr.first : path + "." + tr.first;
            if (tr.second.empty())
            {
                std::cout << key << ":" << tr.second.data() << std::endl;
            }
            else
            {
                print_json(tr.second, key);
            }
        }
    }
};