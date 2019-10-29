vpath %.c  = src/
vpath %.so = lib/

ganjing:main ooo

main:main.c install 
	# 调用子Makefile，生成执行文件
	$(MAKE) -C src/ main

install:
	# 调用子Makefile,生成库
	$(MAKE) -C src/ libx.so

ooo:
	#删除生成的.o临时文件
	$(MAKE) -C src/ sco
clean:
	$(RM) main
	$(MAKE) -C src/ clean

distclean:
	$(MAKE) -C src/ distclean


.PHONY: install clean distclean ganjing ooo
