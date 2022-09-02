// client file

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int a, char const *S[])
{
    char Data[255];
    int socket_id = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int Status = connect(socket_id, (struct sockaddr *)&server_address, sizeof(server_address));

    if (Status == -1)
    {
        printf("Error\n");
    }
    else
    {
        recv(socket_id, Data, sizeof(Data), 0);
        printf("Message is: %s\n", Data);
    }
    close(socket_id);
    return 0;
}