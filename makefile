a.exe:splay_app.o splay_imp.o
	c++ splay_app.o splay_imp.o -o a.exe
splay_app.o:splay_app.cpp
	c++ -c splay_app.cpp
splay_imp.o:splay_imp.cpp
	c++ -c splay_imp.cpp