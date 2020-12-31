#ifndef __DRAGDROPMANAGER_H__
#define __DRAGDROPMANAGER_H__

#include "FairyGUIMacros.h"
#include "cocos2d.h"
#include "GLoader.h"
#include "GRootHolder.h"

NS_FGUI_BEGIN

class GRootHolder;

class DragDropManager
{
public:
    DragDropManager();
    ~DragDropManager();

    static DragDropManager* getInstance();

    GLoader* getAgent() const { return _agent; }
    bool isDragging() const { return _agent->getParent() != nullptr; }
    void startDrag(const std::string& icon, const cocos2d::Value& sourceData = cocos2d::Value::Null, int touchPointID = -1);
    void cancel();

private:
    void onDragEnd(EventContext* context);

    static DragDropManager* _inst;

    GLoader* _agent;
    cocos2d::Value _sourceData;
    GRootHolder* _gRootHolder;
};

NS_FGUI_END

#endif
