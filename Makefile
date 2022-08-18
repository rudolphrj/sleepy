PREFIX = /usr/local

sleepy: sleepy.c
	gcc -o sleepy sleepy.c

clean: rm -f sleepy

install: sleepy
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp -f sleepy $(DESTDIR)$(PREFIX)/bin
	chmod 755 $(DESTDIR)$(PREFIX)/bin/sleepy

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/sleepy

.PHONY: clean install uninstall
