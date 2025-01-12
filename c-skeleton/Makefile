# make PREFIX=/tmp OPTFLAGS=-pthread ... 이런식으로 인자를 넘겨줄 수 있다.

# -DNDEBUG for dbg.h
CFLAGS=-g -O2 -Wall -Wextra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)

# ?=는 이미 값이 설정되어 있지 않은 경우에만 할당
PREFIX?=/usr/local

SOURCE=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCE)) # $(patsubst pattern,replacement,text). 여기선 %.c를 %.o로 모두 바꿈

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# ------------------------------------------------
# The Target Build

# deps 정의
all: 
	$(TARGET) 
	$(SO_TARGET) 
	tests

dev: CFLAGS=-g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev: all # dev target은 all target을 deps로 가짐

build:
	@mkdir -p build
	@mkdir -p bin

# target을 만드는 규칙
$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS) # $@ 는 현재 파일 이름
	ranlib $@

# so_target을 만드는 규칙
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)


# ------------------------------------------------
# The Unit Tests
.PHONY: tests
tests: CFLAGS += $(TARGET)
tests: $(TESTS)
	sh ./tests/runtests.sh


# ------------------------------------------------
# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc*" -exec rm {} \;
	rm -rf `find . -name "*.dSYM" -print`

# ------------------------------------------------
# The Install
install: all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	install $(TARGET) $(DESTDIR)/$(PREFIX)/lib

# ------------------------------------------------
# The Checker
check:
	@echo Files with potentially dangerous functions
	@grep '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|strn?cpy|a?sn?printf|byte_)' $(SOURCE) || true
