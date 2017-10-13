CFLAGS = /W4 user32.lib

all: MessageBox.exe

clean:
	del MessageBox.obj
	del MessageBox.exe
