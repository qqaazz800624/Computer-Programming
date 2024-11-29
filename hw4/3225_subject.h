#ifndef subject_h
#define subject_h
#include "3225_observer.h"
#include <vector>
 
/**
 * 通知中心，負責管理訂閱者，以及當notify方法被觸發時，負責通知所有相關訂閱者。
 */
class Subject {
private:
    /**
     * 觀察者集合
     */
    std::vector<Observer *> observers;
    /**
     * 通知中心名稱
     */
    std::string name;
 
public:
    /**
     * 建構式
     *
     * @param  {std::string} name : 通知中心名稱
     */
    Subject(std::string name);
    /**
     * 增加觀察者
     * @param  {Observer*} observer : 觀察者
     */
    void addObserver(Observer *observer);
    /**
     * 對所有觀察者發出通知
     * 令每位觀察者發出(notify)通知訊息
     * @param  {std::string} message : 訊息
     */
    void notifyObservers(std::string message);
};
 
#endif