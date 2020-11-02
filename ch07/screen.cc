#include "screen.h"

void Window_mgr::clear(ScreenIndex si)
{
    Screen &s = screens[si];
    s.contents_ = std::string(s.height_ * s.width_, ' ');
}