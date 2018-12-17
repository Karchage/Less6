#include <windows.h>
#include <iostream>
#include <cstdio>

void levelD(int level)
{
	for(int i=0;i!=level;i++)
	{
		std::cout<<"   ";
	}
}
using namespace std;
HANDLE FindFolder(char *path,int &level,WIN32_FIND_DATA FolderPass)
{
	char buffer[250];
	wsprintfA (buffer, "%s\\*\0", path);
	HANDLE  FindFile = FindFirstFile(buffer,&FolderPass);
	if(FindFile != 0)
	{
		do
		{
			if(strcmp(".",FolderPass.cFileName)!=0 &&strcmp("..",FolderPass.cFileName) !=0)
			{
			if (FolderPass.dwFileAttributes == 16)
            { 	
                std::wcout<<FolderPass.cFileName<<"\n";
                
                char newpath[250];
                level++;
                sprintf (newpath,"%s\\%s", path,FolderPass.cFileName);
                FindFolder(newpath,level,FolderPass);
            }else {
            	levelD(level);
			std::wcout<<FolderPass.cFileName<<"\n";}   
		}
		}
		while( FindNextFile(FindFile, &FolderPass)!=0);
		level--;
		FindClose(FindFile);	
	}
}

int main()
{
	int level = 0;
	char dPath[250];
	WIN32_FIND_DATA FolderPass;
	std::cout<<"Please write path\n For examle C:\\User \n";
	std::cin>>dPath;
	FindFolder(dPath,level,FolderPass);	
	return 0;
}

