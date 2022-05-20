#include "serial2bin.hpp"

using namespace std;

void string_type();
void vector_int_type();
void vector_double_type();
void vector_string_type();
void list_int_type();
void list_double_type();
void list_string_type();

int main(void){
    string_type();
	vector_int_type();
	vector_double_type();
	vector_string_type();
	list_int_type();
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