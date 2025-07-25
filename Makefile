CXX       := g++
CXXFLAGS  := -std=c++14 -Wall -g
CPPFLAGS  := -MMD -MP -Iminions -Iservices -Ispells -I. -Icommands -Ienchantments -Icontrollers -Imodels -Iviews -Iabilities -Iabilities/activatedabilities -Iasciiart
EXEC      := sorcery

SRCS := $(wildcard *.cc minions/*.cc services/*.cc spells/*.cc commands/*.cc enchantments/*.cc controllers/*.cc models/*.cc views/*.cc abilities/*.cc abilities/activatedabilities/*.cc asciiart/*.cc)
OBJS := $(SRCS:.cc=.o)
DEPS := $(OBJS:.o=.d)

$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@

-include $(DEPS)

.PHONY: clean
clean:
	$(RM) $(EXEC) $(OBJS) $(DEPS)
