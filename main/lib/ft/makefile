FUNC_READ_FILE = ${shell grep -v '^\#' $1}

FUNC_INFO = ${info [libft] $1}
FUNC_ITERATE = ${foreach line,$2,${call $1,${line}}}

FUNC_GEN_OBJECT = ${patsubst %.c,%.o,${addprefix ${OBJECTS_DIR}/,${notdir $1}}}
FUNC_GEN_DEPEND = ${patsubst %.c,%.d,${addprefix ${DEPENDS_DIR}/,${notdir $1}}}

INCLUDES = -I ./includes

SOURCES_LIST = ./build/source.txt
SOURCES = ${call FUNC_READ_FILE, ${SOURCES_LIST}}

VPATH_LIST = ./build/vpath.txt
VPATH = ${call FUNC_READ_FILE, ${VPATH_LIST}}

OBJECTS_DIR = ./build/objects
OBJECTS = ${call FUNC_ITERATE,FUNC_GEN_OBJECT,${SOURCES}}

DEPENDS_DIR = ./build/depends
DEPENDS = ${call FUNC_ITERATE,FUNC_GEN_DEPEND,${SOURCES}}

LIB = libft.a
TRY = try

all : ${LIB}

${TRY} : all
	@touch ${TRY}
	@rm ${TRY}

${LIB} : ${OBJECTS} ${DEPENDS} | ${OBJECTS_DIR} ${DEPENDS_DIR}
	${call FUNC_INFO,Building library}
	@ar rc ${LIB} ${OBJECTS}
	@ranlib ${LIB}

${OBJECTS_DIR} :
	${call FUNC_INFO,Creating folder for objects}
	@mkdir ${OBJECTS_DIR}

${OBJECTS_DIR}/%.o : %.c ${DEPENDS_DIR}/%.d | ${OBJECTS_DIR} ${DEPENDS_DIR}
	${call FUNC_INFO,Compiling C object $<}
	@gcc -MMD -MT $@ -MF ${call FUNC_GEN_DEPEND,$<} ${INCLUDES} -c $< -o $@

${DEPENDS_DIR} :
	${call FUNC_INFO,Creating folder for depends}
	@mkdir ${DEPENDS_DIR}

${DEPENDS} :

clean :
	${call FUNC_INFO,Deleting objects}
	@rm -rf ${OBJECTS_DIR}
	${call FUNC_INFO,Deleting depends}
	@rm -rf ${DEPENDS_DIR}

fclean : clean
	${call FUNC_INFO,Deleting library}
	@rm -rf ${LIB}

re : fclean all

report :
	${info }
	${call FUNC_INFO,sources = ${SOURCES}}
	${info }
	${call FUNC_INFO,vpath = ${VPATH}}
	${info }
	${call FUNC_INFO,objects = ${OBJECTS}}
	${info }
	${call FUNC_INFO,depends = ${DEPENDS}}
	${info }

.PHONY : all clean fclean re report

include ${wildcard ${DEPENDS}}
