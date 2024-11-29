#ifndef devices_h
#define devices_h
 
#include <iostream>
/**
 * 觀察者抽象類別
 */
class Observer {
public:
    /**
     * 抽象函式：通知事件的處理行為
     * @param  {std::string} msg    : 通知訊息
     * @param  {std::string} sender : 通知中心名稱
     */
    virtual void notify(std::string msg, std::string sender) =0;
};
 
/**
 * 觀察者:PC裝置
 */
class PCDevice : public Observer{
private:
    /**
     * PC的IP位址
     */
    std::string ipAddress;
 
public:
    //設定 ipAddress
    PCDevice(std::string ipAddress);
    //印出 通知訊息 PC with IP...
    void notify(std::string msg, std::string sender);
};
 
 
/**
 * 觀察者:iOS裝置
 */
class iOSDevice : public Observer{
private:
    /**
     * iOS的裝置代碼
     */
    std::string apnsToken;
 
public:
    //設定 apnsToken
    iOSDevice(std::string apnsToken);
    //印出 通知訊息  ios device...
    void notify(std::string msg, std::string sender);
};
 
 
/**
 * 觀察者:Android裝置
 */
class AndroidDevice : public Observer{
private:
    /**
     * Android的裝置代碼
     */
    std::string fcmToken;
 
public:
    //設定 fcmToken
    AndroidDevice(std::string fcmToken);
    //印出 通知訊息 android device...
    void notify(std::string msg, std::string sender);
};
 
#endif