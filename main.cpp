#include "serial2bin.hpp"
#include "serial2xml.hpp"

using namespace std;

// test for serial2bin 
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
void userType_type();

// test for serial2xml
void xml_string_type();
void xml_vector_int_type();
void xml_vector_double_type();
void xml_vector_string_type();
void xml_list_int_type();
void xml_list_double_type();
void xml_list_string_type();
void xml_pair_int_double_type();
void xml_pair_int_string_type();
void xml_set_int_type();
void xml_set_double_type();
void xml_set_string_type();
void xml_map_int2double_type();
void xml_map_int2str_type();
void xml_map_str2int_type();
void xml_map_str2str_type();
void xml_userType_type();

struct usr_type{
	int num;
	string name;
	vector<double> vec;
};
int main(void){
    // string_type();
	// pair_type();
	// vector_int_type();
	// vector_double_type();
	// vector_string_type();
	// list_int_type();
	// list_double_type();
	// list_string_type();
	// set_int_type();
	// set_double_type();
	// set_string_type();
	// map_int2double_type();
	// map_int2str_type();
	// map_str2int_type();
	// map_str2str_type();
	userType_type();
	// xml_string_type();
   	// xml_string_type();
	// xml_vector_int_type();
	// xml_vector_double_type();
	// xml_vector_string_type();
	// xml_list_int_type();
	// xml_list_double_type();
	// xml_list_string_type();
	// xml_pair_int_double_type();
	// xml_pair_int_string_type();
	// xml_set_int_type();
	// xml_set_double_type();
	// xml_set_string_type();
	// xml_map_int2double_type();
	// xml_map_int2str_type();
	// xml_map_str2int_type();
	// xml_map_str2str_type();
	// xml_userType_type();
	return 0;
}

void string_type(){
	cout << "test for string" << endl;
	string str0 = "test", str1;
	serial2bin::serialize_bin(str0, "string.data");
	serial2bin::deserialize_bin(str1, "string.data");
	cout << "str0 = " << str0 << endl;
	cout << "str1 = " << str1 << endl;
	cout << "Is equal:" << (str0 == str1) << endl;
	cout << endl;
}

void pair_type(){
	cout << "test for pair" << endl;
	pair<int, double> p0 = {5, 2.1};
	pair<int, double> p1;
	serial2bin::serialize_bin(p0, "pair.data");
	serial2bin::deserialize_bin(p1, "pair.data");
	cout << "P0 = " << p0.first << " " << p0.second << endl;
	cout << "P1 = " << p1.first << " " << p1.second << endl;
	cout << "Is equal:" << (p0 == p1) << endl;
	cout << endl;
}

void vector_int_type(){
	cout << "test for vector<int>" << endl;
	vector<int> v0 = {1,2,3};
	vector<int> v1;
	serial2bin::serialize_bin(v0, "vector1.data");
	serial2bin::deserialize_bin(v1, "vector1.data");
	cout << "v0 is " << v0[0] << " " << v0[1] << " " << v0[2] << endl;
	cout << "v1 is " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
	cout << "Is equal :" << (v0 == v1) << endl;
	cout << endl;
}

void vector_double_type(){
	cout << "test for vector<double>" << endl;
	vector<double> v0 = {1.2,2.4,3.6};
	vector<double> v1;
	serial2bin::serialize_bin(v0, "vector2.data");
	serial2bin::deserialize_bin(v1, "vector2.data");
	cout << "v0 is " << v0[0] << " " << v0[1] << " " << v0[2] << endl;
	cout << "v1 is " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
	cout << "Is equal :" << (v0 == v1) << endl;
	cout << endl;	
}

void vector_string_type(){
	cout << "test for vector<string>" << endl;
	vector<string> v0 = {"lianxu1", "lianxu2", "lianxu3"};
	vector<string> v1;
	serial2bin::serialize_bin(v0, "vector3.data");
	serial2bin::deserialize_bin(v1, "vector3.data");
	cout << "v0 is " << v0[0] << " " << v0[1] << " " << v0[2] << endl;
	cout << "v1 is " << v1[0] << " " << v1[1] << " " << v1[2] << endl;
	cout << "Is equal :" << (v0 == v1) << endl;
	cout << endl;
}

void list_int_type(){
	cout << "test for list<int>" << endl;
	list<int> l0 = {1, 2, 3};
	list<int> l1;
	serial2bin::serialize_bin(l0, "list1.data");
	serial2bin::deserialize_bin(l1, "list1.data");
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
	serial2bin::serialize_bin(l0, "list2.data");
	serial2bin::deserialize_bin(l1, "list2.data");
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
	serial2bin::serialize_bin(l0, "list3.data");
	serial2bin::deserialize_bin(l1, "list3.data");
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
	serial2bin::serialize_bin(s0, "set1.data");
	serial2bin::deserialize_bin(s1, "set1.data");
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
	serial2bin::serialize_bin(s0, "set2.data");
	serial2bin::deserialize_bin(s1, "set2.data");
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
	serial2bin::serialize_bin(s0, "set3.data");
	serial2bin::deserialize_bin(s1, "set3.data");
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
	serial2bin::serialize_bin(m0, "map1.data");
	serial2bin::deserialize_bin(m1, "map1.data");
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
	serial2bin::serialize_bin(m0, "map2.data");
	serial2bin::deserialize_bin(m1, "map2.data");
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
	serial2bin::serialize_bin(m0, "map3.data");
	serial2bin::deserialize_bin(m1, "map3.data");
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
	serial2bin::serialize_bin(m0, "map4.data");
	serial2bin::deserialize_bin(m1, "map4.data");
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

void userType_type(){
	usr_type u0;
	u0.name = "lianxu1";
	u0.num = 21;
	u0.vec = {1.2, 2.4, 3.6};
	usr_type u1;
	serial2bin::userDefinedType("usertype.data", u0.name,  u0.num, u0.vec);
	cout << "serialization for usertype successfully" << endl;
	return ;
}


void xml_string_type(){
	cout << "test for xml string " << endl;
	serial2xml::xmlSerialBase baseStr;
	string str0 = "lianxu";
	string str1 = "";
	baseStr.serialize_xml(str0, "str.xml");
	baseStr.deserialize_xml(str1, "str.xml");
	cout << "str0  is " << str0 << endl;
	cout << "str1  is " << str1 << endl;
	cout << "Is equal " << (str0 == str1) << endl;
	cout << endl;
	return ;
}

void xml_vector_int_type(){
	cout << "test for xml vector<int> " << endl;
	serial2xml::xmlSerialBase baseVector;
	vector<int> v0 = {1, 2, 3};
	vector<int> v1;
	baseVector.serialize_xml(v0, "vector1.xml");
	baseVector.deserialize_xml(v1, "vector1.xml");
	cout << "v0 is ";
	for(auto& item : v0){
		cout << item << " ";
	}
	cout << endl;
	cout << "v1 is ";
	for(auto& item : v1){
		cout << item << " ";
	}
	cout << endl;
	cout << "Is equal " << (v0 == v1) << endl;
	cout << endl;
}

void xml_vector_double_type(){
	cout << "test for xml vector<double> " << endl;
	serial2xml::xmlSerialBase baseVector;
	vector<double> v0 = {1.2, 2.4, 3.6};
	vector<double> v1;
	baseVector.serialize_xml(v0, "vector2.xml");
	baseVector.deserialize_xml(v1, "vector2.xml");
	cout << "v0 is ";
	for(auto& item : v0){
		cout << item << " ";
	}
	cout << endl;
	cout << "v1 is ";
	for(auto& item : v1){
		cout << item << " ";
	}
	cout << endl;
	cout << "Is equal " << (v0 == v1) << endl;
	cout << endl;
}

void xml_vector_string_type(){
	cout << "test for xml vector<string> " << endl;
	serial2xml::xmlSerialBase baseVector;
	vector<string> v0 = {"lianxu1", "lianxu2", "lianxu3"};
	vector<string> v1;
	baseVector.serialize_xml(v0, "vector3.xml");
	baseVector.deserialize_xml(v1, "vector3.xml");
	cout << "v0 is ";
	for(auto& item : v0){
		cout << item << " ";
	}
	cout << endl;
	cout << "v1 is ";
	for(auto& item : v1){
		cout << item << " ";
	}
	cout << endl;
	cout << "Is equal " << (v0 == v1) << endl;
	cout << endl;
}

void xml_list_int_type(){
	cout << "test for xml list<int> " << endl;
	serial2xml::xmlSerialBase baseList;
	list<int> l0 = {1, 2, 3};
	list<int> l1;
	baseList.serialize_xml(l0, "list1.xml");
	baseList.deserialize_xml(l1, "list1.xml");
	cout << "l0 is ";
	for(auto& item : l1){
		cout << item << " ";
	}
	cout << endl;
	cout << "l1 is ";
	for(auto& item : l1){
		cout << item << " ";
	}
	cout << endl;
	cout << "Is equal " << (l0 == l1) << endl;
	cout << endl;
}

void xml_list_double_type(){
	cout << "test for xml list<double>" << endl;
	serial2xml::xmlSerialBase baseList;
	list<double> l0 = {1.2, 2.4, 3.6};
	list<double> l1;
	baseList.serialize_xml(l0, "list2.xml");
	baseList.deserialize_xml(l1, "list2.xml");
	cout << "l0 is ";
	for(auto& item : l1){
		cout << item << " ";
	}
	cout << endl;
	cout << "l1 is ";
	for(auto& item : l1){
		cout << item << " ";
	}
	cout << endl;
	cout << "Is equal " << (l0 == l1) << endl;
	cout << endl;
}

void xml_list_string_type(){
	cout << "test for xml list<string>" << endl;
	serial2xml::xmlSerialBase baseList;
	list<string> l0 = {"lianxu1", "lianxu2", "lianxu3"};
	list<string> l1;
	baseList.serialize_xml(l0, "list3.xml");
	baseList.deserialize_xml(l1, "list3.xml");
	cout << "l0 is ";
	for(auto& item : l1){
		cout << item << " ";
	}
	cout << endl;
	cout << "l1 is ";
	for(auto& item : l1){
		cout << item << " ";
	}
	cout << endl;
	cout << "Is equal " << (l0 == l1) << endl;
	cout << endl;
}

void xml_pair_int_double_type(){
	cout << "test for xml pair<int, double>" << endl;
	serial2xml::xmlSerialBase basePair;
	pair<int, double> p0 = {1, 1.2};
	pair<int, double> p1;
	basePair.serialize_xml(p0, "pair1.xml");
	basePair.deserialize_xml(p1, "pair1.xml");
	cout << "p0 is " << p0.first << " " << p0.second << endl;
	cout << "p1 is " << p1.first << " " << p1.second << endl;
	cout << "Is equal " << (p0 == p1) << endl;
	cout << endl;
}

void xml_pair_int_string_type(){
	cout << "test for xml pair<int, string>" << endl;
	serial2xml::xmlSerialBase basePair;
	pair<int, string> p0 = {1, "lianxu"};
	pair<int, string> p1;
	basePair.serialize_xml(p0, "pair2.xml");
	basePair.deserialize_xml(p1, "pair2.xml");
	cout << "p0 is " << p0.first << " " << p0.second << endl;
	cout << "p1 is " << p1.first << " " << p1.second << endl;
	cout << "Is equal " << (p0 == p1) << endl;
	cout << endl;
}

void xml_set_string_type(){
	cout << "test for xml set<string>" << endl;
	set<string> s0{"lianxu1", "lianxu2", "lianxu3"};
	set<string> s1;
	serial2xml::xmlSerialBase baseSet;
	baseSet.serialize_xml(s0, "set3.xml");
	baseSet.deserialize_xml(s1, "set3.xml"); 
	cout << "s0 is ";
	for(auto& item : s0){
		cout << item << " ";
	}
	cout << endl;
	cout << "s1 is ";
	for(auto& item : s1){
		cout << item << " ";
	}
	cout << endl;
	cout << "is equal "<< (s0 == s1) << endl;
	cout << endl;
}
void xml_set_double_type(){
	cout << "test for xml set<double>" << endl;
	set<double> s0{1.2, 2.4, 3.6};
	set<double> s1;
	serial2xml::xmlSerialBase baseSet;
	baseSet.serialize_xml(s0, "set2.xml");
	baseSet.deserialize_xml(s1, "set2.xml"); 
	cout << "s0 is ";
	for(auto& item : s0){
		cout << item << " ";
	}
	cout << endl;
	cout << "s1 is ";
	for(auto& item : s1){
		cout << item << " ";
	}
	cout << endl;
	cout << "is equal "<< (s0 == s1) << endl;
	cout << endl;
}
void xml_set_int_type(){
	cout << "test for xml set<int>" << endl;
	set<int> s0{1, 2, 3};
	set<int> s1;
	serial2xml::xmlSerialBase baseSet;
	baseSet.serialize_xml(s0, "set1.xml");
	baseSet.deserialize_xml(s1, "set1.xml"); 
	cout << "s0 is ";
	for(auto& item : s0){
		cout << item << " ";
	}
	cout << endl;
	cout << "s1 is ";
	for(auto& item : s1){
		cout << item << " ";
	}
	cout << endl;
	cout << "is equal "<< (s0 == s1) << endl;
	cout << endl;
}

void xml_map_int2double_type(){
	cout << "test for xml map<int double>" << endl;
	serial2xml::xmlSerialBase baseMap;
	map<int, double> m0{
		{1, 1.2},
		{2, 2.4},
		{3, 3.6}
	};
	map<int, double> m1;
	baseMap.serialize_xml(m0, "map1.xml");
	baseMap.deserialize_xml(m1, "map1.xml");
	cout << "m0 is " << endl;
	for(auto& item : m0){
		cout << item.first << " " << item.second << endl;
	}
	cout << "m1 is " << endl;
	for(auto& item : m1){
		cout << item.first << " " << item.second << endl;
	}
	cout << "is equal " << (m0 == m1) << endl;
	cout << endl;
}
void xml_map_int2str_type(){
	cout << "test for xml map<int string>" << endl;
	serial2xml::xmlSerialBase baseMap;
	map<int, string> m0{
		{1, "lianxu1"},
		{2, "lianxu2"},
		{3, "lianxu3"}
	};
	map<int, string> m1;
	baseMap.serialize_xml(m0, "map2.xml");
	baseMap.deserialize_xml(m1, "map2.xml");
	cout << "m0 is " << endl;
	for(auto& item : m0){
		cout << item.first << " " << item.second << endl;
	}
	cout << "m1 is " << endl;
	for(auto& item : m1){
		cout << item.first << " " << item.second << endl;
	}
	cout << "is equal " << (m0 == m1) << endl;
	cout << endl;
}
void xml_map_str2int_type(){
	cout << "test for xml map<string int>" << endl;
	serial2xml::xmlSerialBase baseMap;
	map<string,int> m0{
		{"lianxu1", 1},
		{"lianxu2", 2},
		{"lianxu3", 3}
	};
	map<string, int> m1;
	baseMap.serialize_xml(m0, "map3.xml");
	baseMap.deserialize_xml(m1, "map3.xml");
	cout << "m0 is " << endl;
	for(auto& item : m0){
		cout << item.first << " " << item.second << endl;
	}
	cout << "m1 is " << endl;
	for(auto& item : m1){
		cout << item.first << " " << item.second << endl;
	}
	cout << "is equal " << (m0 == m1) << endl;
	cout << endl;
}
void xml_map_str2str_type(){
	cout << "test for xml map<string string>" << endl;
	serial2xml::xmlSerialBase baseMap;
	map<string,string> m0{
		{"lianxu1k", "lianxu1v"},
		{"lianxu2k", "lianxu2v"},
		{"lianxu3k", "lianxu3v"}
	};
	map<string, string> m1;
	baseMap.serialize_xml(m0, "map4.xml");
	baseMap.deserialize_xml(m1, "map4.xml");
	cout << "m0 is " << endl;
	for(auto& item : m0){
		cout << item.first << " " << item.second << endl;
	}
	cout << "m1 is " << endl;
	for(auto& item : m1){
		cout << item.first << " " << item.second << endl;
	}
	cout << "is equal " << (m0 == m1) << endl;
	cout << endl;	
}

void xml_userType_type(){
	cout << "test for xml userType" << endl;
	serial2xml::xmlSerialBase baseUsrType;
	usr_type u1 = {1, "lianxu", {1.2, 2.4, 3.6}};
	usr_type u2;
	baseUsrType.useDefined_serialize_xml("usr.xml", u1.num, u1.name, u1.vec);
	return ;
}