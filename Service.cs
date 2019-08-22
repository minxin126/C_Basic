#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define MAXSIZE 1024
#define LOGIN 1    //登录Server
#define BYE 2    //离开Server
#define PASS 3    //合法登录
#define DENY 4 //非法登录
#define SHUTDOWN 5 //执行关机
#define ERROR -1 //非法信息
//记录状态信息
static int STATE=0;
int getClientChoice(char * clientmsg)
{
    if(strcmp(clientmsg,"login\n")==0) return LOGIN;
    if(STATE>0)
    {
        if(strcmp(clientmsg,"bye\n")==0) return BYE;
    }
    if(STATE==LOGIN)
    {
        //Default password is 123456
        if(strcmp(clientmsg,"123456\n")==0) return PASS;
        else return DENY;
    }
    if(STATE==PASS)
    {
        if(strcmp(clientmsg,"shutdown\n")==0) return SHUTDOWN;
        else ERROR;    
    }
    return ERROR;
};
//发送消息
void sendMsg(int sockfd,char * buffer,char * msg)
{
    char buffer2[MAXSIZE];
    snprintf(buffer2,sizeof(buffer2),"%s",msg);
    write(sockfd,buffer2,sizeof(buffer2));
}
//定义关机函数
void myshutdown()
{
    //系统在一分钟后关机
    system("shutdown -t 1");
}
int main(int argc , char * * argv )
{
    char buffer[MAXSIZE];
    int listenfd=socket(AF_INET,SOCK_STREAM,0);//定义socket，指向ipv4地址的字节流套接口
    
    struct sockaddr_in serverAddr;
    memset(&serverAddr,0,sizeof(serverAddr));//sockAddr_in 进行初始化
    serverAddr.sin_family=AF_INET;
    serverAddr.sin_addr.s_addr=htonl(INADDR_ANY);
    serverAddr.sin_port=htons(2000);
    if(bind(listenfd,(struct sockaddr *) &serverAddr,sizeof(serverAddr))==-1)
    {
        printf("There is an error during binding\n");
        return -1;
    }
    else
    {
        printf("Bind successfully!!!\n");
    }
    //对listenfd进行监听，从最初建立时的主动套接口（用于进行connect的套接口）转化为被动套接口（接受连接）
    listen(listenfd,100);//第二个参数为套接口排队的最大连接个数
    int connectfd;
    socklen_t addrlen;
    struct sockaddr_in connectAddr;
    memset(&connectAddr,0,sizeof(connectAddr));
    printf("Be ready to accept a connection!\n");
    while(1)
    {
        connectfd=accept(listenfd,(struct sockAddr * )&connectAddr,&addrlen);//接受client端一个请求的socket
        char receivebuffer[MAXSIZE];
        int revbuflen;
        while(1)
        {
            revbuflen = read(connectfd,receivebuffer,MAXSIZE);
            receivebuffer[revbuflen]='\0';
            //printf("%s",receivebuffer);
            int clientChoice=getClientChoice(receivebuffer);
        //    模拟操作过程
            if(clientChoice==LOGIN)
            {
                STATE=LOGIN;
                sendMsg(connectfd,buffer,"Please input your password :\n");
            }
            else if(clientChoice==PASS&&STATE==LOGIN)
            {
                STATE=PASS;
                sendMsg(connectfd,buffer,"Welcome to my Telnet Server...\n");
            }
            else if(clientChoice==SHUTDOWN&&STATE==PASS)
            {
                myshutdown();
                sendMsg(connectfd,buffer,"Remote computer is going to shutdown...\n");
            }
            else if (clientChoice==BYE)
            {
                sendMsg(connectfd,buffer,"bye\n");
                break;
            }
            else if(clientChoice==DENY)
            {
                sendMsg(connectfd,buffer,"Fail to login ,please check your password\n");
            }
            else if(clientChoice==ERROR)
            {
                sendMsg(connectfd,buffer,"wrong,Check your input...\n");
            }
        }
        close(connectfd);
    }
    close(listenfd); //虽然因为上面有while（true），这行永远都执行不了，但是时刻注意关闭socket连接应该是个好习惯。 
    return 0;
}