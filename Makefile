OBJS = main.o HELP.o dbOp.o strOp.o auth.o menu.o addDB.o queryDB.o

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

menu.o:	menu.c headers.h
	gcc -c menu.c

addDB.o:	addDB.c headers.h
	gcc -c addDB.c

queryDB.o:	queryDB.c headers.h
	gcc -c queryDB.c

clean:
	rm -f $(OBJS) parkingAdmon
