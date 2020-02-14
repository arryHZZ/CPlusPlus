#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "fileManager.h"
#include"fileutil.h"

//扫描磁盘信息
void FileManger::scannereDir(const std::string& path)
{
	//清理容器
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
		//初始化MD5初始值
		_md5.reset();
		_md5toFiles.insert(make_pair(_md5.getFileMD5(f.c_str()), f));
	}
}

//获取重复的文件
void FileManger::getCopList()
{
	_filestoMD5.clear();
	auto it = _md5toFiles.begin();
	while (it != _md5toFiles.end())
	{
		//查看MD5相同文件的个数是否大于1
		if (_md5toFiles.count(it->first) > 1)
		{
			//查找每一个MD5对应文件的所有文件集合
			auto pairIt = _md5toFiles.equal_range(it->first);
			auto begin = pairIt.first;
			while (begin != pairIt.second)
			{
				//保存重复文件的映射关系
				_filestoMD5.insert(make_pair(begin->second, begin->first));
				++begin;
			}
			//移动到下一个不同MD5的文件的位置
			it = pairIt.second;
		}
		else
		{
			it = _md5toFiles.erase(it);
			_files.erase(it->second);
		}
	}
}

//删除重复的文件，相同内容的文件只保留一份
void FileManger::deleteByName(const std::string& name)
{

}

void FileManger::deleteByMD5(const std::string& md5)
{

}

void FileManger::deleteAllCopy()
{

}

//模糊删除，删除包含输入字符的文件中重复的文件
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
			std::cout << "\t第" << idx << "个文件" << std::endl;
			std::cout << curIt->second << std::endl;
			count++;
		}
		it = pairIt.second;
	}
	std::cout << "文件总数: " << total << "\t" << count << std::endl;
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