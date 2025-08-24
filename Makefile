# Makefile for LeetCode C++ Solutions
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
DEBUG_FLAGS = -std=c++17 -Wall -Wextra -g -DDEBUG

# Directories
DAILY_DIR = daily
MATH_DIR = math
RANDOM_DIR = random
INTERVIEW_DIR = interview

# Output directories
DAILY_OUTPUT = $(DAILY_DIR)/output
MATH_OUTPUT = $(MATH_DIR)/output
RANDOM_OUTPUT = $(RANDOM_DIR)/output
INTERVIEW_OUTPUT = $(INTERVIEW_DIR)/output

# Find all cpp files
DAILY_SOURCES = $(wildcard $(DAILY_DIR)/*.cpp)
MATH_SOURCES = $(wildcard $(MATH_DIR)/*.cpp)
RANDOM_SOURCES = $(wildcard $(RANDOM_DIR)/*.cpp)
INTERVIEW_SOURCES = $(wildcard $(INTERVIEW_DIR)/*.cpp)

# Generate executable names
DAILY_TARGETS = $(patsubst $(DAILY_DIR)/%.cpp,$(DAILY_OUTPUT)/%,$(DAILY_SOURCES))
MATH_TARGETS = $(patsubst $(MATH_DIR)/%.cpp,$(MATH_OUTPUT)/%,$(MATH_SOURCES))
RANDOM_TARGETS = $(patsubst $(RANDOM_DIR)/%.cpp,$(RANDOM_OUTPUT)/%,$(RANDOM_SOURCES))
INTERVIEW_TARGETS = $(patsubst $(INTERVIEW_DIR)/%.cpp,$(INTERVIEW_OUTPUT)/%,$(INTERVIEW_SOURCES))

ALL_TARGETS = $(DAILY_TARGETS) $(MATH_TARGETS) $(RANDOM_TARGETS) $(INTERVIEW_TARGETS)

# Default target
.PHONY: all clean test help dirs

all: dirs $(ALL_TARGETS)

# Create output directories
dirs:
	@mkdir -p $(DAILY_OUTPUT) $(MATH_OUTPUT) $(RANDOM_OUTPUT) $(INTERVIEW_OUTPUT)

# Compilation rules for each category
$(DAILY_OUTPUT)/%: $(DAILY_DIR)/%.cpp | $(DAILY_OUTPUT)
	$(CXX) $(CXXFLAGS) $< -o $@

$(MATH_OUTPUT)/%: $(MATH_DIR)/%.cpp | $(MATH_OUTPUT)
	$(CXX) $(CXXFLAGS) $< -o $@

$(RANDOM_OUTPUT)/%: $(RANDOM_DIR)/%.cpp | $(RANDOM_OUTPUT)
	$(CXX) $(CXXFLAGS) $< -o $@

$(INTERVIEW_OUTPUT)/%: $(INTERVIEW_DIR)/%.cpp | $(INTERVIEW_OUTPUT)
	$(CXX) $(CXXFLAGS) $< -o $@

# Debug builds
debug: CXXFLAGS = $(DEBUG_FLAGS)
debug: all

# Test all executables (basic compilation check)
test: all
	@echo "Testing compilation of all solutions..."
	@for exe in $(ALL_TARGETS); do \
		if [ -f "$$exe" ]; then \
			echo "✓ $$exe compiled successfully"; \
		else \
			echo "✗ $$exe failed to compile"; \
			exit 1; \
		fi; \
	done
	@echo "All solutions compiled successfully!"

# Clean all generated files
clean:
	rm -rf $(DAILY_OUTPUT) $(MATH_OUTPUT) $(RANDOM_OUTPUT) $(INTERVIEW_OUTPUT)
	rm -f *.o *.out *.exe

# Individual category targets
daily: dirs $(DAILY_TARGETS)
math: dirs $(MATH_TARGETS)
random: dirs $(RANDOM_TARGETS)
interview: dirs $(INTERVIEW_TARGETS)

# Help
help:
	@echo "Available targets:"
	@echo "  all        - Compile all solutions"
	@echo "  daily      - Compile daily solutions only"
	@echo "  math       - Compile math solutions only"
	@echo "  random     - Compile random solutions only"
	@echo "  interview  - Compile interview solutions only"
	@echo "  debug      - Compile with debug flags"
	@echo "  test       - Test compilation of all solutions"
	@echo "  clean      - Remove all compiled files"
	@echo "  help       - Show this help message"

# Create output directories
$(DAILY_OUTPUT) $(MATH_OUTPUT) $(RANDOM_OUTPUT) $(INTERVIEW_OUTPUT):
	mkdir -p $@
