# Custom Bash Builtin
The main reason for making a bash builtin would be simply for perfomance. This effectively allows you to have C bindings in bash, so for example, you could create a JSON parser/sorting algorithm in C, compile it as a bash builtin, and write scripts around it, which would allow you to do things that usually you'd use jq for, but much more efficiently.

# Install Guide
### Oneliner
```bash
git clone https://github.com/644/ldnsbash; cd ldnsbash; make; enable -f ./ldnsbash.so ldnsbash; ldnsbash; echo "$LDNSBASH"
```
---
### Breakdown
#### Download this repo and cd to it
```bash
git clone https://github.com/644/ldnsbash
cd ldnsbash
```
#### Build it
```bash
make
```
#### Load the builtin into bash
```bash
enable -f ./ldnsbash.so ldnsbash
```
#### And run it
```bash
ldnsbash
echo "$LDNSBASH"
```
#### To unload the builtin
```bash
enable -d ldnsbash
```

It's important to have bash >4.0+ installed, along with bash-builtins.

# License
MIT
