CXX         := g++
CXXFLAGS    := -std=c++17 -g #-fsanitize=address #-Wall #-Wextra

BIN         := bin
SRC         := src
BUILD       := build
INCLUDE     := include
LIB         := lib
DATA        := data
LIBRARIES   := 
EXECUTABLE  := p06_automata_simulator
EXECUTABLE_TRACE := p06_automata_simulator_trace
PARAMS      := 
SOURCES     := $(wildcard $(SRC)/*.cc)
OBJS        := $(patsubst $(SRC)/%.cc, $(BUILD)/%.o,$(SOURCES))
OBJS_TRACE  := $(patsubst $(SRC)/%.cc, $(BUILD)/%_trace.o,$(SOURCES))

.PHONY: all project run clean trace

all: $(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(OBJS)
	@echo "🚧 Building..."
	$(CXX) -o $@ $(CXXFLAGS) -L$(LIB) $(OBJS)

$(BUILD)/%.o: $(SRC)/%.cc
	@echo "🚧 Building..."
	$(CXX) -c -o $@ $(CXXFLAGS) $<

trace: CXXFLAGS += -D TRACE
trace: clean all
	@echo "🛠️  Built with TRACE mode"

project:
	clear
	@echo "📁 Creating Project Structure..."
	mkdir -p bin build include src

run:
	@echo "🚀 Executing..."
	./$(BIN)/$(EXECUTABLE) $(PARAMS)

clean:
	@echo "🧹 Clearing..."
	rm -f $(BIN)/* $(BUILD)/*

tar:
	@echo "📦 Compressing..."
	tar -czvf p06_Cheuk_Kelly_Ng_Pante.tgz $(SRC) $(INCLUDE) $(BIN) $(BUILD) $(DATA) makefile
