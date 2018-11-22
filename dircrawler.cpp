//============================================================================
// Name        : dircrawler.cpp
// Author      : Mina Samaan
// Version     :
// Copyright   : Your copyright notice
// Description : a program to crawl the directories and files on linux
//============================================================================

#include <iostream>
#include <dirent.h>
#include <stack>

using namespace std;

int main(int argc, char *argv[]) {

	DIR *dir;
	struct dirent *direntry = NULL;
	string dirname;

	if (argc > 1)
		dirname = string(argv[1]);
	else
	{
		cout << " Usage dircrawler dir"<< endl ;
		return 0;
	}

	stack<string> mystack;
	mystack.push(dirname);

	while (!mystack.empty())
	{
		dirname = mystack.top();
		mystack.pop();
		/* Open the directory */
		if (!(dir = opendir(dirname.c_str())))
			continue;

		direntry = readdir(dir);

		while ((direntry = readdir(dir)) != NULL)
			{
			string tempstring(direntry->d_name);
				if (direntry->d_type == 4) //if it is a directory not a file
				{
					if(( tempstring != "." && tempstring != ".."))
						mystack.push(dirname + "/"+ tempstring);
				}
				else{
					cout << dirname << "/" << tempstring << endl ;
				}
			}
		/* close the directory */
		closedir(dir);
	}

	return 0;
}
