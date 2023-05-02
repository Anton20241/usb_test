#pragma once

#include "SerialPort.hpp"
#include <chrono>
#include <thread>
#include <unistd.h>
//#include <termios.h>
#define FING_INDEX 0

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

    uint32_t timeFailCount = 0;
    uint32_t msgFailcount = 0;
    int gen_count = 0;
    while(gen_count < 1000) {
        gen_count++;

        //std::this_thread::sleep_for(std::chrono::milliseconds(100));

        std::vector<std::vector<uint8_t>> fingersReq = {{0x11, 0x09, 0x30, 0, 0, 0, 0, 0, 0x2E},
                                                        {0x12, 0x09, 0x30, 0, 0, 0, 0, 0, 0xF5},
                                                        {0x13, 0x09, 0x30, 0, 0, 0, 0, 0, 0xBC},
                                                        {0x14, 0x09, 0x30, 0, 0, 0, 0, 0, 0x72},
                                                        {0x15, 0x09, 0x30, 0, 0, 0, 0, 0, 0x3B},
                                                        {0x16, 0x09, 0x30, 0, 0, 0, 0, 0, 0xE0}
        };

        std::vector<std::vector<uint8_t>> fingersRes = {{0x11, 0x0d, 0x30, 0, 0, 0, 0, 0, 0, 0,     0,    0x88, 0x6D},
                                                        {0x12, 0x0d, 0x30, 0, 0, 0, 0, 0, 0, 0,     0,    0x98, 0x87},
                                                        {0x13, 0x0d, 0x30, 0, 0, 0, 0, 0, 0, 0,     0,    0x88, 0xA3},
                                                        {0x14, 0x0d, 0x30, 0, 0, 0, 0, 0, 0, 0,     0,    0x80, 0x1E},
                                                        {0x15, 0x0d, 0x30, 0, 0, 0, 0, 0, 0, 0,     0,    0x98, 0x83},
                                                        {0x16, 0x0d, 0x30, 0, 0, 0, 0, 1, 0, 0xFF,  0x7F, 0x08, 0x29}
        };

        uint32_t send_bytes = 0;
        while (!send_bytes) send_bytes = serialPort.Write(&(fingersReq[FING_INDEX][0]), fingersReq[FING_INDEX].size());
        std::chrono::system_clock::time_point from_send_to_get_tp = std::chrono::system_clock::now();

        // printf("\n[SEND]:\n");
        // for (size_t i = 0; i < send_bytes; i++){
        //   printf("[%u]", fingersReq[FING_INDEX][i]);
        // }
        // printf("\nsend_bytes = %u\n", send_bytes);

        uint8_t read_buf[13] = {0};
        uint32_t get_bytes = 0;
        while (!get_bytes) get_bytes = serialPort.Read(read_buf, sizeof(read_buf));

        std::chrono::system_clock::time_point from_send_to_get_cur_tp = std::chrono::system_clock::now();
        std::chrono::duration<double> from_send_to_get_ex_time = from_send_to_get_cur_tp - from_send_to_get_tp;
        std::cout << "\nfrom_send_to_get_ex_time time: " << from_send_to_get_ex_time.count() * 1000000 << std::endl;
        printf("gen_count = %u\n", gen_count);
        printf("timeFailCount = %u\n", timeFailCount);
        printf("msgFailcount = %u\n", msgFailcount);

        if (from_send_to_get_ex_time.count() * 1000000 > 7000){
            timeFailCount++;
        }

        for (size_t i = 0; i < get_bytes; i++){
            if(read_buf[i] != fingersRes[FING_INDEX][i]){
                msgFailcount++;
                break;
            }
        }
        
        printf("[RECEIVED]:\n");
        for (size_t i = 0; i < get_bytes; i++){
            printf("[%u]", read_buf[i]);
        }
        printf("\nget_bytes = %u\n", get_bytes);
    }

	// Close the serial port
	serialPort.Close();
}