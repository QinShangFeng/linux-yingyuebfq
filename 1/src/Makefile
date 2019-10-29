SRC := $(wildcard *.c) # a.c b.c main.c
SRC := $(filter-out main.c, $(SRC)) # a.c b.c

OBJ = $(SRC:%.c=%.o) # a.o b.o

CROSS = arm-none-linux-gnueabi-
CC = $(CROSS)gcc

# 预处理器选项
CPPFLAGS += -I ../include



libx.so:$(OBJ)
	$(CC) -shared -fPIC -o libx.so $^
	mv $@ ../lib

$(OBJ):%.o:%.c
	$(CC) $^ -o $@ -c -fPIC $(CPPFLAGS) $(LDFLAGS)
	

LDFLAGS += -L ../lib
LDFLAGS += -lx
LDFLAGS += -lpthread



main:main.c
	$(CC) $< -o $@ $(CPPFLAGS) $(LDFLAGS)
	mv $@ ../main

sco:
	rm *.o


# 伪目标
clean:
	$(RM) $(OBJ)

distclean:clean
	$(RM) ../lib/libx.so


.PHONY:clean distclean
