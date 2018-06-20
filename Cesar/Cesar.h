#pragma once
class CCesar
{
public:
	CCesar(void);
	static void TransformToCesar(char buff[], unsigned int n);
	static void TransformToCesarRus(char buff[], unsigned int n);
	static void DecodeFromCesar(char buff[], unsigned int n);
	static void DecodeFromCesarRus(char buff[], unsigned int n);
	static void DecodeFromCesar(char buff[]);
	static void DecodeFromCesarRus(char buff[]);
	~CCesar(void);

};

