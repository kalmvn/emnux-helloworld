#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>

#define BYTES_READ 2U

int main(){
    
    //Settings
    int file;
    const unsigned char test_addr = 0x48; //Test address
    const unsigned char test_reg= 0xA0; //Test register

    const char i2c_0[] = "/dev/i2c-0";
    const char i2c_1[] = "/dev/i2c-1";
    const char i2c_2[] = "/dev/i2c-2"; //Location of i2c3 in /dev directory


    // open_i2c_device(i2c_0); //i2c1
    // open_i2c_device(i2c_1); //i2c2
    // open_i2c_device(i2c_2); //i2c3 - imx8mm J1003 i2c

    // Open the device file for read/write
    if ((file = open(i2c_2, O_RDWR)) < 0){
        printf("Failed to open the bus.\n");
        exit(1);
    }

    //Using ioctl point to the i2c address of the slave
    //This I2C_SLAVE constant is used as the command to specify that you want to set the target I2C slave address
    if(ioctl(file, I2C_SLAVE, test_addr) < 0 ) {
        printf("Failed to acquire bus access. \n");
        exit(1);
    }

    //Start read by writing to the test register 
    static char buf[5];
    

    buf[0] = 0xA0;
    
    if(write(file, buf, 1) != 1)
    {
        printf("Failed to write to I2C Device \n");
        printf("DEBUG: Number of bytes written: %d \n", write);
        exit(1);
    }

    //Sample read command, the number of bytes reads should be returned
    if(read(file, buf, BYTES_READ) != BYTES_READ){
        printf("Failed to read from I2C Device \n");
        exit(1);
    }

    //Store received bytes to a 16-bit value (Le)
    static int16_t temp_buf = 0;
    temp_buf =  (buf[0] << 4) | (buf[1] >> 4);

    printf("Result : %d", temp_buf);

    return 0;
    
}



// void open_i2c_device(const char * device_name)
// {
//     // Open the device file for read/write
//     if ((file = open(device_name, O_RDWR)) < 0)
//     {
//         printf("Failed to open the bus.\n");
//         exit(1);
//     }
// }


