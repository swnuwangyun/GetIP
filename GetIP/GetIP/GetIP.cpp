// GetIP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


//c++获取本机IP  
#include <stdio.h>  
#include <stdlib.h>  
#include <WINSOCK2.H>  
#pragma comment(lib,"ws2_32.lib")  
  
int getIP(int ,char**)  
{  
  
    char host_name[255];  
    if(gethostname(host_name,sizeof(host_name))==SOCKET_ERROR)  
    {  
  
        printf("Error %d when getting local host name\n",WSAGetLastError());  
        return -1;  
    }  
    printf("host name:%s\n",host_name);  
    struct hostent *phe=gethostbyname(host_name);  
    if(phe==0)  
    {  
  
        printf("Error host lookup\n");  
        return -1;  
  
    }  
  
    for(int i=0;phe->h_addr_list[i]!=0;++i)  
    {  
        struct in_addr addr;  
        memcpy(&addr,phe->h_addr_list[i],sizeof(struct in_addr));  
        printf("Address %d :%s\n",i,inet_ntoa(addr));  
  
  
    }  
    return 0;  
}  

int main(int argc,char *argv[])  
{  
    WSAData wsaData;  
    if(WSAStartup(MAKEWORD(1,1),&wsaData)!=0)  
    {  
  
        system("pause");  
        return -1;  
    }  
    int result=getIP(argc,argv);  
    WSACleanup();  
    system("pause");  
    return result;  
}  