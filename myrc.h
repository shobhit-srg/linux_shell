#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h> 
#include <sys/wait.h> 
#include <sys/types.h> 
#include <sys/stat.h>
#include <fcntl.h> 
using namespace std;

string prompt="$";

void home1(string x)
	{
		char *cmd = new char[x.length()+1];
        strcpy(cmd,x.c_str());
		setenv("HOME",cmd,1);
	}

void user11(string x1)
	{
		char *cmd1 = new char[x1.length()+1];
        strcpy(cmd1,x1.c_str());
		setenv("USER",cmd1,1);
	}
	void HOSTNAME1(string x2)
	{
		char *cmd2 = new char[x2.length()+1];
        strcpy(cmd2,x2.c_str());
		setenv("HOSTNAME",cmd2,1);
	}

	void PATH1(string x3)
	{
		char *cmd3= new char[x3.length()+1];
        strcpy(cmd3,x3.c_str());
		setenv("PATH",cmd3,1);
	}
	void path(){
	cout<<getenv("PATH")<<endl;}

	void home(){
	cout<<getenv("HOME")<<endl;}

	void hostname(){
		//cout<<"fg";
		cout<<getenv("HOSTNAME");
	}
	void user1(){
		cout<<getenv("USER");
	} 
	string media(string x)
	{
		string delimiter = " ";
		string vlc="vlc ";
		string y = x.substr(x.find(delimiter)+1,x.length());
		vlc=vlc+y;
		return vlc;
	}
	string text11(string x)
	{
		string delimiter = " ";
		string vlc="sublime-text.subl ";
		string y = x.substr(x.find(delimiter)+1,x.length());
		vlc=vlc+y;
		return vlc;
	}