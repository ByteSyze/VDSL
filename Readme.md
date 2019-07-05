# VDSL

**VDSL** is a drag-and-drop nodal programming tool. It created as a final project for a programming class and is currently in an embryonic stage at best. See the *Considerations* section for information on planned/suggested future improvements.

## Getting Started

VDSL is written and tested in Qt Creator 4.7.0 (using Qt 5.11.1). In order to run VSDL, you will need to compile these sources with a compatible version of Qt. All of the original Qt project files are included, so you may open this project in Qt Creator and let it handle building the project.

## How to Use VDSL

### Modules and Ports
VDSL is mainly comprised of **modules** and **ports**. Modules are the "black boxes" that process data within VSDL. Modules communicate with each other through inputs and outputs known as ports. Each module has at least one input or output port, depending on its purpose.

### Module Tree
The Module Tree is located on the left side of the application. It is a hierarchy of available modules that is organized by functionality.

### Main Viewport
The black pane comprising most of the graphical interface is the Main View Port. Modules can be dragged from the Module Tree into this viewport in order to design VDSL programs.

There are several features and operations currently supported by the viewport. To move a module in the viewport, right-click anywhere within its boundary and drag it to the desired location. Alternatively, multiple modules can be selected at the same time by left-clicking within the viewport and dragging over the desired modules (selected modules are indicated by a bright-green border.) They can then be moved in tandem by right-clicking anywhere within the viewport.

Modules in the viewport can be connected together by left-clicking on two yellow-orange port connectors. One of the ports must be an input and the other must be an output, and they must have compatible data types. In order to disconnect an existing port connection, simply click on the connected ports again. When a port connector is clicked, a pending port connection will be shown that follows the cursor. To cancel a pending connection, right click anywhere within the viewport.

To delete an unwanted module, select it and press the "delete" key on your keyboard.
### Main Controls
In order to run a VDSL design, you just need to press the **Start** button in the top left corner. Similarly, the **Stop** button will end the program loop. The slider underneath the start and stop buttons controls the "step speed" of the program loop. Dragging this slider to the left will slow the program execution.

## Considerations

- Modules currently inherit Qt's `QWidget`. The main viewport inherits `QFrame`, and modules are displayed in the viewport by using Qt's parent/child hierarchy. This poses several issues with designing VDSL's workflow. Ideally, the viewport and modules should be changed to inherit from `QGraphicsScene` and `QGraphicsObject`, respectively.
- There is no undo/redo operation
- There is no save or load mechanism
- There is no graphical indication for why certain ports will not connect to eachother (e.g. incompatible types)
____________________________________
Copyright (C) 2018-2019 Tyler Hackett

VDSL is licensed under the GNU General Public License. Read the LICENSE file for more information. 

VDSL was developed using Qt. https://www.qt.io/
