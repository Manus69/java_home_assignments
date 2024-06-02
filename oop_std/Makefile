cc = javac
controller_dir = controller/
data_dir = data/
service_dir = service/
view_dir = view/
prog = Program.java

src = $(wildcard $(controller_dir)*java) $(wildcard $(data_dir)*.java) $(wildcard $(service_dir)*.java) $(wildcard $(view_dir).java)
# src += $(prog)

obj = $(src:.java=.class)

%.class : %.java
	$(cc) $^

test: $(obj)
