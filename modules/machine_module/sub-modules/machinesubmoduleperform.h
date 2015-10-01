#ifndef MACHINESUBMODULEPERFORM_H
#define MACHINESUBMODULEPERFORM_H

// Machine handle codes
#include "../machinemoduledirectory.h"

// Required
#include "../../../core/datatypes.h"
#include "../../framework/modulebase.h"

namespace hdtoolbox
{

class MachineSubModulePerform : public ModuleBase
{
public:
    MachineSubModulePerform();

    // Required
    HDTBReturnItem processRequest(std::vector<std::string>);

private:

    HDTBReturnItem cleanup();
    HDTBReturnItem copy(std::string, std::string);
    HDTBReturnItem winupdate();
    HDTBReturnItem scrub();
    HDTBReturnItem fixJava();

};

}

#endif // MACHINESUBMODULEPERFORM_H
