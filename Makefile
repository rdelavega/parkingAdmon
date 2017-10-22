OBJS = main.o HELP.o dbOp.o strOp.o auth.o

CFLAGS = -lnsl -lm -lz -lmysqlclient

parkingAdmon:	$(OBJS)
	gcc -o parkingAdmon $(OBJS) $(CFLAGS)

main.o:	main.c headers.h
	gcc -c main.c

HELP.o:	HELP.c headers.h
	gcc -c HELP.c

dbOp.o:	dbOp.c headers.h
	gcc -c dbOp.c

strOp.o:	strOp.c headers.h
	gcc -c strOp.c

auth.o:	auth.c headers.h
	gcc -c auth.c

clean:
	rm -f $(OBJS) parkingAdmon
