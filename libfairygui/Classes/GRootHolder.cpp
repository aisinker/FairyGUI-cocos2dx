#include "GRootHolder.h"

USING_NS_CC;
NS_FGUI_BEGIN

GRootHolder* GRootHolder::_inst = nullptr;

GRootHolder* GRootHolder::create()
{
    GRootHolder* pRet = new (std::nothrow) GRootHolder();
    if (pRet)
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = nullptr;
        return nullptr;
    }
}

void GRootHolder::setGlobalInstance(GRootHolder* rootHolder) {
    if (_inst != nullptr) {
        CC_SAFE_RELEASE_NULL(_inst);
    }
    _inst = rootHolder;
    _inst->retain();
}

GRootHolder* GRootHolder::getGlobalInstance() {
    if (_inst == nullptr) {
        GRootHolder::create()->asGlobalInstance();
    }
    return _inst;
}

GRootHolder::GRootHolder():gRoot(nullptr)
{
}

GRootHolder::~GRootHolder()
{
    if (gRoot != nullptr) {
        CC_SAFE_RELEASE_NULL(gRoot);
    }
}

void GRootHolder::asGlobalInstance() {
    GRootHolder::setGlobalInstance(this);
}

void GRootHolder::setGRoot(GRoot* gRoot)
{
    if (this->gRoot != nullptr) {
        CC_SAFE_RELEASE_NULL(this->gRoot);
    }

    if (gRoot != nullptr) {
        gRoot->retain();
        this->gRoot = gRoot;
    }
}

GRoot* GRootHolder::getGRoot() {
    if (gRoot == nullptr) {
        Scene* scene = CCDirector::getInstance()->getRunningScene();
        GRoot* gRoot = GRoot::create(scene);
        setGRoot(gRoot);
    }
    return gRoot;
}

NS_FGUI_END