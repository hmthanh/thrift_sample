# build gen
thrift --gen cpp multiply.thrift


# build server
g++ -o server Server.cpp Handler.cpp gen-cpp/MultiplicationService.cpp -Wall -std=c++11 -lthrift -pthread

# build client
g++ -o client Client.cpp gen-cpp/MultiplicationService.cpp -Wall -std=c++11 -lthrift -pthread
