EXECUTABLE=expmple.out


example: clean
	g++ -Wall -Wextra -Werror -Wpedantic --std=c++17 example.cc -o $(EXECUTABLE)
	.$(SEP)$(EXECUTABLE)

clean:
	$(DELETE_FILE) $(EXECUTABLE)


# Crossplatform specs
# Inherited from one project to another
# so did not changed even if no need of all
SEP='\'
MAKEDIR=md
DELETE_FOLDER=RD /S/Q
DELETE_FILE=DEL /F
COPY=copy -Recurse
OPEN=start
OS=$(shell uname)

ifeq ($(OS), Linux)
	OPEN=xdg-open
	MAKEDIR=mkdir -p
	SEP=/
	DELETE_FOLDER=rm -rf
	DELETE_FILE=rm -f
	COPY=cp -r
endif

ifeq ($(OS), Darwin)
	OPEN=open
	MAKEDIR=mkdir -p
	SEP=/
	DELETE_FOLDER=rm -rf
	DELETE_FILE=rm -f
	COPY=cp -r
endif
