#include "stdafx.h"
#include "Cesar.h"
#include <iostream>

using namespace std;

double f[26];
double frus[33];
double p[26] = {0.0817, 0.0149, 0.0278, 0.0425, 0.127, 0.0223, 0.0202, 0.0609, 0.0697, 0.0015, 0.0077, 0.0402, 0.0241, 
	0.0675, 0.0751, 0.0193, 0.0009, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0007};
char alf[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

CCesar::CCesar(void)
{

}

void CCesar::TransformToCesar(char buff[], unsigned int n)
{
	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++)
		{
			
			if((buff[i]>64)&&(buff[i]<91)||(buff[i]>96)&&(buff[i]<123)) 
						{
							//кодирование дл€ маленьких букв
							if(((buff[i]+n)>96)&&((buff[i]+n)<=122)) 
							{
								
								buff[i] = (buff[i]+n)%97+97;
							}
							else
							if ((buff[i]+n)>122) buff[i]= (buff[i]+n)%122 +96;
							else

							//кодирование дл€ больших букв
							if(((buff[i]+n)>64)&&((buff[i]+n)<=90)) 
							{
								
								buff[i] = (buff[i]+n)%65+65;
							}
							else
							if (((buff[i]+n)>90)&&((buff[i]+n)<122)) buff[i]= (buff[i]+n)%90 +64;

							//кодирование дл€ всех букв
							else	buff[i] += n;
						}
			else continue;
		}
		cout<<buff<<endl;
	}
	return;
}

void CCesar::TransformToCesarRus(char buff[], unsigned int n)
{
	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++)
		{
			
			if((buff[i]>='а')&&(buff[i]<='€')||(buff[i]>='ј')&&(buff[i]<='я')) 
						{
							//кодирование дл€ маленьких букв

							if ((buff[i]>='а')&&((int)(buff[i]+n)>'€')) buff[i]= (buff[i]+n)%'€' +'а';
							else

							//кодирование дл€ больших букв
							if(((buff[i]+n)>'я')&&((buff[i])<='я')) 
							{
								
								buff[i] = buff[i]%'я'+'ј'+n-1;
							}

							//кодирование дл€ всех букв
							else	 buff[i] += n;
						}
			else continue;
		}
		cout<<buff<<endl;
	}
	return;
}

void CCesar::DecodeFromCesar(char buff[], unsigned int n)
{
	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++)
		{
			if((buff[i]>64)&&(buff[i]<91)||(buff[i]>96)&&(buff[i]<123))
			{

				//декодирование дл€ больших букв
							if((buff[i]-n)<65) 
							{
								
								buff[i] = 90-64%(buff[i]-n);
							}
							else

							//декодирование дл€ маленьких букв
							if(((buff[i]-n)>90)&&((buff[i]-n)<97)) 
							{
								//cout<<buff[i];
								buff[i] = 122-96%(buff[i]-n);
							}

							//кодирование дл€ всех букв
							else	buff[i] -= n;


			}
			else continue;
		}
	
		cout<<buff<<endl;
	}
	return;
}

void CCesar::DecodeFromCesarRus(char buff[], unsigned int n)
{
	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++)
		{
			if((buff[i]>='а')&&(buff[i]<='€')||(buff[i]>='ј')&&(buff[i]<='я')) 
			{

				//декодирование дл€ маленьких букв
							if(((buff[i]-n)<'а')&&(buff[i]>='а'))
							{
								
								buff[i] = '€'-'а'%(buff[i]);
							}
							else

							//декодирование дл€ больших букв
							if(((buff[i]-n)<'ј')&&(buff[i]>='ј')) 
							{
								//cout<<buff[i];
								buff[i] = 'я'-'ј'%(buff[i]);
							}

							//кодирование дл€ всех букв
							else	buff[i] -= n;


			}
			else continue;
		}
	
		cout<<buff<<endl;
	}
	return;
}


void CCesar::DecodeFromCesar(char buff[])
{
	char temp_buff[2024]={0};
	for(int i=0; i<26;i++)	f[i]=0;

	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++) 
		{

			temp_buff[i] = toupper(buff[i]);
			if(temp_buff[i]>'A'&&temp_buff[i]<'Z')
			f[temp_buff[i]-65]++;
			
		}

		double maxValue=0; int index=0;
		for(int i = 0;i < 26; i++) 
		{
			f[i]/=sizeof(buff);
			if (f[i]>maxValue) {maxValue=f[i]; index = i;}
		}
		
		unsigned int s = index+65-'E';// сдвиг
		//cout<<"step "<<s<<endl;


		DecodeFromCesar(buff,s);

	}
	return;
}

void CCesar::DecodeFromCesarRus(char buff[])
{
	char temp_buff[2024]={0};
	for(int i=0; i<33;i++)	f[i]=0;

	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++) 
		{

			temp_buff[i] = toupper(buff[i]);
			if(temp_buff[i]>'ј'&&temp_buff[i]<'я')
			f[temp_buff[i]-'ј']++;
			
		}

		double maxValue=0; int index=0;
		for(int i = 0;i < 33; i++) 
		{
			f[i]/=sizeof(buff);
			if (f[i]>maxValue) {maxValue=f[i]; index = i;}
		}
		
		unsigned int s = index+'ј'-'ќ';// сдвиг
		//cout<<"step "<<s<<endl;


		DecodeFromCesarRus(buff,s);

	}
	return;
}


CCesar::~CCesar(void)
{
}
