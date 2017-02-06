all: test staticlib

rebuild: clean all

test: test.cpp libreplicate.a

clean:
	$(RM) *.o test libreplicate.a
	
staticlib: libreplicate.a

libreplicate.a: replicate.o
	$(AR) $(ARFLAGS)s $@ $^
	
replicate.o: replicate.cpp replicate.h

