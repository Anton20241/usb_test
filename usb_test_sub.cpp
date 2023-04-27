// C library headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <sys/signal.h>
#include <sys/types.h>
#include <boost/asio.hpp>
#include <boost/function.hpp>

#define FALSE 0
#define TRUE 1

int serial_port;

void setup(std::string port, int boudrate){

  /* open the device to be non-blocking (read will return immediatly) */
  serial_port = open(port.c_str(), O_RDWR | O_NOCTTY);
  if (serial_port < 0) {perror(port.c_str()); exit(-1); }

  // Create new termios struct, we call it 'tty' for convention
  struct termios tty;

  // Read in existing settings, and handle any error
  if(tcgetattr(serial_port, &tty) != 0) {
    printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
  }

  tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
  tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
  tty.c_cflag &= ~CSIZE; // Clear all bits that set the data size
  tty.c_cflag |= CS8; // 8 bits per byte (most common)
  tty.c_cflag &= ~CRTSCTS;
  tty.c_cflag |= CREAD | CLOCAL;
  tty.c_iflag &= ~(IXON | IXOFF | IXANY);
  tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes
  tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
  tty.c_oflag &= ~OPOST;

  // Set up timeouts: Calls to read() will return as soon as there is
  // at least one byte available or when 100 ms has passed.
  tty.c_cc[VTIME] = 0;
  tty.c_cc[VMIN] = 13;

  // Set in/out baud rate to be BAUDRATE
  cfsetispeed(&tty, boudrate);
  cfsetospeed(&tty, boudrate);

  // Save tty settings, also checking for error
  if (tcsetattr(serial_port, TCSANOW, &tty) != 0) {
      printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
  }
}

int main(int argc, char *argv[]) {

    if(argc < 3){
        std::cout << "[./usb_test_sub][/dev/ttyX][baudrate]\n";
        return -1;
    }

    std::string port = argv[1];
    std::string baudrate = argv[2];

  setup(port, std::stoi(baudrate));
  uint32_t read_count = 0;
  uint32_t send_count = 0;

  while(1){
    // Flush away any bytes previously read or written.
    int result = tcflush(serial_port, TCIOFLUSH);
    if (result){
      perror("tcflush failed");  // just a warning, not a fatal error
    }

    //read data
    uint8_t read_buf [13] = {0};
    int read_bytes = read(serial_port, &read_buf, sizeof(read_buf));
    if (read_bytes >= 0){
      read_count++;
      std::cout << "\nread_bytes = " << read_bytes << "\n";
      for (size_t i = 0; i < read_bytes; i++)
      {
        printf("[%u]", read_buf[i]);
      }
      std::cout << "\n";
      std::cout << "read_count = " << read_count << "\n";
    }
  }
  close(serial_port);
  return 0; // success
};

