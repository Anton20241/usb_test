#pragma once

#include "SerialPort.hpp"
#include <chrono>
#include <thread>
#include <unistd.h>
//#include <termios.h>



using namespace mn::CppLinuxSerial;

int main() {
	// Create serial port object and open serial port
    SerialPort serialPort("/dev/ttyUSB0", 256000);
	// SerialPort serialPort("/dev/ttyACM0", 13000);
    serialPort.SetTimeout(-1); // Block when reading until any data is received
	serialPort.Open();

	// Write some ASCII datae
	// serialPort0.Write("Hello");

	// Read some data back
    while(1) {

        //std::this_thread::sleep_for(std::chrono::milliseconds(100));

        uint8_t ptrData1[9] = {0x16, 0x09, 0x30, 0, 0, 0, 0, 0, 0xE0};
        uint32_t send_bytes = serialPort.Write(ptrData1, sizeof(ptrData1));
        std::chrono::system_clock::time_point from_send_to_get_tp = std::chrono::system_clock::now();
        if (!send_bytes) continue;

        // printf("\n[SEND]:\n");
        // for (size_t i = 0; i < send_bytes; i++){
        //   printf("[%u]", ptrData1[i]);
        // }
        // std::cout << std::endl;

        uint8_t read_buf[13] = {0};
        uint32_t get_bytes = serialPort.Read(read_buf, sizeof(read_buf));
        
        if (get_bytes > 0){

          std::chrono::system_clock::time_point from_send_to_get_cur_tp = std::chrono::system_clock::now();
          std::chrono::duration<double> from_send_to_get_ex_time = from_send_to_get_cur_tp - from_send_to_get_tp;
          std::cout << "from_send_to_get_ex_time time: " << from_send_to_get_ex_time.count() * 1000000 << std::endl;

          // printf("[RECEIVED]:\n");
          // for (size_t i = 0; i < get_bytes; i++){
          //   printf("[%u]", read_buf[i]);
          // }
          // std::cout << std::endl;
        }
    }

	// Close the serial port
	serialPort.Close();
}