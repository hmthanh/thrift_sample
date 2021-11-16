#include "gen-cpp/MultiplicationService.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <memory>
#include <iostream>
#include <chrono>


using namespace ::apache::thrift::server;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using std::make_shared;
using std::shared_ptr;

using namespace std;

class MultiplicationServiceHandler : public MultiplicationServiceIf
{
public:
    virtual int32_t multiply(const int32_t n1, const int32_t n2) override
    {
        cout << "Multiply " << n1 << " * " << n2 << endl;
        this_thread::sleep_for(std::chrono::milliseconds(1000));
        return n1 * n2;
    }
};