DIR = ../hw1
TARGET = $(DIR)/sample_unittest

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
