// server file

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int a, char const *S[])
{
    char Message[255] = "Message from the server to the "
                        "client \'Hello Client\' ";
    int server_sock_id = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    bind(server_sock_id, (struct sockaddr *)&server_address, sizeof(server_address));
    listen(server_sock_id, 1);
    int Client_Sock = accept(server_sock_id, NULL, NULL);
    send(Client_Sock, Message, sizeof(Message), 0);
    close(server_sock_id);
    return 0;
}