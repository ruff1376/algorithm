#define _CRT_SECURE_NO_WARNINGS
#include "winsock2.h"
#include "ws2tcpip.h"
#include "stdio.h"

#define SERVER_PORT 16382  // server port number
#define BUF_SIZE 4096 // block transfer size  
#define QUEUE_SIZE 10
#define IPAddress "165.246.38.151" // server IP address

int main()
{
	WORD wVersionRequested;
	WSADATA	wsaData;
	SOCKADDR_IN target; //Socket address information
	SOCKET s;
	int	err;
	int	bytesSent;
	char buf[100];

	//--- INITIALIZATION -----------------------------------
	wVersionRequested = MAKEWORD(1, 1);
	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0) {
		printf("WSAStartup error %ld", WSAGetLastError());
		WSACleanup();
		return false;
	}
	//------------------------------------------------------

	//---- Build address structure to bind to socket.--------  
	target.sin_family = AF_INET; // address family Internet
	target.sin_port = htons(SERVER_PORT); //Port to connect on
	inet_pton(AF_INET, IPAddress, &(target.sin_addr.s_addr)); // target IP
		//--------------------------------------------------------


	// ---- create SOCKET--------------------------------------
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
	if (s == INVALID_SOCKET)
	{
		printf("socket error %ld", WSAGetLastError());
		WSACleanup();
		return false; //Couldn't create the socket
	}
	//---------------------------------------------------------


	//---- try CONNECT -----------------------------------------
	if (connect(s, (SOCKADDR *)&target, sizeof(target)) == SOCKET_ERROR)
	{
		printf("connect error %ld", WSAGetLastError());
		WSACleanup();
		return false; //Couldn't connect
	}
	//-------------------------------------------------------

	//---- SEND bytes -------------------------------------------
	printf("enter a string to send to server\n");
	gets_s(buf, 99);
	bytesSent = send(s, buf, strlen(buf), 0); // use "send" in windows
	printf("Bytes Sent: %ld \n", bytesSent);

	// now receive
	int n;
	if (strcmp(buf, "hello") == 0) {
		n = recv(s, buf, 50, 0); // read max 50 bytes
		buf[n] = 0; // make a string
		printf("received: %s\n", buf);
		gets_s(buf, 99);
		send(s, buf, strlen(buf), 0);
		char temp[50];
		strcpy(temp, buf);
		FILE *f;
		f = fopen(buf, "w");
		for (;;) {
			n = recv(s, buf, 50, 0);
			if (n == 0) break;
			buf[n] = 0;
			fwrite(buf, 1, n, f);
		}
		printf("%s downloaded successfully.\n", temp);
	}

	//--------------------------------------------------------
	closesocket(s);
	WSACleanup();

	return 0;
}