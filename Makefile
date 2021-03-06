CC=gcc
CFLAGS=-O3 -Wall -Wextra -march=native --std=gnu11
LDLIBS=-lz
CXX=g++
CXXFLAGS=-O3 -Wall -Wextra -march=native --std=gnu++11
# Ignore compilation fails for java
IGNOREJAVA=true

# Targets to make
TGT =

# Extra files to delete
REM =

# Add one for your problem here, do not add targets here
TGT += $(addprefix artifi/solutions/,    martinvl martinvl.class hawken)
TGT += $(addprefix birthdays/solutions/, joakimjl olalia) # MISSING java8
TGT += $(addprefix bitmean/solutions/,   martinvl.class martinvl_wrong.class martinvl_slow.class)
TGT += $(addprefix festival/solutions/,  hawken hawken_wrong kjetimh kjetimh_wrong martinvl.class martinvl_buffered.class)
TGT += $(addprefix fibez/solutions/,)
TGT += $(addprefix football/solutions/,  joakimjl.class olalia)
TGT += $(addprefix healthy/solutions/,   martinvl.class martinvl_slow.class)
REM += $(addprefix healthy/solutions/,   martinvl\$$1.class martinvl_slow\$$1.class)
TGT += $(addprefix kristian/solutions/,  hawken hawken_wrong martinvl.class olalia)
TGT += $(addprefix pinmaker2/solutions/, martinvl_exponential.class martinvl.class martinvl_linear.class martinvl_overflow.class)
TGT += $(addprefix pinmaker/solutions/,  martinvl martinvl.class martinvl_overflow.class martinvl_slow martinvl_slow.class)
TGT += $(addprefix prize/solutions/,     hawken martinvl martinvl_slow martinvl_wrong martinvl_wrong2)
TGT += $(addprefix quid/solutions/,      kjetimh martinvl.class)
REM += $(addprefix quid/solutions/,      martinvl\$$Edge.class martinvl\$$Graph.class)
TGT += $(addprefix rabout/solutions/,    olalia olalia_slow hawken)
TGT += $(addprefix ssnw/server/,         main)
REM += $(addprefix ssnw/server/,         main.o irq.o network.o)
TGT += $(addprefix ssnw/solutions/,      hennilu Hennilu.class sjurtf)
TGT += $(addprefix walk/solutions/,      olalia hawken)
TGT += $(addprefix war/scripts-stuff/,   hawken cdedup)
TGT += $(addprefix war/solutions/,       hawken hawken.class joakimjl.class)

### Basic make rules
.PHONY: all clean

all: $(TGT)

clean:
	@rm -vf $(TGT)
	@rm -vf $(REM)

# Specific compilation stuff goes here
ssnw/server/main: $(addprefix ssnw/server/, main.o network.o irq.o)

### java rule, assume one .java compiles the equivalently named .class
%.class: %.java
	javac $< || $(IGNOREJAVA)
