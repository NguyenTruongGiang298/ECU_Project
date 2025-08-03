# Compiler and flags
CC       := gcc
CFLAGS   := -std=c99 -Wall -Wextra -pthread

# Thư mục chứa header và source files
HEADER_DIRS := 	csvlib		       	\
				MCAL/ADC          	\
				MCAL/CAN          	\
				MCAL/DIO          	\
				MCAL/PWM  
INCLUDES := $(addprefix -I, $(HEADER_DIRS))

SRCS := main.c 			\
        csvlib/csv_io.c \
        MCAL/ADC/Adc.c 	\
        MCAL/CAN/Can.c 	\
        MCAL/DIO/Dio.c 	\
        MCAL/PWM/Pwm.c

				

BINARY_DIR :=Build

# file thực thi
BIN := $(BINARY_DIR)/my_programme

# Quy định tên của file Object
OBJECTS := $(SRCS:%.c=$(BINARY_DIR)/%.o)

# Quy tắc đầu tiên là quy tắc mặc định sẽ được thực thi
all: $(BIN)

# Tạo bin nếu chưa tồn tại
# Trước khi compile, tạo thư mục chứa object file nếu chưa có
$(BINARY_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

	
# Quy tắc để tạo ra tệp thực thi
$(BIN): $(OBJECTS) | $(BINARY_DIR)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS)

# Quy tắc để biên dịch các tệp .c thành .o
$(BINARY_DIR)/%.o: %.c | $(BINARY_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


# Quy tắc để làm sạch thư mục build
clean:
	rm -rf $(BINARY_DIR)

# Quy tắc chạy chương trình
run: $(BIN)
	@./$(BIN)

# Quy tắc giả (phony target)
.PHONY: all clean

