/*

Por John Sanabria - john.sanabria@correounivalle.edu.co

 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "dummynet.h"

#define MAXMSG 1024

int main(int argc, char* argv[])
{
  int client;
  int portfd;
  char PORT[6];

  if (argc == 2) {
    strcpy(PORT, argv[1]);
  } else {
    strcpy(PORT,"10000");
  }

  printf("Server started at port no. [%s] with root directory as [%s]\n",PORT,ROOT);
  portfd = startServer(PORT);

  client = listenfd(portfd); // ACCEPT connections
  if (client<0) // error en la solicitud
    perror("accept() error");
  else {
    int msgsize = MAXMSG;
    char mesg[MAXMSG];
    echoServer(client,mesg,&msgsize);
    printf("[SERVER] %s\n",mesg);
  }

  return 0;
}

