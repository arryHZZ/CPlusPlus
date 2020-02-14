#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "fileManager.h"
#include"fileutil.h"

//ɨ�������Ϣ
void FileManger::scannereDir(const std::string& path)
{
	//��������
	_files.clear();
	searchDir(path, _files);
	std::cout << "all list" << std::endl;
	showAllFile();
	getMd5toFiles();
	showCopyList();
	getCopList();
	std::cout << "copy list" << std::endl;
	showCopyList();
	showAllFile();

}

void FileManger::getMd5toFiles()
{
	_md5toFiles.clear();
	for (const auto& f : _files)
	{
		//��ʼ��MD5��ʼֵ
		_md5.reset();
		_md5toFiles.insert(make_pair(_md5.getFileMD5(f.c_str()), f));
	}
}

//��ȡ�ظ����ļ�
void FileManger::getCopList()
{
	_filestoMD5.clear();
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		//�鿴MD5��ͬ�ļ��ĸ����Ƿ����1
		if (_md5toFiles.count(it->first) > 1)
		{
			//����ÿһ��MD5��Ӧ�ļ��������ļ�����
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.first;
			while (begin != pairIt.second)
			{
				//�����ظ��ļ���ӳ���ϵ
				_filestoMD5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//�ƶ�����һ����ͬMD5���ļ���λ��
			it = pairIt.second;
		}
		else
		{
			it = _md5toFiles.erase(it);
			_files.erase(it->second);
		}
	}
}

//ɾ���ظ����ļ�����ͬ���ݵ��ļ�ֻ����һ��
void FileManger::deleteByName(const std::string& name)
{

}

void FileManger::deleteByMD5(const std::string& md5)
{

}

void FileManger::deleteAllCopy()
{

}

//ģ��ɾ����ɾ�����������ַ����ļ����ظ����ļ�
void FileManger::deleteByMatchName(const std::string& MatchName)
{

}

void FileManger::showCopyList()
{
	auto it = _md5toFiles.begin();
	int total = _md5toFiles.size();
	int count = 0;
	while (it != _md5toFiles.end())
	{
		int idx = 1;
		auto pairIt = _md5toFiles.equal_range(it->first);
		auto curIt = pairIt.first;
		std::cout << "cur MD5" << it->first << std::endl;
		while (curIt != pairIt.second)
		{
			std::cout << "\t��" << idx << "���ļ�" << std::endl;
			std::cout << curIt->second << std::endl;
			count++;
		}
		it = pairIt.second;
	}
	std::cout << "�ļ�����: " << total << "\t" << count << std::endl;
}
void FileManger::showAllFile()
{
	for (const auto& f : _files)
	{
		std::cout << f << std::endl;
	}
	std::cout << "file count: " << _files.size() << std::endl;
}
//void FileManger::showMD5Map();