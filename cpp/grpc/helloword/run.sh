protoc --grpc_out=. --cpp_out=. --plugin=protoc-gen-grpc=/usr/local/bin/grpc_cpp_plugin helloworld.proto
clang++-14 helloworld.grpc.pb.cc helloworld.pb.cc server.cpp -o server -lgrpc++ -lprotobuf -lgrpc++_reflection
clang++-14 helloworld.grpc.pb.cc client.cpp -o client
