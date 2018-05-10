DIR = ../hw1
TARGET = $(DIR)/sample_unittest
SRC = $(DIR)/sample.cc

all:
	make -C $(DIR) USER_DIR=triangle -B
	make -C $(DIR) USER_DIR=nextdate -B
	make -C $(DIR) USER_DIR=commission -B

test:
	make -C $(DIR) USER_DIR=triangle -B
	$(TARGET)
	make -C $(DIR) USER_DIR=nextdate -B
	$(TARGET)
	make -C $(DIR) USER_DIR=commission -B
	$(TARGET)

gcov:
	make -C $(DIR) USER_DIR=triangle -B
	$(TARGET)
	gcov $(SRC)
	make -C $(DIR) USER_DIR=nextdate -B
	$(TARGET)
	gcov $(SRC)
	make -C $(DIR) USER_DIR=commission -B
	$(TARGET)
	gcov $(SRC)
