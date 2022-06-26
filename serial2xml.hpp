#ifndef __SERIAL2XML_HPP__
#define __SERIAL2XML_HPP__

#include "global.h"
#include "tinyxml2.h"

using namespace tinyxml2;
using namespace std;

namespace serial2xml{
    // different from serial2bin
    // in serialxml use serial2xml class 
    class xmlSerialBase{
    private:
        // XMLDocument is the container for tinyxml2.h's element
        XMLDocument doc;
        // XMLElement is the root element
        XMLElement* root;
        inline void reset(){
            // clear the existed content in doc
            doc.Clear();
            // create the declaration
            XMLDeclaration* dec = doc.NewDeclaration("xml version \"1.0\" encoding = \"UTF-8\"");
            doc.InsertFirstChild(dec);
            // insert the root 
            root = doc.NewElement("serialization");
            doc.InsertEndChild(root);
            return;
        }
        // save the xml file
        inline void save(string fileName){
            doc.SaveFile(fileName.c_str());
            return;
        }

    public:
        // ctor
        xmlSerialBase(){
            reset();
        }
        
        // the external interface for bool xml
        inline void serialize_xml(const bool& object, string fileName){
            reset();
            serialize(object, root);
            save(fileName);
        }

        // the external interface for char xml
        inline void serialize_xml(const char& object, string fileName){
            reset();
            serialize(object, root);
            save(fileName);
        }

        // the external interface for int xml
        inline void serialize_xml(const int& object, string fileName){
            reset();
            serialize(object, root);
            save(fileName);
        }

        // the external interface for double xml
        inline void serialize_xml(const double& object, string fileName){
            reset();
            serialize(object, root);
            save(fileName);
        }

        // the external interface for string xml
        inline void serialize_xml(const string& object, string fileName){
            reset();
            serialize(object, root);
            save(fileName);
        }

        // the external interface for deserializing bool file
        inline bool deserialize_xml(bool& object, string fileName){
            XMLError ret = doc.LoadFile(fileName.c_str());
            if(ret != 0){
                cout << "fail to load the xml file" << endl;
                return false;
            }
            root = doc.FirstChildElement("serialization");
        
            bool _ret = deserialize(object, root->FirstChildElement("std_bool"));
            if(! _ret){
                cout << "can't find the expected type in xml file" << endl;
                return false;
            }
            return true;
        }

        // the external interface for deserializing int file
        inline bool deserialize_xml(int& object, string fileName){
            XMLError ret = doc.LoadFile(fileName.c_str());
            if(ret != 0){
                cout << "fail to load the xml file" << endl;
                return false;
            }
            root = doc.FirstChildElement("serialization");
        
            bool _ret = deserialize(object, root->FirstChildElement("std_int"));
            if(! _ret){
                cout << "can't find the expected type in xml file" << endl;
                return false;
            }
            return true;
        }

        // the external interface for deserializing char file
        inline bool deserialize_xml(char& object, string fileName){
            XMLError ret = doc.LoadFile(fileName.c_str());
            if(ret == 0){
                cout << "fail to load the xml file" << endl;
                return false;
            }
            root = doc.FirstChildElement("serialization");
        
            bool _ret = deserialize(object, root->FirstChildElement("std_char"));
            if(! _ret){
                cout << "can't find the expected type in xml file" << endl;
                return false;
            }
            return true;
        }

        // the external interface for deserializing double file
        inline bool deserialize_xml(double& object, string fileName){
            XMLError ret = doc.LoadFile(fileName.c_str());
            if(ret != 0){
                cout << "fail to load the xml file" << endl;
                return false;
            }
            root = doc.FirstChildElement("serialization");
        
            bool _ret = deserialize(object, root->FirstChildElement("std_double"));
            if(! _ret){
                cout << "can't find the expected type in xml file" << endl;
                return false;
            }
            return true;
        }

        // the external interface for deserializing string file
        inline bool deserialize_xml(string& object, string fileName){
            XMLError ret = doc.LoadFile(fileName.c_str());
            if(ret != 0){
                cout << "fail to load the xml file" << endl;
                return false;
            }
            root = doc.FirstChildElement("serialization");
        
            bool _ret = deserialize(object, root->FirstChildElement("std_string"));
            if(! _ret){
                cout << "can't find the expected type in xml file" << endl;
                return false;
            }
            return true;
        }

        // UserDefineType 
        template<class... Args>
        inline void useDefined_serialize_xml(string fileName, Args... rest){
            reset();
            useDefined_serialize(fileName, rest...);
        }



        template<class T>
        void serialize_xml(const vector<T>& vec, string fileName);
        template<class T>
        bool deserialize_xml(vector<T>& vec, string fileName);
        template<class T>
        void serialize_xml(const list<T>& l, string fileName);
        template<class T>
        bool deserialize_xml(list<T>& l, string fileName);
        template<class first, class second>
        void serialize_xml(const pair<first, second>& p, string fileName);
        template<class first, class second>
        bool deserialize_xml(pair<first, second>& p, string fileName);
        template<class T>
        void serialize_xml(const set<T>& s, string fileName);
        template<class T>
        bool deserialize_xml(set<T>& s, string fileName);
        template<class K, class V>
        void serialize_xml(const map<K,V>& m, string fileName);
        template<class K, class V>
        bool deserialize_xml(map<K,V>& m, string fileName);

    private:
        // to serialize the bool type into xml file
        inline void serialize(const bool& object, XMLElement* node) {
            XMLElement* item = doc.NewElement("std_bool");
            item->SetAttribute("value", to_string(object).c_str());
            node->InsertEndChild(item);
        }

        // to serialize the char type into xml file
        inline void serialize(const char& object, XMLElement* node){
            XMLElement* item = doc.NewElement("std_char");
            item->SetAttribute("value", to_string(object).c_str());
            node->InsertEndChild(item);
        }

        // to serialize the int type into xml file
        inline void serialize(const int& object, XMLElement* node){
            XMLElement* item = doc.NewElement("std_int");
            item->SetAttribute("value", to_string(object).c_str());
            node->InsertEndChild(item);
        }

        // to serialize the double type into xml file
        inline void serialize(const double& object, XMLElement* node){
            XMLElement* item = doc.NewElement("std_double");
            item->SetAttribute("value", to_string(object).c_str());
            node->InsertEndChild(item);
        }

        // to serialize the string type into xml file
        inline void serialize(const string& object, XMLElement* node) {
            XMLElement* item = doc.NewElement("std_string");
            item->SetAttribute("value", object.c_str());
            node->InsertEndChild(item);
        }    

        // UserDefineType 
        template<class H, class... Args>
        inline void useDefined_serialize(string fileName, H head, Args... rest){
            serialize(head, root);
            useDefined_serialize(fileName, rest...);
        }

        inline void useDefined_serialize(string fileName){
            save(fileName);
        }

        // to deserialize the bool type from xml file
        inline bool deserialize(bool& object, XMLElement* node){
            if(node == nullptr){
                return false;
            }
            string value = node->Attribute("value");
            object = stoi(value);
            return true;
        }

        // to deserialize the char type from xml file
        inline bool deserialize(char& object, XMLElement* node){
            if(node == nullptr){
                return false;
            }
            string value = node->Attribute("value");
            object = stoi(value);
            return true;
        }

        // to deserialize the int type from xml file
        inline bool deserialize(int& object, XMLElement* node){
            if(node == nullptr){
                return false;
            }
            string value = node->Attribute("value");
            object = stoi(value);
            return true;
        }

        // to deserialize the double type from xml file
        inline bool deserialize(double& object, XMLElement* node){
            if(node == nullptr){
                return false;
            }
            string value = node->Attribute("value");
            object = stod(value);
            return true;
        }

        // to deserialize the string type from xml file
        inline bool deserialize(string& object, XMLElement* node){
            if(node == nullptr){
                return false;
            }
            string value = node->Attribute("value");
            object = value;
            return true;
        }

        template<class T>
        void serialize(const vector<T>& vec, XMLElement* node);
        template<class T>
        bool deserialize(vector<T>& vec, XMLElement* node);
        template<class T>
        void serialize(const list<T>& l, XMLElement* node);
        template<class T>
        bool deserialize(list<T>& l, XMLElement* node);
        template<class first, class second>
        void serialize(const pair<first, second>& p, XMLElement* node);
        template<class first, class second>
        bool deserialize(pair<first, second>& p, XMLElement* Node);
        template<class T>
        void serialize(const set<T>& s, XMLElement* node);
        template<class T>
        bool deserialize(set<T>& s, XMLElement* node);
        template<class K, class V>
        void serialize(const map<K,V>& m, XMLElement* node);
        template<class K, class V>
        bool deserialize(map<K,V>& m, XMLElement* node);
    };

    // to serialize the vector type into xml file
    template<class T>
    void xmlSerialBase::serialize(const vector<T>& vec, XMLElement* node){
        XMLElement* item = doc.NewElement("std_vector");
        item->SetAttribute("size", to_string(vec.size()).c_str());
        node->InsertEndChild(item);
        for(auto& elem: vec){
            serialize(elem, item);
        }
        return ;
    }

    // the external interface for serializing the vector xml
    template<class T>
    void xmlSerialBase::serialize_xml(const vector<T>& vec, string fileName){
        reset();
        serialize(vec, root);
        save(fileName);
    }

    // to deserialize vector type from xml file
    template<class T>
    bool xmlSerialBase::deserialize(vector<T>& vec, XMLElement* node){
        if(node == nullptr){
            return false;
        }
        XMLElement* child = node->FirstChild()->ToElement();
        for(int i=0; i<atoi(node->Attribute("size")); i++){
            T  item;
            deserialize(item, child);
            vec.emplace_back(item);
            if(child->NextSibling()){
                child = child->NextSibling()->ToElement();
            }
        }
        return true;
    }

    // the external interface for deserializing the vector xml
    template<class T>
    bool xmlSerialBase::deserialize_xml(vector<T>& vec, string fileName){
        XMLError ret = doc.LoadFile(fileName.c_str());
        if(ret != 0){
           cout << "fail to load the xml file" << endl;
           return false;
        }

        root = doc.FirstChildElement("serialization");
        bool _ret = deserialize(vec, root->FirstChildElement("std_vector"));
        if(! _ret){
            cout << "can't find the expected type in xml file" << endl;
            return false;
        }
        return true;
    }
    
    // to serialize the list type into xml file
    template<class T>
    void xmlSerialBase::serialize(const list<T>& l, XMLElement* node){
        XMLElement* item = doc.NewElement("std_list");
        item->SetAttribute("size", to_string(l.size()).c_str());
        node->InsertFirstChild(item);
        for(auto& elem :l){
            serialize(elem, item);
        }
        
    };

    // the external interface for serializing the list xml
    template<class T>
    void xmlSerialBase::serialize_xml(const list<T>& l, string fileName){
        reset();
        serialize(l, root);
        save(fileName);
        return ;
    }

    // to deserializing the list type from xml file
    template<class T>
    bool xmlSerialBase::deserialize(list<T>& l, XMLElement* node){
        if(node == nullptr){
            return false;
        }
        XMLElement* child = node->FirstChild()->ToElement();
        for(int i=0; i<atoi(node->Attribute("size")); i++){
            T item;
            deserialize(item, child);
            l.push_back(item);
            if(child->NextSibling()){
                child = child->NextSibling()->ToElement();
            }
        }
        return true;
    }

    // the external interface for deserializing the list xml
    template<class T>
    bool xmlSerialBase::deserialize_xml(list<T>& l, string fileName){
        XMLError ret = doc.LoadFile(fileName.c_str());
        if(ret != 0){
            cout << "fail to load the xml file" << endl; 
            return false;
        }
        root = doc.FirstChildElement("serialization");
        bool _ret = deserialize(l, root->FirstChildElement("std_list"));
        if(! _ret){
            cout << "can't find the expected type in xml file" << endl;
            return false;
        }
        return true;
    }

    // to serialize the pair type into xml file
    template<class first, class second>
    void xmlSerialBase::serialize(const pair<first, second>& p, XMLElement* node){
        XMLElement* item = doc.NewElement("std_pair");
        XMLElement* p1 = doc.NewElement("first");
        serialize(p.first, p1);
        item->InsertFirstChild(p1);
        XMLElement* p2 = doc.NewElement("second");
        serialize(p.second, p2);
        item->InsertEndChild(p2);
        node->InsertEndChild(item);
        return ;
    }

    // the external interface for serializing the pair xml
    template<class first, class second>
    void xmlSerialBase::serialize_xml(const pair<first, second>& p, string fileName){
        reset();
        serialize(p, root);
        save(fileName);
        return;
    }

    // to deserialize the pair type from xml file
    template<class first, class second>
    bool xmlSerialBase::deserialize(pair<first, second>& p, XMLElement* node){
        if(node == nullptr){
            return false;
        }
        XMLElement* p1 = node->FirstChildElement("first");
        deserialize(p.first, p1->FirstChild()->ToElement());
        XMLElement* p2 = node->FirstChildElement("second");
        deserialize(p.second, p2->FirstChild()->ToElement());
        return true;
    }

    // the external interface for deserializing the pair xml
    template<class first, class second>
    bool xmlSerialBase::deserialize_xml(pair<first, second>& p, string fileName){
        XMLError ret = doc.LoadFile(fileName.c_str());
        if(ret != 0){
            cout << "fail to load the xml file" << endl;
            return false;
        }
        root = doc.FirstChildElement("serialization");
        bool _ret = deserialize(p, root->FirstChildElement("std_pair"));
        if(! _ret){
            cout << "can't find the expected type in xml file" << endl;
            return false;
        }
        return true;
    }

    // to serialize the set type into xml file
    template<class T>
    void xmlSerialBase::serialize(const set<T>& s, XMLElement* node){
        XMLElement* item = doc.NewElement("std_set");
        item->SetAttribute("size", to_string(s.size()).c_str());
        node->InsertFirstChild(item);
        for(auto& elem : s){
            serialize(elem, item);
        }
        return ;
    }

    // the external interface for serializing the set xml
    template<class T>
    void xmlSerialBase::serialize_xml(const set<T>& s, string fileName){
        reset();
        serialize(s, root);
        save(fileName);
        return ;
    }

    // deserialize the set type from xml file
    template<class T>
    bool xmlSerialBase::deserialize(set<T>& s, XMLElement* node){
        if(node == nullptr){
            return false;
        }
        XMLElement* child = node->FirstChild()->ToElement();
        for(int i=0; i<atoi(node->Attribute("size")); i++){
            T elem;
            deserialize(elem, child);
            s.insert(elem);
            if(child->NextSibling()){
                child = child->NextSibling()->ToElement();
            }
        }
        return true;
    }

    // the external interface for deserializing the set xml
    template<class T>
    bool xmlSerialBase::deserialize_xml(set<T>& s, string fileName){
        XMLError ret = doc.LoadFile(fileName.c_str());
        if(ret != 0){
            cout << "fail to load the xml file" << endl;
            return false;           
        }
        root = doc.FirstChildElement("serialization");
        bool _ret = deserialize(s, root->FirstChildElement("std_set"));
        if(! _ret){
            cout << "can't find the expected type in xml file" << endl;
            return false;
        }
        return true;
    }

    // to serialize the xml file into xml file
    template<class K, class V>
    void xmlSerialBase::serialize(const map<K,V>& m, XMLElement* node){
        XMLElement* item = doc.NewElement("std_map");
        item->SetAttribute("size", to_string(m.size()).c_str());
        node->InsertFirstChild(item);
        for(auto& elem : m){
            serialize(make_pair(elem.first, elem.second), item);
        }
        return ;
    }

    // the external interface for serializing the map xml
    template<class K, class V>
    void xmlSerialBase::serialize_xml(const map<K,V>& m, string fileName){
        reset();
        serialize(m, root);
        save(fileName);
        return ;
    }

    // to deserialize map type from xml file
    template<class K, class V>
    bool xmlSerialBase::deserialize(map<K,V>& m, XMLElement* node){
        if(node == nullptr){
            return false;
        }
        XMLElement* child = node->FirstChild()->ToElement();
        for(int i=0; i<atoi(node->Attribute("size")); i++){
            pair<K,V> p;
            deserialize(p, child);
            m.insert(p);
            if(child->NextSibling()){
                child = child->NextSibling()->ToElement();
            }
        }
        return true;
    }

    // the external interface for deserializing the map xml
    template<class K, class V>
    bool xmlSerialBase::deserialize_xml(map<K,V>& m, string fileName){
        XMLError ret = doc.LoadFile(fileName.c_str());
        if(ret != 0){
            cout << "fail to load the xml file" << endl;
            return false;           
        }
        root = doc.FirstChildElement("serialization");
        bool _ret = deserialize(m, root->FirstChildElement("std_map"));
        if(! _ret){
            cout << "can't find the expected type in xml file" << endl;
            return false;
        }
        return true;
    }
};

#endif