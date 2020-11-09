#ifndef _Message_H
#define _Message_H

#include <iostream>
#include <string>
#include <set>

class Folder;

class Message
{
    friend void swap(Message &lhs, Message &rhs);
    friend void swap(Folder &lhs, Folder &rhs);
    friend class Folder;
public:
    explicit Message(const std::string contents = "")
        : contents_(contents) 
    {}
    Message(const Message &mes);
    Message& operator=(const Message &mes);
    Message(Message &&mes);
    Message& operator=(Message &&mes);
    ~Message();

    void save(Folder &folder);
    void remove(Folder &folder);

private:
    std::string contents_;
    std::set<Folder*> folders_;

    void add_to_folders(const Message &mes);
    void remove_from_folders();

    void addFolder(Folder *folder) { folders_.insert(folder); }
    void remFolder(Folder *folder) { folders_.erase(folder); }

    void move_folders(Message *mes);
};

class Folder
{
    friend void swap(Folder &lhs, Folder &rhs);
    friend void swap(Message &lhs, Message &rhs);
    friend class Message;
public:
    Folder() {}
    Folder(const Folder &folder);
    Folder& operator=(const Folder &folder);
    ~Folder();

private:
    std::set<Message*> messages_;

    void add_to_messages(const Folder &folder);
    void remove_from_messages();

    void addMsg(Message *mes) { messages_.insert(mes); }
    void remMsg(Message *mes) { messages_.erase(mes); }
};

void swap(Message &lhs, Message &rhs);
void swap(Folder &lhs, Folder &rhs);

#endif