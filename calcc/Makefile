cc = gcc
flags = -Wall -Wextra -g3
target = _calc.out

src_dir = src
obj_dir = obj
src = $(wildcard $(src_dir)/*.c)
obj = $(addprefix $(obj_dir)/,$(notdir $(src:.c=.o)))
main = $(src_dir)/main.c
main_obj = $(obj_dir)/main.o


all : dir
all : main
all : target

main :
	$(cc) $(flags) -c $(main) -o $(main_obj)

$(obj_dir)/%.o : $(src_dir)/%.c
	$(cc) $(flags) -c $^ -o $@

target : $(obj)
	$(cc) $(flags) $(obj) -o $(target) -lm

del :
	rm -f $(obj)

re : del all

dir :
	mkdir -p $(obj_dir)

test : dir
test : flags += -DTEST
test : main
test : all

