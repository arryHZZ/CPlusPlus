#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
//#include "md5.h"
#include "fileutil.h"
#include "fileManager.h"

using std::cout;
using std::endl;

//void testStringMD5()
//{
//	MD5 md5;
//	std::string str = "123456789abcdefgh";
//	cout << md5.getStringMD5(str) << endl;
//	md5.reset();
//	std::string str2 = "123456789abcdefgi";
//	cout << md5.getStringMD5(str2) << endl;
//}
//
//void testHex()
//{
//	MD5 md5;
//	uint32 n = 0x23456789;
//	cout << md5.changeHex(n) << endl;
//}
//
void testFileMD5()
{
	MD5 md5;
	const char* filepath = "a.txt";
	//const char* filepath2 = "b.txt";

	cout << md5.getFileMD5(filepath) << endl;
	md5.reset();
	//cout << md5.getFileMD5(filepath2) << endl;
}

//void testSearch()
//{
//	std::string path;
//	cout << "please input search dir:" << endl;
//	getline(std::cin, path);
//	std::vector<std::string> subFiles;
//	searchDir(path, subFiles);
//	for (const auto& f : subFiles)
//	{
//		cout << f << endl;
//	}
//}

void testFM()
{
	FileManger fm;
	std::string path = ".";
	fm.scannereDir(path);
}

int main()
{
	//MD5 md5;
	//testHex();
	//testStringMD5();
	//testFileMD5();
	//testSearch();
	testFM();
	return 0;
}