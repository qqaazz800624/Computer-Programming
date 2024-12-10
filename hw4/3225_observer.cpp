#include "3225_observer.h"
 
using namespace std;
 
PCDevice::PCDevice(string ipAddress){
    this->ipAddress = ipAddress;
}
 
iOSDevice::iOSDevice(string apnsToken){
    this->apnsToken = apnsToken;
}
 
AndroidDevice::AndroidDevice(string fcmToken){
    this->fcmToken = fcmToken;
}

void PCDevice::notify(string msg, string sender){
    cout << "PC with IP[" << ipAddress << "] received message from " 
         << sender << ": " << msg << endl;
}

void iOSDevice::notify(string msg, string sender){
    cout << "ios device[" << apnsToken << "] received message from " 
         << sender << ": " << msg << endl;
}

void AndroidDevice::notify(string msg, string sender){
    cout << "android device[" << fcmToken << "] received message from " 
         << sender << ": " << msg << endl;
}
// TODO: 完成其餘成員函數