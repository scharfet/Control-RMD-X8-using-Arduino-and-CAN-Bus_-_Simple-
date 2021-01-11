// CAN Send Example
//

#include <mcp_can.h>
#include <SPI.h>

long unsigned int rxId;
unsigned char len = 0;
unsigned char rxBuf[8];
char msgString[128];                        // Array to store serial string
#define CAN0_INT 2                              // Set INT to pin 2

MCP_CAN CAN0(10);     // Set CS to pin 10

void setup()
{
  Serial.begin(115200);

  // Initialize MCP2515 running at 16MHz with a baudrate of 500kb/s and the masks and filters disabled.
  if (CAN0.begin(MCP_ANY, CAN_1000KBPS, MCP_16MHZ) == CAN_OK) Serial.println("MCP2515 Initialized Successfully!");
  else Serial.println("Error Initializing MCP2515...");

  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
}


void loop()


/* VERSION 1 ================================== */
/* Speed value in Hex, possible? ===================== */

{
  byte data[8] = {0xA2, 0x00, 0x00, 0x00, 0xA0, 0x86, 0x01, 0x00};
    // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
    byte sndStat = CAN0.sendMsgBuf(0x141, 0, 8, data);
  }



/* VERSION 2 ================================ */
/*  Speed value in decimal 

  byte data[8] = {0xA2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
for (long speed = 0; speed < 100000; speed += 100) {
    data[4] = speed & 0xFF;
    data[5] = (speed >> 8) & 0xFF;
    data[6] = (speed >> 16) & 0xFF;
    data[7] = (speed >> 24) & 0xFF;
    // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
    byte sndStat = CAN0.sendMsgBuf(0x141, 0, 8, data);
  }
*/
