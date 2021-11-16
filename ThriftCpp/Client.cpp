#include "gen-cpp/MultiplicationService.h"
#include <thrift/transport/TSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <memory>
#include <string>
#include <iostream>
#include <ctime>
#include <thread>

using namespace apache::thrift::transport;
using namespace apache::thrift::protocol;
using std::make_shared;
using std::shared_ptr;
using namespace std;

class MultiplyClientThread
{
public:
    void operator()(MultiplicationServiceClient client)
    {
        // int32_t a = 20;
        int32_t b = 10;
        try
        {
            for (int i = 0; i < 15; i++)
            {
                client.multiply(i, b);
            }
        }
        catch (invalid_argument &io)
        {
            printf("InvalidOperation: %s", io.what());
        }
    }
};

int main()
{
    shared_ptr<TTransport> trans;
    trans = make_shared<TSocket>("localhost", 1234);
    trans = make_shared<TBufferedTransport>(trans);
    auto proto = make_shared<TBinaryProtocol>(trans);
    MultiplicationServiceClient client(proto);

    try
    {
        trans->open();

        // int32_t a = 100;
        // int32_t b = 2;

        // int32_t res = client.multiply(a, b);
        // std::cout << std::to_string(res);
        for (int i = 0; i < 10; i++)
        {
            thread clientThread(MultiplyClientThread(), client);
            clientThread.join();
        }
    }
    catch (invalid_argument &io)
    {
        printf("InvalidOperation: %s", io.what());
    }
    trans->close();
}
