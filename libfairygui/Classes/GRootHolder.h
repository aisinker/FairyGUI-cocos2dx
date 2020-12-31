#ifndef __GROOTHOLDER_H__
#define __GROOTHOLDER_H__

#include "FairyGUI.h"
#include "cocos2d.h"

NS_FGUI_BEGIN

class GRootHolder : public cocos2d::Ref
{
public:
    static GRootHolder* create();
    static void setCurrentInstance(GRootHolder* rootHolder);
    static GRootHolder* getCurrentInstance();

    GRootHolder();
    virtual ~GRootHolder();

    void asCurrentInstance();
    void setGRoot(GRoot* gRoot);
    GRoot* getGRoot();
private:
    GRoot* gRoot;

    static GRootHolder* _inst;
};

NS_FGUI_END

#endif