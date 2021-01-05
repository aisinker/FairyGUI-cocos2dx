#ifndef __GROOTHOLDER_H__
#define __GROOTHOLDER_H__

#include "FairyGUI.h"
#include "cocos2d.h"

NS_FGUI_BEGIN

class GRootHolder : public cocos2d::Ref
{
public:
    static GRootHolder* create();
    static void setGlobalInstance(GRootHolder* rootHolder);
    static GRootHolder* getGlobalInstance();

    GRootHolder();
    virtual ~GRootHolder();

    void asGlobalInstance();
    void setGRoot(GRoot* gRoot);
    GRoot* getGRoot();
private:
    GRoot* gRoot;

    static GRootHolder* _inst;
};

NS_FGUI_END

#endif