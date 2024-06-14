cc = gcc
flags = -Wall -Wextra -g3
target = _calc.out

src_dir = src
obj_dir = obj
src = $(wildcard $(src_dir)/*.c)
obj = $(addprefix $(obj_dir)/,$(notdir $(src:.c=.o)))

all : target

$(obj_dir)/%.o : $(src_dir)/%.c
	$(cc) $(flags) -c $^ -o $@

target : $(obj)
	$(cc) $(flags) $(obj) -o $(target) -lm

del :
	rm -f $(obj)

re : del all

