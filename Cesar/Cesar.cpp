#include "stdafx.h"
#include "Cesar.h"
#include <iostream>

using namespace std;

double f[26];
double p[26] = {0.0817, 0.0149, 0.0278, 0.0425, 0.127, 0.0223, 0.0202, 0.0609, 0.0697, 0.0015, 0.0077, 0.0402, 0.0241, 
	0.0675, 0.0751, 0.0193, 0.0009, 0.0599, 0.0633, 0.0906, 0.0276, 0.0098, 0.0236, 0.0015, 0.0197, 0.0007};

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
						
							if(((buff[i]+n)>90)&&((buff[i]+n)<123)) buff[i] = (buff[i]+n)%90+96;
							if ((buff[i]+n)>122) buff[i]= (buff[i]+n)%122 +65;

							else	buff[i] += n;
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
				if((buff[i]-n)<65) buff[i]=122-65%(buff[i]-n);

				if(((buff[i]-n)>90)&&((buff[i]-n)<97)) buff[i] = 90-(buff[i]-n)%97;

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
	//double f[26];
	for(int i=0; i<26;i++)	f[i]=0;

	if(strlen(buff)!=0)
	{
		for(int i = 0;i < strlen(buff); i++) 
		{
			buff[i] = toupper(buff[i]);
			f[buff[i]-65]++;
			
		}

		int maxValue=0, index=0;
		for(int i = 0;i < 26; i++) 
		{
			f[i]/=strlen(buff);
			if (f[i]>maxValue) {maxValue=f[i]; index = i;}
		}
		
		unsigned int s = f[index]+65-'E';// сдвиг

		for(int i = 0;i < strlen(buff); i++)
		    buff[i] -= s;
		cout<<buff<<endl;

		getchar();
		//DecodeFromCesar(buff,s);

	}
	return;
}


CCesar::~CCesar(void)
{
}
