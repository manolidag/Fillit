gcc -c error.c read_file.c side_check.c check_validity.c struct.c
gcc -g -fsanitize=address main.c error.o read_file.o side_check.c check_validity.c struct.c -L. libft.a
