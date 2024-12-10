#ifndef devices_h
#define devices_h
 
#include <iostream>

using namespace std;

class Observer {
    public:
        virtual void notify(string msg, string sender) =0;
    };
 

class PCDevice : public Observer{
    private:
        string ipAddress;
    
    public:
        PCDevice(string ipAddress);
        void notify(string msg, string sender);
};
 
class iOSDevice : public Observer{
    private:
        string apnsToken;
    
    public:
        iOSDevice(string apnsToken);
        void notify(string msg, string sender);
};
 
class AndroidDevice : public Observer{
    private:
        string fcmToken;
    
    public:
        AndroidDevice(string fcmToken);
        void notify(string msg, string sender);
};
 
#endif