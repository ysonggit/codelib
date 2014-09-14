#include <memory>
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Mail{
    string sender;
    string content;
    string receiver;
};

struct MailBox{
    int date;
    // key is integer, representing user id
    // value is Mail type
    map<int, Mail> mails;
};


struct Member{
    string name;
    int uid; // user id
    shared_ptr<MailBox> ptr_mbox;
};

// A Group owns serveral members and a post box
// every member can drop his/her mail to the Mail box
class Group{
    // key is user id
    // value is Employee type
    map<int, Member> users;
    
    MailBox mbox;
};
