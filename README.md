# Custom Bash Builtin
The main reason for making a bash builtin would be simply for perfomance. This effectively allows you to have C bindings in bash, so for example, you could create a JSON parser/sorting algorithm in C, compile it as a bash builtin, and write scripts around it, which would allow you to do things that usually you'd use jq for, but much more efficiently.

# Install
```
$ printf 'nameserver 1.1.1.1' > /tmp/ldns.conf
$ wget https://raw.githubusercontent.com/644/ldnsbash/main/ldnsbash.c
$ gcc -I/usr/include/bash/builtins -I/usr/include/bash/include -I/usr/include/bash -I/usr/lib/bash -shared -fPIC -lldns -O3 -Wpedantic -o ldnsbash.so ldnsbash.c
$ enable -f ./ldnsbash.so ldnsbash
$ ldnsbash; echo "$LDNSBASH"
```

It's important to have bash >4.0+ installed, along with bash-builtins.
