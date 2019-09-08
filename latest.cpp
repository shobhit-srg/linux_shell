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
#include <limits.h>
#include <fcntl.h> 
#include <bits/stdc++.h> 
#include <fstream> 
#include <signal.h>
#include <fstream>
#include "myrc.h"
using namespace std;
int flag;
int x;
map<string,string> ali;

char gpwd()
{
  char buf[1000];
  //Its pwd
  if (getcwd(buf, sizeof(buf)) != NULL)
    printf("%s",buf);
  else
    perror("Error:");
    
}
void parse(char *str,char **argv)
{
	string cd="cd";
	string exit="exit";
	 char *token = strtok(str, " "); 
	 int i=0;
   x=0;
    while (strcmp( token,"NULL")) 
    { 
    	argv[i++]=token;
        x++;
        token = strtok(NULL, " ");
    }
     // cout<<argv[i-1]-argv[0];
     argv[i]=NULL;
  
}
void tokenize(std::string const &str, const char delim, vector<string> &out)
{
  size_t start;
  size_t end = 0;

  while ((start = str.find_first_not_of(delim, end)) != string::npos)
  {
    end = str.find(delim, start);
    out.push_back(str.substr(start, end - start));
  }
}

void  execute(char **argv)
{
     pid_t  pid;
     int    status;

     if ((pid = fork()) < 0) {   
     cout<<"Error"<<endl;
          exit(1);
     }
     else if (pid == 0) {        
          if (execvp(*argv, argv) < 0) {     
          cout<<"Wrong Input"<<endl;
               exit(1);
          }
     }
     else {                                 
          while (wait(&status) != pid)     
               ;
     }
}
void pipe1(char **argx,int count)
{
  char *pi[64][64];
  int j,i=0,k;
     for(j=0;j<=count;j++)
      {
          for(k=0;k<4,argx[i]!=NULL;k++)
          {
            if(strcmp(argx[i], "|")==0)
            {
                //cout<<i;
                pi[j][k]=NULL;
                ++i;
              //  cout<<j<<k<<" "<<pi[j][k]<<endl;
                break;
            }
          
               pi[j][k]=argx[i];
                ++i;
            if(argx[i]==NULL)
              pi[j][k]==NULL;
          }
         
      }
    int x2=fork();
    if(x2==0)
    {
    for( i=0; i<count; i++)
    {
        int pd[2];
        pipe(pd);

        if (!fork()) 
        {  
            dup2(pd[1], 1); 
            execvp(*pi[i],pi[i]);
            perror("exec");
            abort();
        }
            dup2(pd[0], 0);
            close(pd[1]);
    }
    if(strcmp(argx[x-1], ">")!=0){
    execvp(*pi[i],pi[i]);
    perror("exec");
    abort();}
    
    }

    else
    {
        wait(NULL);
    }
   
}




int main()
{
  
	while(1)
	{
    HOSTNAME1("SRG");
		flag=0;
    char *argv[64];
		user1();
    cout<<"@";
    hostname();
    int uid=getuid();
    if(uid==1000)
    cout<<" "<<prompt<<" : ";
    char *ifile;
    char *ofile;
    char line[100];
		string command;
		getline(cin,command);
    if(command.empty())
    continue;
    ofstream out;
    out.open("history.txt",ios::out| ios::ate| ios::app);
    out << command << endl; 
    out.close(); 

    if(command.find("open") != std::string::npos) 
        {
            string command1;
            if(command.find(".mp4") != std::string::npos)
              {   command1=media(command);
                  command=command1;}

            else if(command.find(".mp3") != std::string::npos)
             {    command1=media(command);
                  command=command1;}
            else if(command.find(".txt") != std::string::npos) 
               { command1=text11(command);
                  command=command1;}
        }


      
  int xxx=count(command.begin(),command.end(),'|');
    command+=" NULL";
  
    //cout<<x;
    //cout<<command<<endl;
   for (auto itr = ali.begin(); itr != ali.end(); ++itr) { 
        if(itr->first==command)
           { command=itr->second; 
            break;}
    } 

     if (command.find(">") != std::string::npos && !(command.find(">>") != std::string::npos))
      {
         char *argv1[64];
          char *argv2[64];
          int pid;
          int s1;
          string delimiter = ">";
          string token1 = command.substr(0, command.find(delimiter));
          token1+=" NULL";
          string token2 = command.substr(command.find(delimiter)+1,command.length());
          token2.erase(
          remove( token2.begin(), token2.end(), '\"' ),
          token2.end()
          );
          char *t1 = new char[token1.length()+1];
          strcpy(t1,token1.c_str());
          parse(t1,argv1);
          char *t2 = new char[token2.length()+1];
          strcpy(t2,token2.c_str());
          parse(t2,argv2);
          if(t2[0]==' ')
          {
            ofile=++t2;
          }
          else 
          ofile=t2;
         // cout<<ofile;
          pid=fork();
          if (pid == 0)
          {
              if(ofile!=NULL)
            {
                  int fd2=open(ofile, O_WRONLY | O_CREAT, 0644);
                  dup2(fd2, STDOUT_FILENO);
                  close(fd2);
            }
          execvp(*argv1,argv1);
          }

          else {                                 
              while (wait(&s1) != pid)     
              ;
              }
            
          continue;
      } 

      else if (command.find(">>") != std::string::npos)
      {

          char *argv1[64];
          char *argv2[64];
          int pid;
          int s1;
          string delimiter = ">>";
          string token1 = command.substr(0, command.find(delimiter));
          token1+=" NULL";
          string token2 = command.substr(command.find(delimiter)+2,command.length());
          token2.erase(
          remove( token2.begin(), token2.end(), '\"' ),
          token2.end()
          );
          char *t1 = new char[token1.length()+1];
          strcpy(t1,token1.c_str());
          parse(t1,argv1);
          char *t2 = new char[token2.length()+1];
          strcpy(t2,token2.c_str());
          parse(t2,argv2);
          if(t2[0]==' ')
            ofile=++t2;
          else
           ofile=t2;
          pid=fork();
          if (pid == 0)
          {
              if(ofile!=NULL)
            {
                  int fd2=open(ofile, O_WRONLY| O_APPEND | O_CREAT, 0644);
                  dup2(fd2, STDOUT_FILENO);
                  close(fd2);
            }
          execvp(*argv1,argv1);
          }

          else {                                 
              while (wait(&s1) != pid)     
              ;
              }   
          continue; 
      } 

	if (command.find("<") != std::string::npos)
      {
         char *argv1[64];
          char *argv2[64];
          int pid;
          int s1;
          string delimiter = "<";
          string token1 = command.substr(0, command.find(delimiter));
          token1+=" NULL";
          string token2 = command.substr(command.find(delimiter)+1,command.length());

          char *t1 = new char[token1.length()+1];
          strcpy(t1,token1.c_str());
          parse(t1,argv1);
          char *t2 = new char[token2.length()+1];
          strcpy(t2,token2.c_str());
          parse(t2,argv2);
          if(t2[0]==' ')
          {
            ifile=++t2;
          }
          else 
          ifile=t2;
         // cout<<ofile;
          pid=fork();
          if (pid == 0)
          {
              if(ofile!=NULL)
            {
                  int fd1=open(ifile, O_RDONLY);
                  dup2(fd1, STDIN_FILENO);
                  close(fd1);
            }
          execvp(*argv1,argv1);
          }

          else {                                 
              while (wait(&s1) != pid)     
              ;
              }

          continue;
      } 


          command.erase(
          remove( command.begin(), command.end(), '\"' ),
          command.end()
          );

          command.erase(
          remove( command.begin(), command.end(), '\'' ),
          command.end()
          );

        if (command.find("alias") != std::string::npos)
        {
          char *ar1[64];
          char *ar2[64];
          string d = "=";
          string a1 = command.substr(0, command.find(d));
          a1+=" NULL";
          string a2 = command.substr(command.find(d)+1,command.length());
          a1.erase(0,6);
          if(ali.find(a1)!=ali.end())
          ali[a1]=a2;
            else
          ali.insert({a1,a2});
          continue;
        }

        char *cmd = new char[command.length()+1];
        strcpy(cmd,command.c_str());
        parse(cmd,argv);
     
        //for(int i=0;i<x;i++)
        //  cout<<argv[i]<<endl;
        if(xxx>0)
        {
          pipe1(argv,xxx);
          continue;
        }
        if(strcmp(argv[0],"HOME")==0)
        { 
          //cout<<"dsgvsd";
          home1(argv[2]);
          continue;
        }
        if(strcmp(argv[0],"USER")==0)
        {
          //cout<<"dfghdf";
          user11(argv[2]);
          continue;
        } 
        if(strcmp(argv[0],"HOSTNAME")==0)
        {
          HOSTNAME1(argv[2]);
          continue;
        }
        if(strcmp(argv[0],"PATH")==0)
        {
          PATH1(argv[2]);
          continue;
        }
        

        if(strcmp(argv[0],"History")==0)
        {
          string line;
          ifstream in;
          in.open("history.txt"); 
          while (in) { 
          getline(in, line); 
          cout << line<< endl;} 
          in.close(); 
          continue;
        }
      if(strcmp(argv[0], "PS1")==0)
      {       prompt=argv[1];
        continue;}
      if(strcmp(argv[0], "cd") == 0)
      { 
        if(x == 1)
        {
        char *home = getenv("HOME");
        if(chdir(home) != 0)
        {perror("chdir error");}
        }
        else
        {
          if(strcmp(argv[1],"~")==0)
          {
            char *home = getenv("HOME");
            if(chdir(home) != 0)
            {perror("chdir error");}

          }
          else if(strcmp(argv[1],"-")==0)
          {
          if(chdir("..") != 0)
            {perror("chdir error");}
              gpwd();
            cout<<endl;
          }
          else if(chdir(argv[1]) != 0)
          {perror("chdir error");}
        }
        continue; 
      }

 
     if(strcmp(argv[0],"echo")==0)
    {

      if(strcmp(argv[1],"$PATH")==0)
      {     path();
            continue;}

      if(strcmp(argv[1],"$HOME")==0)
      {     h1:
            home();
            continue;}
     if(strcmp(argv[1],"$HOSTNAME")==0)
     {     
            hostname();
            continue;}
     if(strcmp(argv[1],"$USER")==0)
     {    user1();
            continue;}
       if(strcmp(argv[1],"$$")==0)
     {    cout<<getpid()<<endl;
            continue;}
      /// echo1()      
    }
    
    //if()

    if(strcmp(argv[0], "exit") == 0)
      break;
  
       cout<<x;
		//execute(argv); 

	}
	return 0;
}