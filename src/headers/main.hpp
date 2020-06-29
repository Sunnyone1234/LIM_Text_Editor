#ifndef MAIN_HPP
#define MAIN_HPP

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

class App : public wxApp
{
public:
    virtual bool OnInit() wxOVERRIDE;
};

#endif // !MAIN_HPP
