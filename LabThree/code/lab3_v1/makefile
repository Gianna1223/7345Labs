compile:
	clang++ -g -std=c++14 ./*.cpp -o output
	./output
emcc:
	emcc -std=c++11 -pthread -s PROXY_TO_PTHREAD -s ALLOW_MEMORY_GROWTH=1 -s NO_DISABLE_EXCEPTION_CATCHING
	node example.js