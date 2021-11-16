# server.py
from multiplication_handler import MultiplicationHandler
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer
from MultiplicationService import *


if __name__ == '__main__':
    handler = MultiplicationHandler()
    processor = Processor(handler)
    transport = TSocket.TServerSocket(host='127.0.0.1', port=1234)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TThreadPoolServer(processor, transport, tfactory, pfactory)
    print("Server has started\nListening...")
    server.serve()
