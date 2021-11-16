# server.py
from multiplication_handler import MultiplicationHandler
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol, TCompactProtocol
from thrift.server import TServer
from thrift.server.TNonblockingServer import TNonblockingServer
from MultiplicationService import *


if __name__ == '__main__':
    handler = MultiplicationHandler()
    processor = Processor(handler)
    transport = TSocket.TNonblockingServerSocket(host='127.0.0.1', port=1234)
    # protocol_fact = TCompactProtocol.TCompactProtocolFactory()

    # tfactory = TTransport.TBufferedTransportFactory()
    tfactory = TTransport.TFramedTransport(transport)
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()
    outfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TNonblockingServer(processor, transport)
    # server = TNonblockingServer(processor, transport, tfactory, pfactory)
    
    print("Server has started\nListening...")
    transport.open()
    server.serve()
