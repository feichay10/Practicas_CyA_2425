CXX         := g++
CXXFLAGS    := -std=c++17 -g #-fsanitize=address #-Wall #-Wextra

BIN         := bin
SRC         := src
BUILD       := build
INCLUDE     := include
LIB         := lib
DATA        := data
LIBRARIES   := 
EXECUTABLE  := p08_Grammar2CNF
PARAMS      := 
SOURCES     := $(wildcard $(SRC)/*.cc)
OBJS        := $(patsubst $(SRC)/%.cc, $(BUILD)/%.o,$(SOURCES))

.PHONY: all project run clean trace

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L$(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cc
	@echo "🚧 Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

project:
	clear
	@echo "📁 Creating Project Structure..."
	mkdir -p bin build include src data

run:
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMS)

clean:
	@echo "🧹 Clearing..."
	rm -f $(BIN)/* $(BUILD)/*

tar:
	@echo "📦 Compressing..."
	tar -czvf p08_Cheuk_Kelly_Ng_Pante.tgz $(SRC) $(INCLUDE) $(BIN) $(BUILD) $(DATA) makefile
