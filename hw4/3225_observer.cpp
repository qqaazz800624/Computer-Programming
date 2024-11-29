#include "3225_observer.h"
 
using namespace std;
 
PCDevice::PCDevice(std::string ipAddress){
    this->ipAddress = ipAddress;
}
 
iOSDevice::iOSDevice(std::string apnsToken){
    this->apnsToken = apnsToken;
}
 
AndroidDevice::AndroidDevice(std::string fcmToken){
    this->fcmToken = fcmToken;
}

void PCDevice::notify(std::string msg, std::string sender){
    cout << "PC with IP[" << ipAddress << "] received message from " 
         << sender << ": " << msg << endl;
}

void iOSDevice::notify(std::string msg, std::string sender){
    cout << "ios device[" << apnsToken << "] received message from " 
         << sender << ": " << msg << endl;
}

void AndroidDevice::notify(std::string msg, std::string sender){
    cout << "android device[" << fcmToken << "] received message from " 
         << sender << ": " << msg << endl;
}
// TODO: 完成其餘成員函數