#include "gen-cpp/MultiplicationService.h"
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <memory>
#include <iostream>
#include "Handler.cpp"
#include <iostream>

using namespace ::apache::thrift::server;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using std::make_shared;
using std::shared_ptr;

int main()
{
    auto handler = make_shared<MultiplicationServiceHandler>();
    auto proc = make_shared<MultiplicationServiceProcessor>(handler);
    auto trans_svr = make_shared<TServerSocket>(1234);
    auto trans_fac = make_shared<TBufferedTransportFactory>();
    auto proto_fac = make_shared<TBinaryProtocolFactory>();

    cout << "Server start to listening!" << endl;
    TSimpleServer server(proc, trans_svr, trans_fac, proto_fac);
    
    server.serve();
    return 0;
}