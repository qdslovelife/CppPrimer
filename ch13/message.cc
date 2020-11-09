#include "message.h"

Message::Message(const Message &mes)
    : contents_(mes.contents_), folders_(mes.folders_)
{
    add_to_folders(*this);
}

Message& Message::operator=(const Message &mes)
{
    remove_from_folders();
    contents_ = mes.contents_;
    folders_ = mes.folders_;
    add_to_folders(*this);
    return *this;
}

Message::Message(Message &&mes)
    : contents_(std::move(mes.contents_))
{
    move_folders(&mes);
}

Message& Message::operator=(Message &&mes)
{
    if(this != &mes)
    {
        remove_from_folders();
        contents_ = std::move(mes.contents_);
        move_folders(&mes);
    }
    return *this;
}

Message::~Message()
{
    remove_from_folders();
}

void Message::save(Folder &folder)
{
    folders_.insert(&folder);
    folder.addMsg(this);
}

void Message::remove(Folder &folder)
{
    folders_.erase(&folder);
    folder.remMsg(this);
}

void Message::add_to_folders(const Message &mes)
{
    for(auto f : mes.folders_)
    {
        f->addMsg(this);
    }
}

void Message::remove_from_folders()
{
    for(auto f : folders_)
    {
        f->remMsg(this);
    }
}

void Message::move_folders(Message *mes)
{
    folders_ = std::move(mes->folders_);
    for(auto f : folders_)
    {
        f->remMsg(mes);
        f->addMsg(this);
    }
    mes->folders_.clear();
}

Folder::Folder(const Folder &folder)
    : messages_(folder.messages_)
{
    add_to_messages(*this);
}

Folder& Folder::operator=(const Folder &folder)
{
    remove_from_messages();
    messages_ = folder.messages_;
    add_to_messages(*this);
    return *this;
}

Folder::~Folder()
{
    remove_from_messages();
}

void Folder::add_to_messages(const Folder &folder)
{
    for(auto m : folder.messages_)
    {
        m->addFolder(this);
    }
}

void Folder::remove_from_messages()
{
    for(auto m : messages_)
    {
        m->remFolder(this);
    }
}

void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    for(auto f : lhs.folders_)
    {
        f->remMsg(&lhs);
    }
    for(auto f : rhs.folders_)
    {
        f->remMsg(&rhs);
    }
    swap(lhs.folders_, rhs.folders_);
    swap(lhs.contents_, rhs.contents_);
    for(auto f : lhs.folders_)
    {
        f->addMsg(&lhs);
    }
    for(auto f : rhs.folders_)
    {
        f->addMsg(&rhs);
    }
}

void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    for(auto m : lhs.messages_)
    {
        m->remFolder(&lhs);
    }
    for(auto m : rhs.messages_)
    {
        m->remFolder(&rhs);
    }
    swap(lhs.messages_, rhs.messages_);
    for(auto m : lhs.messages_)
    {
        m->addFolder(&lhs);
    }
    for(auto m : rhs.messages_)
    {
        m->addFolder(&rhs);
    }
}