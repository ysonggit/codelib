#include <memory>
#include <iostream>
#include <map>
#include <string>
#include <ostream>
#include <sstream>

using namespace std;

struct Mail{
    Mail(){ }
    Mail(string s, string c, string r) {
	sender = s;
	content = c;
	receiver = r;
    }
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
    Member(int i, string s, shared_ptr<MailBox>& p);
    Member(int, string, MailBox &);
    int uid;
    string name;
    weak_ptr<MailBox> wp_mbox;
    Mail createMail(string, string);
    void dropMail(Mail);
    void dropMail(Mail, MailBox&);
    void openMail(int);
    void openMail(int, MailBox &);
    MailBox *ptr;
};

Member::Member(int i, string s, shared_ptr<MailBox>& p){
    uid = i;
    name = s;
    wp_mbox = p; // p owns the memory
    
}

Member::Member(int i, string s, MailBox & mb){
    uid = i;
    name = s;
    ptr  = &mb;
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

void Member::dropMail(Mail m){
    ///(*ptr).mails[uid] = m; // works
    shared_ptr<MailBox> ptr_2 = wp_mbox.lock(); // now p and ptr_2 own the memory
    if(ptr_2) {// ptr_2 is initialized from a weak pointer, so make sure to check memory exists or not
	// not working using this way
	ptr_2->mails.insert(map<int, Mail>::value_type(uid, m));
    }
}

// open user X 's mail in the mailbox
void Member::openMail(int x){
    Mail m = (*ptr).mails[x]; //works
    //Mail m = (*wp_mbox).mails[x];
    cout<<"User "<<name<<" opens mail from "<<m.sender<<endl;
    cout<<m<<endl;
}

void Member::openMail(int x, MailBox & mb){
    Mail m = mb.mails[x];
    cout<<"User "<<name<<" opens mail from "<<m.sender<<endl;
    cout<<m<<endl;
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
	    cout<<"Mail ("<< it->first<<")"<<endl;
	    cout<<it->second<<endl;
	    cout<<"======================================="<<endl;
	}
    }
    shared_ptr<MailBox> p_mbox;
};


Group::Group(int n) : number_users(n){
    mbox.date = 1;
    mbox.mails[0] = Mail(string("A"), string("I am A"), string("ALL"));
    p_mbox = make_shared<MailBox>(mbox);
    // fail to write to mbox using p_mbox->mails[0] = ....
    for(int i=0; i<n; i++){
	// convert int ascii to char
	char c = i+65;
	// convert char to string
	stringstream ss;
	ss<<c;
	string uname;
	ss>>uname;
	Member m(i, uname, p_mbox);
	//Member m(i, uname, mbox); // works
	users.insert(map<int, Member>::value_type(i, m));
    }
}

int main(){
    int N = 10;
    Group A(N);
    Member user1 = A.users.find(1)->second;
    Mail m1 = user1.createMail("Mike", "hello");
    user1.dropMail(m1);
    ///user1.dropMail(m1, A.mbox);
    //A.showMails();
    ///Member user5 = A.users.find(5)->second;
    //user5.wp_mbox = make_shared<MailBox>(A.mbox);
    /// user5.openMail(1);
    //user5.openMail(1, A.mbox); 
    Member user6 = A.users.find(6)->second;
    Mail m6 = user6.createMail("Jane", "Love you");
    user6.dropMail(m6);
    ///user5.openMail(6);
    A.showMails();
    return 0;
}
