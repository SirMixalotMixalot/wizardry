CXX       := g++
CXXFLAGS  := -std=c++14 -Wall -g
CPPFLAGS  := -MMD -MP -Iminions -Iservices
EXEC      := sorcery

SRCS := $(wildcard *.cc minions/*.cc services/*.cc)
OBJS := $(SRCS:.cc=.o)
DEPS := $(OBJS:.o=.d)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

-include $(DEPS)

.PHONY: clean
clean:
	$(RM) $(EXEC) $(OBJS) $(DEPS)
