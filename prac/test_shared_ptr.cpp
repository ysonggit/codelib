#include <memory>
#include <iostream>
#include <map>
#include <string>
#include <ostream>
#include <sstream>

using namespace std;

struct Mail{
    //Mail(string s, string c, string r) : sender(s), content(c), receiver(r){ }
    string sender;
    string content;
    string receiver;
};

ostream & operator<<(ostream & lhs, const Mail & m){
    lhs << " Receiver : " << m.receiver << endl;
    lhs << " ---------- \n " << m.content << endl;
    lhs << " -----------\n Sender : " << m.sender <<endl;
    return lhs;
}


struct MailBox{
    int date;
    // key is integer, representing user id
    // value is Mail type
    map<int, Mail> mails;
};


class Member{
public:
    Member(int i, string s, shared_ptr<MailBox> p);
    int uid;
    string name;
    shared_ptr<MailBox> ptr_mbox;
    Mail createMail(string, string);
    void dropMail(Mail, MailBox&);
};

Member::Member(int i, string s, shared_ptr<MailBox> p){
    uid = i;
    name = s;
    ptr_mbox = p;
}

Mail Member::createMail(string target, string info){
    Mail m;
    m.sender = name;
    m.receiver = target;
    m.content = info;
    return m;
}

void Member::dropMail(Mail m, MailBox & mb){
    mb.mails[uid] = m;
}

// A Group owns serveral members and a post box
// every member can drop his/her mail to the Mail box
class Group{
public:
    // key is user id
    // value is Employee type
    Group(int );
    map<int, Member> users;
    int number_users;
    MailBox mbox;
    void showMails(){
	for(auto it = mbox.mails.begin(); it != mbox.mails.end(); ++it){
	    cout<<it->first<<endl;
	    cout<<it->second<<endl;
	    cout<<"======================================="<<endl;
	}
    }
};


Group::Group(int n) : number_users(n){
    mbox.date = 1;
    shared_ptr<MailBox> _ptr_mbox = make_shared<MailBox>(mbox);
    for(int i=0; i<n; i++){
	// convert int ascii to char
	char c = i+65;
	// convert char to string
	stringstream ss;
	ss<<c;
	string uname;
	ss>>uname;
	Member m(i, uname, _ptr_mbox);
	users.insert(map<int, Member>::value_type(i, m));
    }
}

int main(){
    int N = 10;
    Group A(N);
    Member user1 = A.users.find(1)->second;
    Mail m1 = user1.createMail("Mike", "hello");
    user1.dropMail(m1, A.mbox);
    A.showMails();
    return 0;
}
