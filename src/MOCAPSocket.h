#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <iostream>
#include <math.h>
#include <arpa/inet.h>
using namespace std;
#define MULTICAST_ADDRESS	"239.255.42.99"
//#define MY_ADDRESS		"129.25.20.204"
//#define MY_ADDRESS			"192.168.0.187"
#define MY_ADDRESS			"192.168.1.164"
#define PORT_COMMAND		1510
#define PORT_DATA			1511
#define SOCKET_ERROR		(-1)
#define MAXRECV  			3000
#define MAX_RIGID_BODY     32
#define PI                 3.14

struct RigidBodyObject{
        int ID;
        float x, y, z, qx, qy, qz, qw, yaw, pitch, roll, x_old, y_old, z_old;
};

class MOCAPSocket {
public:
        MOCAPSocket();
        virtual ~MOCAPSocket();
        int Read();
        RigidBodyObject rigidBody [MAX_RIGID_BODY];
private:
        int Receive();
        void ParseData(char* pData);
        int DataSocket;
        struct sockaddr_in SocketAddrIn;
        struct ip_mreq Mreq;
        char buffer [ MAXRECV + 1 ];
        int frameNmbr;
        void Q2Euler(RigidBodyObject* RB);
        float Rad2Deg(float angle);
        int NmbrOfRBs;
};


