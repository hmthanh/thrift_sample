thrift -r --gen cpp multiply.thrift



python3 ./TSimpleServer/server.py

python3 ./TSimpleServer/client.py
python3 ./TSimpleServer/client2.py



python3 ./TThreadedServer/server.py

python3 ./TThreadedServer/client2.py
python3 ./TThreadedServer/client.py


python3 ./TThreadPoolServer/server.py

python3 ./TThreadPoolServer/client2.py
python3 ./TThreadPoolServer/client.py



python3 ./TNonblockingServer/server.py

python3 ./TNonblockingServer/client2.py
python3 ./TNonblockingServer/client.py




