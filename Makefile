# Library stuff
LDFLAGS 		:= 

# ooga booga variables
TARGET_NAME	:= catfetch
INCLUDE 	:= include
SOURCE		:= source
OUT			:= out
INSTALLDIR	:= $(HOME)/.local/bin

# Source files
CXX_SRC_FILES	:= $(wildcard $(addsuffix /*.cpp ,$(SOURCE)))
CC_SRC_FILES	:= $(wildcard $(addsuffix /*.c ,$(SOURCE)))

all:
	mkdir -p $(OUT)
	$(CXX) $(CC_SRC_FILES) $(CXX_SRC_FILES) -o $(OUT)/$(TARGET_NAME) -I$(INCLUDE) $(LDFLAGS)

clean:
	rm -rf $(OUT)

install:
	cp $(OUT)/$(TARGET_NAME) $(INSTALLDIR)/$(TARGET_NAME)

uninstall:
	rm $(INSTALLDIR)/$(TARGET_NAME)