 LOG=${info [ft_nm] $1}
SILENT=@

SRC_DIR=src
SRC=$(wildcard $(SRC_DIR)/*.c)

INCL=include        \
	 lib/ft/includes

OBJ_DIR=obj
OBJ=$(patsubst %.c,%.o,$(addprefix $(OBJ_DIR)/,$(notdir $(SRC))))

EXE=ft_nm

LIBFT_DIR=lib/ft
LIBFT=$(LIBFT_DIR)/libft.a

CC=gcc
CFLAGS=$(addprefix -I , $(INCL))
LDFLAGS=-L lib/ft -l ft

all: $(EXE)

$(EXE): $(OBJ_DIR) $(OBJ) $(LIBFT)
	${call LOG,Linking executable}
	$(SILENT) $(CC) $(OBJ) -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	${call LOG,Compiling C object $<}
	$(SILENT) $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	${call LOG,Creating folder for objects}
	$(SILENT) mkdir $(OBJ_DIR)

$(LIBFT):
	${call LOG,Building libft}
	$(SILENT) make -C $(LIBFT_DIR)

clean:
	${call LOG,Deleting objects}
	$(SILENT) rm -rf $(OBJ_DIR)
	${call LOG,Cleaning libft}
	$(SILENT) make -C $(LIBFT_DIR) clean

fclean:
	${call LOG,Deleting objects}
	$(SILENT) rm -rf $(OBJ_DIR)
	${call LOG,Deleting executable}
	$(SILENT) rm -f $(EXE)
	${call LOG,Cleaning libft}
	$(SILENT) make -C $(LIBFT_DIR) fclean

re: fclean all
