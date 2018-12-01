#ifndef MODULETREEWIDGETITEM_H
#define MODULETREEWIDGETITEM_H

#include <QTreeWidgetItem>
#include <Modules/module.h>

class ModuleTreeWidgetItem : public QTreeWidgetItem
{
public:
    ModuleTreeWidgetItem();
    ~ModuleTreeWidgetItem();

    void setModulePrototype(Module *);
    Module *cloneModulePrototype();

private:

    Module *prototype;
};

#endif // MODULETREEWIDGETITEM_H
