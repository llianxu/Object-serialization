#ifndef __SERIAL2BIN_HPP__
#define __SERIAL2BIN_HPP__

#include "global.h"

using namespace std;

namespace serial2bin{
    template<class T>
    void serialize(T& item, string fileName){
        fstream file;
        file.open(fileName, ios::out | ios::binary);
        file.write(reinterpret_cast<char*>(&item), sizeof(item));
        file.flush();
        file.close();
    }

    template<class T>
    void deserialize(T& item, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        file.read(reinterpret_cast<char*>(&item), sizeof(item));
        file.close();
    }

    // string's serialize
    //string_write is used to write string to the binary data
    // const for set
    static void write(const string& str, ostream& file){
        int n = str.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        file.write(str.c_str(), n);
        return ; 
    }

    void serialize(string& str, string fileName){
        fstream file;
        file.open(fileName, ios::out | ios::binary);
        write(str, file);
        file.flush();
        file.close();
    }

    // string's deserialize
    //string_read is used to read string from the binary data
    static void read(string& str, istream& file){
        int n = 0;
        file.read(reinterpret_cast<char*>(&n), sizeof(n));
        str.resize(n);
        file.read(const_cast<char*>(str.c_str()), n);
        return ; 
    }

    void deserialize(string& str, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        read(str, file);
        file.flush();
        file.close();
    }

    //vector's serialize
	//vector_write is used to write vector to the binary file
    template<class T>
    static void write(vector<T>& v, ostream& file){
        int n = v.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : v){
            file.write(reinterpret_cast<char*>(&item), sizeof(item));
        }
        return ;
    }

    static void write(vector<string>& v, ostream& file){
        int n = v.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : v){
            write(item, file);
        }
        return ;
    }

    template<class T>
    void serialize(vector<T>& v, string fileName){
        fstream file;
        file.open(fileName, ios::out | ios::binary);
        write(v, file);
        file.flush();
        file.close();
    }


    //vector's deserialize
    //vector_read is used to read from the binary data
    template<class T>
    static void read(vector<T> &v, istream& file){
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

    static void read(vector<string> &v, istream& file){
        if(!file.eof()){
            v.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                string str;
                read(str, file);
                v.emplace_back(str);
            }
            return ;
        }
    }

    template<class T>
    void deserialize(vector<T> &v, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        read(v, file);
        file.flush();
        file.close();
        return ; 
    }

    
    //list's serialize
	//list_write is used to write list to the binary file
    template<class T>
    static void write(list<T>& l, ostream& file){
        int n = l.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : l){
            file.write(reinterpret_cast<char*>(&item), sizeof(item));
        }
        return ;

    }

    static void write(list<string>& l, ostream& file){
        int n = l.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : l){
            write(item, file);
        }
        return ;
    }

    template<class T>
    void serialize(list<T>& l, string fileName){
        fstream file;
        file.open(fileName, ios::out | ios::binary);
        write(l, file);
        file.flush();
        file.close();
    }

    //list's deserialize
	//list_read is used to read list from the binary file
    template<class T>
    static void read(list<T>& l, istream& file){
        if(!file.eof()){
            l.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                T item;
                file.read(reinterpret_cast<char*>(&item), sizeof(item));
                l.emplace_back(item);
            }
        }
        return ;
    }


    static void read(list<string>& l, istream& file){
        if(!file.eof()){
            l.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                string str;
                read(str, file);
                l.emplace_back(str);
            }
        }
        return ;
    }

    template<class T> 
    void deserialize(list<T>& l, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        read(l, file);
        file.flush();
        file.close();
    }

    //set's serialize
	//set_write is used to write set to the binary file
    template<class T>
    static void write(set<T>& s, ostream& file){
        int n = s.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : s){
            T* ptr = const_cast<T*>(&item);
            file.write(reinterpret_cast<char*>(ptr), sizeof(item));
        }
        return ;
    }

    static void write(set<string>& s, ostream& file){
        int n = s.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : s){
            write(item, file);
        }
        return ;
    }

    template<class T>
    void serialize(set<T> &s, string fileName){
        fstream file;
        file.open(fileName, ios::out | ios::binary);
        write(s, file);
        file.flush();
        file.close();
    }

    //set's deserialize
	//set_read is used to read set from the binary file
    template<class T>
    static void read(set<T>& s, istream& file){
        if(!file.eof()){
            s.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                T item;
                file.read(reinterpret_cast<char*>(&item), sizeof(item));
                s.insert(item);
            }
        }
    }

    static void read(set<string>& s, istream& file){
        if(!file.eof()){
            s.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                string str;
                read(str, file);
                s.insert(str);
            }
        }
        return ;
    }

    template<class T>
    void deserialize(set<T>& s, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        read(s, file);
        file.flush();
        file.close();
    }

    //map's serialize
    //map_write is used to write map to the binary file
    template<class K, class V>
    static void write(map<K,V>& m, ostream& file){
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
    static void write(map<K,string>& m, ostream& file){
        int n = m.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : m){
            K* ptrk;
            ptrk = const_cast<K*>(&(item.first));
            file.write(reinterpret_cast<char*>(ptrk), sizeof(item.first));
            write(item.second, file);
        }
        return ;
    }

    template<class V>
    static void write(map<string,V>& m, ostream& file){
        int n = m.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : m){
            write(item.first, file);
            V* ptrv;
            ptrv = const_cast<V*>(&(item.second));
            file.write(reinterpret_cast<char*>(ptrv), sizeof(item.second));
        }
        return ;
    }

    static void write(map<string, string>& m, ostream& file){
        int n = m.size();
        file.write(reinterpret_cast<char*>(&n), sizeof(n));
        for(auto& item : m){
            write(item.first, file);
            write(item.second, file);
        }
        return ;
    }

    template<class K, class V>
    static void serialize(map<K,V>& m, string fileName){
        fstream file;
        file.open(fileName, ios::out | ios::binary);
        write(m, file);
        file.flush();
        file.close();
    }

    //map's deserialize
    //map_read is used to read map from the binary file
    template<class K, class V>
    static void read(map<K,V>& m, istream& file){
        if(!file.eof()){
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
        }
        return;
    }

    template<class K>
    static void read(map<K,string>& m, istream& file){
        if(!file.eof()){
            m.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                K tempK;
                file.read(reinterpret_cast<char*>(&tempK), sizeof(tempK));
                string tempV;
                read(tempV, file);
                m.insert(pair<K,string>(tempK, tempV));
            }
        }
        return;
    }

    template<class V>
    static void read(map<string,V>& m, istream& file){
        if(!file.eof()){
            m.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                string tempK;
                read(tempK, file);
                V tempV;
                file.read(reinterpret_cast<char*>(&tempV), sizeof(tempV));
                m.insert(pair<string,V>(tempK, tempV));
            }
        }
        return;
    }

    static void read(map<string,string>& m, istream& file){
        if(!file.eof()){
            m.clear();
            int n = 0;
            file.read(reinterpret_cast<char*>(&n), sizeof(n));
            for(int i=0; i<n; i++){
                string tempK;
                read(tempK, file);
                string tempV;
                read(tempV, file);
                m.insert(pair<string,string>(tempK, tempV));
            }
        }
        return;
    } 

    template<class K, class V>
    void deserialize(map<K,V>& m, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        read(m, file);
        file.flush();
        file.close();
    }   
}
#endif