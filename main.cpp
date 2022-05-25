#include "serial2bin.hpp"

using namespace std;

void string_type();
void pair_type();
void vector_int_type();
void vector_double_type();
void vector_string_type();
void list_int_type();
void list_double_type();
void list_string_type();
void set_int_type();
void set_double_type();
void set_string_type();
void map_int2double_type();
void map_str2int_type();
void map_int2str_type();
void map_str2str_type();

int main(void){
    string_type();
	pair_type();
	vector_int_type();
	vector_double_type();
	vector_string_type();
	list_int_type();
	list_double_type();
	list_string_type();
	set_int_type();
	set_double_type();
	set_string_type();
	map_int2double_type();
	map_int2str_type();
	map_str2int_type();
	map_str2str_type();
    return 0;
}

void string_type(){
	cout << "test for string" << endl;
	string str0 = "test", str1;
	serial2bin::serialize(str0, "string.data");
	serial2bin::deserialize(str1, "string.data");
	cout << "str0 = " << str0 << endl;
	cout << "str1 = " << str1 << endl;
	cout << "Is equal:" << (str0 == str1) << endl;
	cout << endl;
}

void pair_type(){
	cout << "test for pair" << endl;
	pair<int, double> p0 = {5, 2.1};
	pair<int, double> p1;
	serial2bin::serialize(p0, "pair.data");
	serial2bin::deserialize(p1, "pair.data");
	cout << "P0 = " << p0.first << " " << p0.second << endl;
	cout << "P1 = " << p1.first << " " << p1.second << endl;
	cout << "Is equal:" << (p0 == p1) << endl;
	cout << endl;
}

void vector_int_type(){
	cout << "test for vector<int>" << endl;
	vector<int> v0 = {1,2,3};
	vector<int> v1;
	serial2bin::serialize(v0, "vector1.data");
	serial2bin::deserialize(v1, "vector1.data");
	cout << "v0 is " << v0[0] << " " << v0[1] << " " << v0[2] << endl;
	cout << "v1 is " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
	cout << "Is equal :" << (v0 == v1) << endl;
	cout << endl;
}

void vector_double_type(){
	cout << "test for vector<double>" << endl;
	vector<double> v0 = {1.2,2.4,3.6};
	vector<double> v1;
	serial2bin::serialize(v0, "vector2.data");
	serial2bin::deserialize(v1, "vector2.data");
	cout << "v0 is " << v0[0] << " " << v0[1] << " " << v0[2] << endl;
	cout << "v1 is " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
	cout << "Is equal :" << (v0 == v1) << endl;
	cout << endl;	
}

void vector_string_type(){
	cout << "test for vector<string>" << endl;
	vector<string> v0 = {"lianxu1", "lianxu2", "lianxu3"};
	vector<string> v1;
	serial2bin::serialize(v0, "vector3.data");
	serial2bin::deserialize(v1, "vector3.data");
	cout << "v0 is " << v0[0] << " " << v0[1] << " " << v0[2] << endl;
	cout << "v1 is " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
	cout << "Is equal :" << (v0 == v1) << endl;
	cout << endl;
}

void list_int_type(){
	cout << "test for list<int>" << endl;
	list<int> l0 = {1, 2, 3};
	list<int> l1;
	serial2bin::serialize(l0, "list1.data");
	serial2bin::deserialize(l1, "list1.data");
	cout << "l0 is ";
	for(auto iter = l0.begin(); iter != l0.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;

	cout << "l1 is ";
	for(auto iter = l1.begin(); iter != l1.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "Is equal:" << (l0 == l1) << endl;
	cout << endl;	

}

void list_double_type(){
	cout << "test for list<double>" << endl;
	list<double> l0 = {1.2, 2.4, 3.6};
	list<double> l1;
	serial2bin::serialize(l0, "list2.data");
	serial2bin::deserialize(l1, "list2.data");
	cout << "l0 is ";
	for(auto iter = l0.begin(); iter != l0.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;

	cout << "l1 is ";
	for(auto iter = l1.begin(); iter != l1.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "Is equal:" << (l0 == l1) << endl;
	cout << endl;	
}

void list_string_type(){
	cout << "test for list<string>" << endl;
	list<string> l0 = {"lianxu1", "lianxu2", "lianxu3"};
	list<string> l1;
	serial2bin::serialize(l0, "list3.data");
	serial2bin::deserialize(l1, "list3.data");
	cout << "l0 is ";
	for(auto iter = l0.begin(); iter != l0.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;

	cout << "l1 is ";
	for(auto iter = l1.begin(); iter != l1.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "Is equal:" << (l0 == l1) << endl;
	cout << endl;	

}

void set_int_type(){
	cout << "test for set<int>" << endl;
	set<int> s0 = {1,2,3};
	set<int> s1;
	serial2bin::serialize(s0, "set1.data");
	serial2bin::deserialize(s1, "set1.data");
	cout << "s0 is ";
	for(auto iter = s0.begin(); iter != s0.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;	


	cout << "s1 is ";
	for(auto iter = s1.begin(); iter != s1.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "Is equal:" << (s0 == s1) << endl;
	cout << endl;
}

void set_double_type(){
	cout << "test for set<double>" << endl;
	set<double> s0 = {1.2,2.4,3.6};
	set<double> s1;
	serial2bin::serialize(s0, "set2.data");
	serial2bin::deserialize(s1, "set2.data");
	cout << "s0 is ";
	for(auto iter = s0.begin(); iter != s0.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;

	cout << "s1 is ";
	for(auto iter = s1.begin(); iter != s1.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "Is equal:" << (s0 == s1) << endl;
	cout << endl;
}

void set_string_type(){
	cout << "test for set<string>" << endl;
	set<string> s0 = {"lianxu1","lianxu2","lianxu3"};
	set<string> s1;
	serial2bin::serialize(s0, "set3.data");
	serial2bin::deserialize(s1, "set3.data");
	cout << "s0 is ";
	for(auto iter = s0.begin(); iter != s0.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;

	cout << "s1 is ";
	for(auto iter = s1.begin(); iter != s1.end(); iter++){
		cout << *iter << " ";
	}
	cout << endl;
	cout << "Is equal:" << (s0 == s1) << endl;
	cout << endl;
}

void map_int2double_type(){
	cout << "test for map<int, double>" << endl;
	map<int, double> m0{
		{1, 1.2},
		{2, 2.4},
		{3, 3.6}
	};
	map<int, double> m1;
	serial2bin::serialize(m0, "map1.data");
	serial2bin::deserialize(m1, "map1.data");
	cout << "m0 is" << endl;
	for(auto iter = m0.begin(); iter != m0.end(); iter++){
		cout << (*iter).first << " " << (*iter).second << " ";
	}
	cout << endl;
	cout << "m1 is" << endl;
	for(auto iter = m1.begin(); iter != m1.end(); iter++){
		cout << (*iter).first << " " << (*iter).second << " ";
	}
	cout << endl;
	cout << "Is equal: " << (m0 == m1) << endl;
	cout << endl; 

}
void map_str2int_type(){
	cout << "test for map<string, int>" << endl;
	map<string, int> m0{
		{"lianxu1", 1},
		{"lianxu2", 2},
		{"lianxu3", 3}
	};
	map<string, int> m1;
	serial2bin::serialize(m0, "map1.data");
	serial2bin::deserialize(m1, "map1.data");
	cout << "m0 is" << endl;
	for(auto iter = m0.begin(); iter != m0.end(); iter++){
		cout << (*iter).first << " " << (*iter).second << " ";
	}
	cout << endl;
	cout << "m1 is" << endl;
	for(auto iter = m1.begin(); iter != m1.end(); iter++){
		cout << (*iter).first << " " << (*iter).second << " ";
	}
	cout << endl;
	cout << "Is equal: " << (m0 == m1) << endl;
	cout << endl; 	
}
void map_int2str_type(){
	cout << "test for map<int, string>" << endl;
	map<int, string> m0{
		{1, "lianxu1"},
		{2, "lianxu2"},
		{3, "lianxu3"}
	};
	map<int, string> m1;
	serial2bin::serialize(m0, "map1.data");
	serial2bin::deserialize(m1, "map1.data");
	cout << "m0 is" << endl;
	for(auto iter = m0.begin(); iter != m0.end(); iter++){
		cout << (*iter).first << " " << (*iter).second << " ";
	}
	cout << endl;
	cout << "m1 is" << endl;
	for(auto iter = m1.begin(); iter != m1.end(); iter++){
		cout << (*iter).first << " " << (*iter).second << " ";
	}
	cout << endl;
	cout << "Is equal: " << (m0 == m1) << endl;
	cout << endl; 
}
void map_str2str_type(){

	cout << "test for map<string, string>" << endl;
	map<string, string> m0{
		{"lianxu1k", "lianxu1v"},
		{"lianxu2k", "lianxu2v"},
		{"lianxu3k", "lianxu3v"}
	};
	map<string, string> m1;
	serial2bin::serialize(m0, "map1.data");
	serial2bin::deserialize(m1, "map1.data");
	cout << "m0 is" << endl;
	for(auto iter = m0.begin(); iter != m0.end(); iter++){
		cout << (*iter).first << " " << (*iter).second << " ";
	}
	cout << endl;
	cout << "m1 is" << endl;
	for(auto iter = m1.begin(); iter != m1.end(); iter++){
		cout << (*iter).first << " " << (*iter).second << " ";
	}
	cout << endl;
	cout << "Is equal: " << (m0 == m1) << endl;
	cout << endl; 
}