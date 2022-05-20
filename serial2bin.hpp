#ifndef __SERIAL2BIN_HPP__
#define __SERIAL2BIN_HPP__

#include "global.h"

using namespace std;

namespace serial2bin{
    template<class T>
    void serialize(T& object, string fileName){
        fstream file;
        file.open(fileName, ios::out | ios::binary);
        file.write(reinterpret_cast<char*>(&object), sizeof(object));
        file.flush();
        file.close();
    }

    template<class T>
    void deserialize(T object, string fileName){
        fstream file;
        file.open(fileName, ios::in | ios::binary);
        file.read(reinterpret_cast<char*>(&object), sizeof(object));
        file.close();
    }

    // string's serialize
    //string_write is used to write string to the binary data
    static void write(string& str, ostream& file){
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
}
#endif