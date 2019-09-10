/*

Por John Sanabria - john.sanabria@correounivalle.edu.co

 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "dummynet.h"

int main(int argc, char* argv[])
{
  int client;
  int portfd;
  char PORT[6];
  char host[1024];

  if (argc == 3) {
    strcpy(host, argv[1]);
    strcpy(PORT, argv[2]);
  } else {
    strcpy(host, "127.0.0.1");
    strcpy(PORT,"10000");
  }

  portfd = startClient(host,atoi(PORT));

  if (portfd == -1) {
   printf("Error conectandose a server\n");
   exit(-1);
  }

  char *mesg = "hola mundo";
  int lenst = strlen(mesg);
  int len = echoClient(portfd,mesg);
  if (len == -1 || lenst != len) {
   printf("Error en echoClient (%d)\n",len);
   exit(-1);
  }
  printf("[CLIENT] %s\n",mesg);

  return 0;
}

