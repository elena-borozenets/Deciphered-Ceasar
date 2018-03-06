// Cesar.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include "Cesar.h"


using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int step = 3;
	

 
    char buff[1024] = {0};
    
	char a = 'a';
	char b= 'b';
	char z = 'z';
	char A = 'A';
	char B= 'B';
	char Z = 'Z';

	cout<<"a="<<(int)a<<" b="<<(int)b<<" z="<<(int)z<<endl;
	
	cout<<"A="<<(int)A<<" B="<<(int)B<<" Z="<<(int)Z<<endl;

	//cout<< (char)toupper(a)<<endl;
	
	cout<<"Whrite message for coding"<<endl;
	
	//getline(cin, buff);


    cin.getline(buff,sizeof(buff));
	
		//cout<<(char)91;
	//cout<<buff; 
	cout<<"Code: "<<endl;
	CCesar::TransformToCesar(buff, step);

	
    
   cout<<"Decode: "<<endl;
   CCesar::DecodeFromCesar(buff, step);
 // CCesar::DecodeFromCesar(buff);

	getchar();
	getchar();
	return 0;
}

