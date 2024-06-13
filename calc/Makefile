cc = javac
src = $(shell find . -name "*.java")
obj = $(src:.java=.class)

%.class : %.java
	$(cc) $^

all: $(obj)

del:
	rm -f $(obj)

re: del all

test:
	echo $(src)
	echo $(obj)