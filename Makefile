INCLUDE := /usr/include/bash/builtins /usr/include/bash/include /usr/include/bash /usr/lib/bash

ldnsbash.so: ldnsbash.c
	$(file >/tmp/ldns.conf,nameserver 1.1.1.1)
	gcc $(foreach dir,$(INCLUDE),-I $(dir)) -shared -fPIC -lldns -O3 -Wpedantic -o $@ $<
