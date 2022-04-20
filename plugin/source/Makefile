NAME = EP_MK1

FILES_DSP = $(wildcard *.cpp)
FILES_DSP += $(wildcard *.c)

include ../../dpf/Makefile.plugins.mk

LINK_FLAGS += -lpthread
CFLAGS += -Wno-unused-parameter
CXXFLAGS += -Wno-unused-parameter


	
TARGETS += jack
	
TARGETS += lv2_dsp
	
TARGETS += vst2
	
TARGETS += vst3
	


all: $(TARGETS)