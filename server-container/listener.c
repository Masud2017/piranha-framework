/* Author : Md.Masud karim
 * Email: msmasud578@gmail.com
 * This script is a server listener. Which listen to the server.
 * */


void start_listen() {
	// This function is responsible to listen to a client Note: I might make this server concurrent in later
	// version but right it's just a single threaded server who can handle one clinet at a time 
	char* buffer = (char*)malloc(sizeof(char)*1024);

	if (getSocket() == TCP_SUCCESS) {
		printf("Socket create success fully\n");
	}

	char *hello =
		"HTTP/1.1 200 OK\n"
		"Date: Thu, 19 Feb 2009 12:27:04 GMT\n"
		"Server: Piranha-Embedded-Server/2.2.3\n"
		"Last-Modified: Wed, 18 Jun 2003 16:05:58 GMT\n"
		"ETag: \"56d-9989200-1132c580\"\n"
		"Content-Type: text/html\n"
		"Content-Length: 440\n"
		"Accept-Ranges: bytes\n"
		"Connection: keep-alive\n"
		"\n"
		"<html><head><link rel = \"icon\" type = \'image\' href = \'https://external-content.duckduckgo.com/iu/?u=https%3A%2F%2Fmedia.istockphoto.com%2Fvectors%2Ffurious-piranha-sport-vector-icon-concept-isolated-on-white-vector-id670567906%3Fk%3D6%26m%3D670567906%26s%3D612x612%26w%3D0%26h%3D9nIGEVR6qtmvAMn75wTbpXNlJdWJYG31vsZ_xLZjdyw%3D&f=1&nofb=1\'><title>Piranha server</title></head><body><h1>Hello world this is my testing server</h1></body></html>";

	connect_tcp(port);
	while(1) {
		accept_tcp();
		read_tcp (buffer);
		if (http_get(buffer) == HTTP_GET) {
			printf("\nConnection response is get request\n");
		
		} else {
		
			printf("\nConnect response is post request\n");
		
		}
		send_tcp(hello);
	}	

}

void stop_listen(void) {
	// this function reponsible of terminating the server but it's not going to be in use often time.
}
