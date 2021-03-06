#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H
#include "../src/raknet/lib/udpsocket.h"
#include "ExtraFuncs.h"
#include "../src/raknet/protocol/Packet.hpp"
#include <map>
#include "../src/raknet/Session.h"
#include "../src/raknet/protocol/UNCONNECTED_PING.hpp"
#include "../src/raknet/protocol/UNCONNECTED_PONG.hpp"
#include "../src/raknet/protocol/OPEN_CONNECTION_REQUEST_1.hpp"
#include "../src/raknet/protocol/OPEN_CONNECTION_REQUEST_2.hpp"
#include "../src/raknet/protocol/DataPacket.hpp"
class Server;
class Session;
class SessionManager
{
public:
    Packet* getPacketFromPool(unsigned char pid);
    void sendPacket(Packet* packet,std::string dest,int port);
    SessionManager(udpsocket* _socket,Server *ser);
    int tickProcessor(void);
    bool receivePacket();
    virtual ~SessionManager();
    udpsocket* socket;
    int64_t serverId;
    bool shutdown=false;
    int64_t getID();
    Session* getSession(std::string source,unsigned int port);
    double lastMeasure;
    unsigned int getPort();
    void tick();
    void removeSession(Session* session,std::string reason);
    void processPackets();
protected:

private:
};

#endif // SESSIONMANAGER_H
