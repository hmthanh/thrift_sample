# client.py
from thrift import Thrift
from thrift.transport import TSocket
from thrift.protocol import TBinaryProtocol
from thrift.transport import TTransport
from MultiplicationService import *
import random

if __name__ == '__main__':
    trans = TSocket.TSocket('localhost', 1234)
    trans = TTransport.TBufferedTransport(trans)
    proto = TBinaryProtocol.TBinaryProtocol(trans)
    client = Client(proto)

    trans.open()
    for i in range(50000):
        n1 = random.randint(1, 2000)
        n2 = random.randint(1, 2000)
        print("Send multiplycation request to server... ")
        result = client.multiply(n1, n2)
        print("Server has response. Result is {}".format(result))
    trans.close()
