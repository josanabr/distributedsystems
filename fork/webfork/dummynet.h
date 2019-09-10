#ifndef __DUMMYNET__
#define __DUMMYNET__

#define BYTES 1024
#define ROOT getenv("PWD") 

int startServer(char *);
int startClient(char *,int);
void respondHTTP(int);
int listenfd(int);
int echoServer(int, char*, int*);
int echoClient(int, char*);

#endif
