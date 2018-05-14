DIR = ..
TARGET = sample_unittest
SRC = sample.cc

all:
	make -C $(DIR)/p_triangle
	make -C $(DIR)/p_nextdate
	make -C $(DIR)/p_commission

test:
	make -C $(DIR)/p_triangle test
	make -C $(DIR)/p_nextdate test
	make -C $(DIR)/p_commission test

gcov:
	make -C $(DIR)/p_triangle gcov
	make -C $(DIR)/p_nextdate gcov
	make -C $(DIR)/p_commission gcov

clean:
	make -C $(DIR)/p_triangle clean
	make -C $(DIR)/p_nextdate clean
	make -C $(DIR)/p_commission clean

