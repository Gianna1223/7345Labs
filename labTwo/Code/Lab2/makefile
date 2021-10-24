compile:
	clang++ -g -std=c++14 ./*.cpp -o output
	./output
emcc:
	emcc -std=c++11 -pthread -s PROXY_TO_PTHREAD -s ALLOW_MEMORY GROWTH=1 NO_DISABLE_EXC -s
	node example.js