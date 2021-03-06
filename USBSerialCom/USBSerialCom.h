#ifndef USB_SERIAL_COM_H
#define USB_SERIAL_COM_H


#include "mbed.h"
#include "BufferedSerial.h"


#define NBR_CHAR_NAV 16

#define KP_POLAR_ANGLE 800
#define KD_POLAR_ANGLE 0.0
#define KI_POLAR_ANGLE 0.0
#define KI_POLAR_ANGLE_SAT 1.0

#define KP_POLAR_LINEAR 400
#define KD_POLAR_LINEAR 0.0
#define KI_POLAR_LINEAR 0.000
#define KI_POLAR_LINEAR_SAT 1.0

#define COM_TIMEOUT 500  // in ms

class MotorCtrl;

class USBSerialCom 
{
    
public:    

    //USBSerialCom(Serial& _pc, MotorCtrl& _asser);  //COnstructor 
    USBSerialCom(void);  //COnstructor 
    
    void processSerialPort();
    
    void setAsser(MotorCtrl * a)
    { asser = a; }
    
    void printMetrics(); // print data like odometri or metrics
    void printOdo(); // print data like odometri or metrics
    void printRobotStatus();
    
    void setSStatus(bool value);
    
    int getTtwist();
    int getVtwist();
    bool getSStatus();
    
    bool getUPower() ;
    
    float getKpPL();
    float getKdPL();
    float getKiPL();
    float getKiPLS();
    
    float getKpPA();
    float getKdPA();
    float getKiPA();
    float getKiPAS();
    
    void sendFeedback(long pidL, long pidR, float pidA, float pidT);
    void sendHeartBeat(long data);
    void sendCoeffs();
    
    bool checkTimeOut();
    
 //   MotorCtrl asser2; 
    
protected:
  
    
    int interpretData(); //Function to be called when we received the full packet

    Timer t_timeout_com;
    
    char inputString[NBR_CHAR_NAV];
    char incomming_message_type;
    char nbr_incom_char;
    long incom_data; 
        
    bool sign;
    
    //commandes/setpoints de l'assrvissement
    long Xorder;
    long Yorder;   
    long Aorder;
    int Lspeed;
    int Rspeed;
    int Ttwist;
    int Vtwist;
    bool SStatus;
    bool UPower;
    
    
    // coefficients d'asservissement pour le polaire
    long KpPL;
    long KdPL;
    long KiPL;
    long KiPLS;
    
    long KpPA;
    long KdPA;
    long KiPA;
    long KiPAS;
    
    bool metricsEnabled;
    bool odoEnabled;
    
    BufferedSerial pc;
   // MotorCtrl& asser;
   MotorCtrl * asser;
    
};

#endif
 