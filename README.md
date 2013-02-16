#c/c++ plugin example code

In this section, I will show an example of plugin in c/c++
## myplugin 

show dlopen in call
	
	gcc -shared -fPIC myplugin.c -o myplugin.so	
	
	gcc -o main main.c  -ldl

## myplugin2

show dlopen in c++ call

	g++ -shared -fPIC myplugin.c -o myplugin.so	
	
	g++ -o main main.cc  -ldl
# reference
http://www.isotton.com/devel/docs/C++-dlopen-mini-HOWTO/C++-dlopen-mini-HOWTO.html

