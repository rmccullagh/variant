objects = main.o var.o
CCFLAGS = -Wall -Wextra -Wpedantic -Wpadded

main : $(objects)
		cc $(CCFLAGS) -o main $(objects)

.PHONY : clean
clean:
	rm -f main $(objects)
