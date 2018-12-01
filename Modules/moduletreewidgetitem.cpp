#include "moduletreewidgetitem.h"

ModuleTreeWidgetItem::ModuleTreeWidgetItem() : QTreeWidgetItem() {}

ModuleTreeWidgetItem::~ModuleTreeWidgetItem()
{
    delete prototype;
}

void ModuleTreeWidgetItem::setModulePrototype(Module *prototype)
{
    this->prototype = prototype;
}

Module *ModuleTreeWidgetItem::cloneModulePrototype()
{
    return this->prototype->clone();
}
