#ifndef _Screen_H
#define _Screen_H

#include <string>
#include <iostream>
#include <vector>

class Screen;

class Window_mgr
{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24, 80)};
};

class Screen
{
    friend void Window_mgr::clear(ScreenIndex);
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos height, pos width, char c = ' ') : height_(height), width_(width), contents_(height * width, c) {}
    char get() const { return contents_[cursor_]; }
    inline char get(pos height, pos width) const;
    Screen& set(char);
    Screen& set(pos, pos, char);
    Screen& move(pos rows, pos cols);
    Screen& display(std::ostream &os) { do_display(os); return *this; }
    const Screen& display(std::ostream &os) const { do_display(os); return *this; }
private:
    void do_display(std::ostream &os) const { os << contents_; }
    pos cursor_ = 0;
    pos height_ = 0, width_ = 0;
    std::string contents_; 
};

inline Screen& Screen::move(pos rows, pos cols)
{
    cursor_ = rows * width_ + cols;
    return *this;
}

char Screen::get(pos height, pos width) const
{
    return contents_[height * width_ + width];
}

inline Screen& Screen::set(char ch)
{
    contents_[cursor_] = ch;
    return *this;
}

inline Screen& Screen::set(pos height, pos width, char ch)
{
    contents_[height * width_ + width] = ch;
    return *this;
}

#endif