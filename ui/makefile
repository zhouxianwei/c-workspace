CFLAGS = `pkg-config --cflags --libs gtk+-3.0` -mwindows
main:
	glib-compile-resources gtk.gresource.xml
	gcc main.c -o ui ${CFLAGS}
	./ui.exe