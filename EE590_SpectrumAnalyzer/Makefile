
# Target / Project Name
TARGET = SpectrumAnalyzer

CFLAGS = -Wall

INCLUDES = -I/opt/vc/include -I/opt/vc/include/interface/vmcs_host/linux -I/opt/vc/include/interface/vcos/pthreads

LIBPATH =

LIBS = -lbcm2835 -lrt -lfftw3 -lm -lshapes -lrt 

SRCS = main.c Display.c SPI.c FFT.c

OBJS = $(SRCS:.c=.o)

all: $(TARGET)
	@echo Makefile compiliation complete!

$(TARGET): $(OBJS)
	gcc $(CFLAGS) $(INCLUDES) -o $(TARGET) $(OBJS) $(LIBPATH) $(LIBS)

#This is a suffix replacement rule for building .o's from .c's
# It uses automatic variables '$<' for the name of the prerequisite of the rule (the .c file)
# and '$@' for the name of the target of the rule (the .o file). '
.c.o:
	gcc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *- $(TARGET)