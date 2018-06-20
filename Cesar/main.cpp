// Cesar.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include "Cesar.h"
#include <fstream>
#include <stdio.h>
#include <conio.h>


using namespace std;

 ifstream MyFile; //описан. объекта MyFile экземпляра класса потока ifstream, обеспеч.чтение данных из файла


bool OpenFile(char FName[])  //Для ввода названия и открытия файла
{	
	
	while((FName[0]==0)) {
	cout<<("Whrite name of file> ");
	cin>>FName; //Ввод имени файла
	if(FName[0]==0) continue;
	MyFile.open(FName);
	if(!MyFile)
	{
		cout<<"Failed to open "<<FName<<" file!"; 
		getchar();
		return 0;
	} return 1;}
}; 

bool OpenFileConst(char FName[])  //Для открытия файла с вшитым названием
{	

	MyFile.open(FName);
	if(!MyFile)
	{

		cout<<"Failed to open "<<FName<<" file!"; 
		getchar();
		return 0;
	} return 1;
}; 



bool ReadText(char buff[]) //чтение из файла
{
	if(MyFile!=nullptr)
	{
		
		MyFile.read(buff,1024);
		MyFile.close();	
		return 1;
	}
	return 0;

}

bool SaveFile(char buff[]) //сохранения текста в файл
{
	ofstream out("Decoded.txt");
	if (!out) 
	{
		cout << "Cannot open file.\n";
		return 1;
	}
	out << buff << "\n";

	
	out.close ();
return 0;
}

bool Menu(char FName[], char buff[])
{
	FName[0]=0;
	cout<<"Choose decoder language: 1 - English, 2 - Russian"<<endl;

	char ilang=_getch();

	cout<<"1 - Choose the embedded file\n2 - enter the name manually"<<endl;
	char ifile =_getch();

	switch (ifile)
	{
	case '1': //вшитый
		{
			if(ilang=='1')FName="coded.txt";
			if(ilang=='2')FName="codedRus.txt";
			OpenFileConst(FName); //вшитое название файла

		}
	break;
	case '2': //вручную
		{
			OpenFile(FName); //для ввода названия файла вручную
		}
		break;
	default: return false;
		break;
	}

	ReadText(buff);

	switch (ilang)
	{
	case '1':
		{
			cout<<"Coded text in file: "<<endl;
			cout<<buff<<endl;
			cout<<endl;
			cout<<"Decoded text: "<<endl;
			CCesar::DecodeFromCesar(buff);

			SaveFile(buff);
			cout<<"\nDecoded text was saved in Decoded.txt file "<<endl;
		} 
		break;
	case '2':
		{
			setlocale( LC_ALL,"Russian" );
			cout<<"Coded text in file: "<<endl;
			cout<<buff<<endl;
			cout<<endl;


			cout<<"Decoded text: "<<endl;
			CCesar::DecodeFromCesarRus(buff);

			SaveFile(buff);
			cout<<"\nDecoded text was saived in Decoded.txt file "<<endl;


		} 
		break;
	default:
		break;
	}
	return true;	
}

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int step = 1;	 
   char buff[2024] = {0};
	char * nametextfile = new char[100];
	bool repeat = true;
	while(repeat) 
	{
		system("cls");
		repeat=false;
		Menu(nametextfile,buff);
		cout<<"Press SPACE for beginning"<<endl;
		if(_getch()==' ') repeat=true;
	}


	delete [] nametextfile;
	return 0;
}

