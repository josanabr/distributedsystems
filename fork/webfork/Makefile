all: lib bin

lib: obj
	ar rc libdummynet.a dummynet.o

obj:
	gcc -c dummynet.c 

http: lib
	gcc -L . main.c -o server -ldummynet

echo: lib 
	gcc -L . echoServer.c -o echoServer -ldummynet
	gcc -L . echoClient.c -o echoClient -ldummynet

clean:
	rm -rf dummynet.o libdummynet.a server echoServer echoClient

  
