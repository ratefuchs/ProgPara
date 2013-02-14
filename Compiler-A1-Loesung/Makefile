all: lexer.l parser.c
	flex -o lexer.c lexer.l
	$(CC) *.c -lfl -o parser
