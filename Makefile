# Basics
#################
SHELL		?=	/bin/sh
RM			=	-@rm -rf
CC			=	gcc
LD			=	ld
AS			=	nasm
PSRC			=	src

PUT			=	tests/ut

CFLAGS			=	-Wall -Wextra -Wshadow

ASFLAGS		=	-f elf64

LDFLAGS		=

SSRC			=	$(PSRC)/strlen.asm		\
					$(PSRC)/strchr.asm		\
					$(PSRC)/strrchr.asm		\
					$(PSRC)/memset.asm		\
					$(PSRC)/memcpy.asm	\
					$(PSRC)/strcmp.asm		\
					$(PSRC)/strncmp.asm	\
					$(PSRC)/strcasecmp.asm	\
					$(PSRC)/memmove.asm	\
					$(PSRC)/strcspn.asm	\
					# $(PSRC)/strstr.asm		\
					$(PSRC)/rindex.asm		\
					$(PSRC)/strpbrk.asm	\

SUT			=		$(PUT)/t_strlen.c		\
					$(PUT)/t_strchr.c		\
					$(PUT)/t_strrchr.c		\
					$(PUT)/t_memset.c		\
					$(PUT)/t_memcpy.c		\
					$(PUT)/t_strcmp.c		\
					$(PUT)/t_strncmp.c		\
					$(PUT)/t_strcasecmp.c	\
					$(PUT)/t_strcspn.c		\
					# $(PUT)/t_memmove.c		\
					# $(PUT)/t_rindex.c		\
					$(PUT)/t_strpbrk.c		\
					$(PUT)/t_strstr.c		\

OSRC			=	$(SSRC:.asm=.o)

BIN			=	libasm.so

TEST			=	unit_tests

all:	$(BIN)

$(BIN):	LDFLAGS += -share
$(BIN):	clean_src $(OSRC)
		$(LD) $(OSRC) -o $(BIN) $(LDFLAGS)

test_run: fclean
	@./tests/all

$(TEST):	ASFLAGS += -DUNIT_TEST
$(TEST):	LDFLAGS += -lcriterion
$(TEST):	clean_src $(OSRC)
	$(CC) $(OSRC) $(SUT) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(TEST)
	-@./$(TEST)

$(UT_OPTI):	LDFLAGS += -lcriterion
$(UT_OPTI):	$(OOPTI)
	$(CC) $(OOPTI) $(SOUT) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(UT_OPTI)
	-@./$(UT_OPTI)

%.o: %.asm
	$(AS) $(ASFLAGS) $^ -o $@

clean_src:
	$(RM) $(OSRC)

clean: clean_src
	$(RM) .tmp
	$(RM) *.gc*

fclean:	clean
	$(RM) $(BIN)
	$(RM) $(TEST)
	$(RM) $(UT_OPTI)

re: fclean all

.PHONY: all re clean fclean $(TEST) $(BIN) $(UT_OPTI)
