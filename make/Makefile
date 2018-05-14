DIR = ..
TARGET = sample_unittest
SRC = sample.cc

all:
	make -C $(DIR)/p_triangle
	make -C $(DIR)/p_nextdate
	make -C $(DIR)/p_commission

test:
	$(DIR)/p_triangle/$(TARGET)
	$(DIR)/p_nextdate/$(TARGET)
	$(DIR)/p_commission/$(TARGET)

gcov:
	gcov $(DIR)/p_triangle/$(SRC)
	gcov $(DIR)/p_nextdate/$(SRC)
	gcov $(DIR)/p_commission/$(SRC)

clean:
	make -C $(DIR)/p_triangle clean
	make -C $(DIR)/p_nextdate clean
	make -C $(DIR)/p_commission clean

