#ifndef __SERIAL2BIN_HPP__
#define __SERIAL2BIN_HPP__

#include "global.h"

using namespace std;

namespace serial2bin{
    // serialization for arithmetic
    template<class T>
    void serialize_bin(T& item, string fileName){
        fstream file;
        //ios:app add the content for file's end
        file.open(fileName, ios::app | ios::binary);
        // cast the pointer to char* for writing byte one by one into file
        file.write(reinterpret_cast<char*>(&item), sizeof(item));
        // flush the cache
        file.flush();
        file.close();
    }
    // deserialization for arithmetic
    template<class T>
    void deserialize_bin(T& item, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        file.read(reinterpret_cast<char*>(&item), sizeof(item));
        file.close();
    }

    // string's serialize
    //string_serialize is used to write string to the binary data
    // string_serialize_bin is the external interface
    // const for set and map
    static void serialize(const string& str, ostream& file){
        int n = str.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        // be careful for string need convert to const char*
        file.write(str.c_str(), n);
        return ; 
    }

    void serialize_bin(string& str, string fileName){
        fstream file;
        file.open(fileName, ios::app | ios::binary);
        serialize(str, file);
        file.flush();
        file.close();
    }

    // string's deserialize
    //string_deserialize is used to read string from the binary data
    //string _deserialize_bin is external interface
    static void deserialize(string& str, istream& file){
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        str.resize(n);  // before read, we must allocate the storage 
        file.read(const_cast<char*>(str.c_str()), n);
        return ; 
    }


    void deserialize_bin(string& str, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        deserialize(str, file);
        file.flush();
        file.close();
    }

    //vector's serialize
	//vector_serialize is used to write vector to the binary file
    //vector_serialize_bin is external interface
    template<class T>
    static void serialize(vector<T>& v, ostream& file){
        int n = v.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : v){
            file.write(reinterpret_cast<char*>(&item), sizeof(item));
        }
        return ;
    }

    static void serialize(vector<string>& v, ostream& file){
        int n = v.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : v){
            serialize(item, file);
        }
        return ;
    }

    template<class T>
    void serialize_bin(vector<T>& v, string fileName){
        fstream file;
        file.open(fileName, ios::app | ios::binary);
        serialize(v, file);
        file.flush();
        file.close();
    }


    //vector's deserialize
    //vector_deserialize is used to read from the binary data
    //vector_deserialize_bin is external interface
    template<class T>
    static void deserialize(vector<T> &v, istream& file){
        if(!file.eof()){
            v.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                T temp = 0;
                file.read(reinterpret_cast<char*>(&temp), sizeof(temp));
                v.emplace_back(temp);
            }
            return ;
        }
    }

    static void deserialize(vector<string> &v, istream& file){
        v.clear();
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int i=0; i<n; i++){
            string str;
            deserialize(str, file);
            v.emplace_back(str);
        }
        return ;
    }

    template<class T>
    void deserialize_bin(vector<T> &v, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        deserialize(v, file);
        file.flush();
        file.close();
        return ; 
    }

    
    //list's serialize
	//list_serialize is used to write list to the binary file
    //list _serialize_bin is external interface
    template<class T>
    static void serialize(list<T>& l, ostream& file){
        int n = l.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : l){
            file.write(reinterpret_cast<char*>(&item), sizeof(item));
        }
        return ;
    }

    static void serialize(list<string>& l, ostream& file){
        int n = l.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : l){
            serialize(item, file);
        }
        return ;
    }

    template<class T>
    void serialize_bin(list<T>& l, string fileName){
        fstream file;
        file.open(fileName, ios::app | ios::binary);
        serialize(l, file);
        file.flush();
        file.close();
    }

    //list's deserialize
	//list_deserialize is used to read list from the binary file
    //list_deserialize_bin is external interface
    template<class T>
    static void deserialize(list<T>& l, istream& file){
            l.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                T item;
                file.read(reinterpret_cast<char*>(&item), sizeof(item));
                l.emplace_back(item);
            }
        return ;
    }


    static void deserialize(list<string>& l, istream& file){
        l.clear();
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int i=0; i<n; i++){
            string str;
            deserialize(str, file);
            l.emplace_back(str);
        }
        return ;
    }

    template<class T> 
    void deserialize_bin(list<T>& l, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        deserialize(l, file);
        file.flush();
        file.close();
    }

    //set's serialize
	//set_serialize is used to write set to the binary file
    //set_serialize_bin is external interface
    template<class T>
    static void serialize(set<T>& s, ostream& file){
        int n = s.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : s){
            T* ptr = const_cast<T*>(&item);
            file.write(reinterpret_cast<char*>(ptr), sizeof(item));
        }
        return ;
    }

    static void serialize(set<string>& s, ostream& file){
        int n = s.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : s){
            serialize(item, file);
        }
        return ;
    }

    template<class T>
    void serialize_bin(set<T> &s, string fileName){
        fstream file;
        file.open(fileName, ios::app | ios::binary);
        serialize(s, file);
        file.flush();
        file.close();
    }

    //set's deserialize
	//set_deserialize is used to read set from the binary file
    //set_deserialize is external interface
    template<class T>
    static void deserialize(set<T>& s, istream& file){
        s.clear();
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int i=0; i<n; i++){
            T item;
            file.read(reinterpret_cast<char*>(&item), sizeof(item));
            s.insert(item);
        }
        return ;
    }

    static void deserialize(set<string>& s, istream& file){
        s.clear();
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int i=0; i<n; i++){
            string str;
            deserialize(str, file);
            s.insert(str);
        }
        return ;
    }

    template<class T>
    void deserialize_bin(set<T>& s, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        deserialize(s, file);
        file.flush();
        file.close();
    }

    //map's serialize
    //map_serialize is used to write map to the binary file
    //map_serialize_bin is external interface
    template<class K, class V>
    static void serialize(map<K,V>& m, ostream& file){
        int n = m.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : m){
            K* ptrk = const_cast<K*>(&(item.first));
            file.write(reinterpret_cast<char*>(ptrk), sizeof(item.first));
            V* ptrv = const_cast<V*>(&(item.second));
            file.write(reinterpret_cast<char*>(ptrv),sizeof(item.second));
        }
        return ;
    }

    template<class K>
    static void serialize(map<K,string>& m, ostream& file){
        int n = m.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : m){
            K* ptrk;
            ptrk = const_cast<K*>(&(item.first));
            file.write(reinterpret_cast<char*>(ptrk), sizeof(item.first));
            serialize(item.second, file);
        }
        return ;
    }

    template<class V>
    static void serialize(map<string,V>& m, ostream& file){
        int n = m.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : m){
            serialize(item.first, file);
            V* ptrv;
            ptrv = const_cast<V*>(&(item.second));
            file.write(reinterpret_cast<char*>(ptrv), sizeof(item.second));
        }
        return ;
    }

    static void serialize(map<string, string>& m, ostream& file){
        int n = m.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : m){
            serialize(item.first, file);
            serialize(item.second, file);
        }
        return ;
    }

    template<class K, class V>
    static void serialize_bin(map<K,V>& m, string fileName){
        fstream file;
        file.open(fileName, ios::app | ios::binary);
        serialize(m, file);
        file.flush();
        file.close();
    }

    //map's deserialize
    //map_deserialize is used to read map from the binary file
    //map_deserialize_bin is external interface
    template<class K, class V>
    static void deserialize(map<K,V>& m, istream& file){
        m.clear();
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int i=0; i<n; i++){
            K tempK;
            file.read(reinterpret_cast<char*>(&tempK), sizeof(tempK));
            V tempV;
            file.read(reinterpret_cast<char*>(&tempV), sizeof(tempV));
            m.insert(pair<K,V>(tempK, tempV));
        }
        return;
    }

    template<class K>
    static void deserialize(map<K,string>& m, istream& file){
        m.clear();
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int i=0; i<n; i++){
            K tempK;
            file.read(reinterpret_cast<char*>(&tempK), sizeof(tempK));
            string tempV;
            deserialize(tempV, file);
            m.insert(pair<K,string>(tempK, tempV));
        }
        return;
    }

    template<class V>
    static void deserialize(map<string,V>& m, istream& file){
        m.clear();
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int i=0; i<n; i++){
            string tempK;
            deserialize(tempK, file);
            V tempV;
            file.read(reinterpret_cast<char*>(&tempV), sizeof(tempV));
            m.insert(pair<string,V>(tempK, tempV));
        }
        return;
    }

    static void deserialize(map<string,string>& m, istream& file){
        m.clear();
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        for(int i=0; i<n; i++){
            string tempK;
            deserialize(tempK, file);
            string tempV;
            deserialize(tempV, file);
            m.insert(pair<string,string>(tempK, tempV));
        }
        return;
    } 

    template<class K, class V>
    void deserialize_bin(map<K,V>& m, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        deserialize(m, file);
        file.flush();
        file.close();
    }   

    // usertype serialize 
	void userDefinedType(string fileName)
	{
		return;
	}

	template<class H,class ...Args>
	void userDefinedType(string fileName, H head, Args ...rest)
	{
		serialize_bin(head, fileName);
		userDefinedType(fileName, rest...);
	}
}
#endif